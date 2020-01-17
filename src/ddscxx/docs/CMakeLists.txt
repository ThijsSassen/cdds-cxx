#
# Copyright(c) 2006 to 2018 ADLINK Technology Limited and others
#
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License v. 2.0 which is available at
# http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
# v. 1.0 which is available at
# http://www.eclipse.org/org/documents/edl-v10.php.
#
# SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
#

# find the required packages

if (${CMAKE_VERSION} VERSION_LESS "3.12")
  find_package(PythonInterp)
else()
  find_package(Python COMPONENTS Interpreter)
endif()
find_package(Doxygen REQUIRED)

# Execute predoxygen Python script

add_custom_target(predoxygen
  COMMAND ${PYTHON_EXECUTABLE}
    "${CMAKE_CURRENT_SOURCE_DIR}/predoxygen.py"
       -i "${CMAKE_CURRENT_SOURCE_DIR}/../include"
       -o "${CMAKE_CURRENT_BINARY_DIR}/predoxygen")


# Execute Doxygen

set(doxy_conf_project "Vortex Lite ISO C++ API Reference Guide")
set(doxy_conf_proj_logo "${PROJECT_SOURCE_DIR}/src/docs/images/PROJECT_LOGO_Lite.png")
set(doxy_conf_image_path "${PROJECT_SOURCE_DIR}/src/docs/dcps/img/")
set(doxy_conf_outputdir "ddscxx_api")
set(doxy_conf_input "${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/predoxygen/include")
set(doxy_conf_exclude "${PROJECT_SOURCE_DIR}/src/ddscxx/docs/predoxygen.py")
set(doxy_conf_exclude_patterns "*/include/dds/*/detail/* */include/org/eclipse/* */include/dds/core/xtypes/* */dds/core/xtypes/*")
set(doxy_conf_strip_from_path "${CMAKE_CURRENT_BINARY_DIR}/predoxygen/include")
configure_file(Doxyfile.in Doxyfile @ONLY)

add_custom_target(ddscxx_doxygen ALL
  ${DOXYGEN_EXECUTABLE} Doxyfile
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Running Doxygen for ISOCPP API docs generation"
  DEPENDS predoxygen
  VERBATIM
)

# Create tar.gz
add_custom_command(TARGET ddscxx_doxygen
    POST_BUILD
    WORKING_DIRECTORY "${doxy_conf_outputdir}"
    COMMAND ${CMAKE_COMMAND} -E tar "zcf" "${CMAKE_PROJECT_NAME}_ISOCPP_HTML.tar.gz" "html")

# Remove generated files when cleaning the build tree
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
  predoxygen
  ${doxy_conf_outputdir}
  ${CMAKE_PROJECT_NAME}_ISOCPP_HTML.tar.gz)
  
add_custom_command(TARGET ddscxx_doxygen
    POST_BUILD
    WORKING_DIRECTORY "${doxy_conf_outputdir}"
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_BINARY_DIR}/doc/api/isocpp
    COMMAND ${CMAKE_COMMAND} -E copy_directory "html" ${PROJECT_BINARY_DIR}/doc/api/isocpp)  

install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${doxy_conf_outputdir}/html/"
    DESTINATION ${CMAKE_INSTALL_DDSCXX_DOCDIR}
    COMPONENT dev)


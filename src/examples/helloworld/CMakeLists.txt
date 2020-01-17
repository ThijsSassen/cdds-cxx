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
cmake_minimum_required(VERSION 3.5)

set(CMAKE_INSTALL_HELLOWORLD_DIR "${CMAKE_INSTALL_DDSCXX_EXAMPLESDIR}/helloworld")

if (NOT TARGET ${CMAKE_PROJECT_NAME}::ddscxx)
    # Find the ${CMAKE_PROJECT_NAME} package. If it is not in a default location, try
    # finding it relative to the example where it most likely resides.
    find_package(${CMAKE_PROJECT_NAME} REQUIRED PATHS "${CMAKE_SOURCE_DIR}/../../../")
endif()

# This is a convenience function, provided by the ${CMAKE_PROJECT_NAME} package,
# that will supply a library target related the the given idl file.
# In short, it takes the idl file, generates the source files with
# the proper data types and compiles them into a library.
idl_ddscxx_generate(ddscxxHelloWorldData_lib "HelloWorldData.idl")

# Both executables have only one related source file.
add_executable(ddscxxHelloworldPublisher publisher.cpp)
add_executable(ddscxxHelloworldSubscriber subscriber.cpp)

# Both executables need to be linked to the idl data type library and
# the ddsc API library.
target_link_libraries(ddscxxHelloworldPublisher ddscxxHelloWorldData_lib ${CMAKE_PROJECT_NAME}::ddscxx)
target_link_libraries(ddscxxHelloworldSubscriber ddscxxHelloWorldData_lib ${CMAKE_PROJECT_NAME}::ddscxx)

set_property(TARGET ddscxxHelloworldPublisher PROPERTY CXX_STANDARD 11)
set_property(TARGET ddscxxHelloworldSubscriber PROPERTY CXX_STANDARD 11)

# The examples have a different CMakeLists.txt for building in source and
# install environments. This is because it includes the (CMake) project name.
# The CMakelists.export will be used for the install environments.
configure_file(CMakeLists.export.in CMakeLists.export @ONLY)

install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/CMakeLists.export"
  DESTINATION "${CMAKE_INSTALL_HELLOWORLD_DIR}"
  COMPONENT dev
  RENAME "CMakeLists.txt")

install(
  FILES "${CMAKE_CURRENT_SOURCE_DIR}/publisher.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/subscriber.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/HelloWorldData.idl"
  DESTINATION "${CMAKE_INSTALL_HELLOWORLD_DIR}"
  COMPONENT dev)

# Workaround until docs generation works properly.
install(
  FILES "${CMAKE_CURRENT_SOURCE_DIR}/readme.rst"
  DESTINATION "${CMAKE_INSTALL_HELLOWORLD_DIR}"
  COMPONENT dev)


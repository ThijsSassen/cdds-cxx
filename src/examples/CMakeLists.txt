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
add_subdirectory(helloworld)

if (BUILD_DOCS)
  find_package(Sphinx REQUIRED)
  sphinx_add_docs(
    examples_docs
    BUILDER html
    SOURCE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
  install(
    DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/examples_docs/"
    DESTINATION "${CMAKE_INSTALL_EXAMPLESDIR}"
    COMPONENT dev
    PATTERN "_sources" EXCLUDE)
endif()


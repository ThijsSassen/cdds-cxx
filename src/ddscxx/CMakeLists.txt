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
include(GenerateExportHeader)

set(source_wrpr_dir "src/dds")
set(source_dlgt_dir "src/org/eclipse/cyclonedds")

set(sources
    "${source_wrpr_dir}/core/Duration.cpp"
    "${source_wrpr_dir}/core/Exception.cpp"
    "${source_wrpr_dir}/core/Reference.cpp"
    "${source_wrpr_dir}/core/Time.cpp"
    "${source_wrpr_dir}/core/policy/CorePolicy.cpp"
    "${source_wrpr_dir}/core/status/State.cpp"
    "${source_wrpr_dir}/domain/discovery.cpp"
    "${source_wrpr_dir}/domain/find.cpp"
    "${source_wrpr_dir}/pub/pubdiscovery.cpp"
    "${source_wrpr_dir}/sub/subdiscovery.cpp"
    "${source_wrpr_dir}/sub/subfind.cpp"
    "${source_wrpr_dir}/sub/status/DataState.cpp"
    "${source_dlgt_dir}/core/Mutex.cpp"
    "${source_dlgt_dir}/core/ObjectDelegate.cpp"
    "${source_dlgt_dir}/core/DDScObjectDelegate.cpp"
    "${source_dlgt_dir}/core/ObjectSet.cpp"
    "${source_dlgt_dir}/core/EntityDelegate.cpp"
    "${source_dlgt_dir}/core/ReportUtils.cpp"
    "${source_dlgt_dir}/core/ListenerDispatcher.cpp"
    "${source_dlgt_dir}/core/InstanceHandleDelegate.cpp"
    "${source_dlgt_dir}/core/EntitySet.cpp"
    "${source_dlgt_dir}/core/MiscUtils.cpp"
    "${source_dlgt_dir}/core/cond/ConditionDelegate.cpp"
    "${source_dlgt_dir}/core/cond/GuardConditionDelegate.cpp"
    "${source_dlgt_dir}/core/cond/StatusConditionDelegate.cpp"
    "${source_dlgt_dir}/core/cond/WaitSetDelegate.cpp"
    "${source_dlgt_dir}/core/policy/PolicyDelegate.cpp"
    "${source_dlgt_dir}/domain/Domain.cpp"
    "${source_dlgt_dir}/domain/DomainWrap.cpp"
    "${source_dlgt_dir}/domain/DomainParticipantDelegate.cpp"
    "${source_dlgt_dir}/domain/DomainParticipantRegistry.cpp"
    "${source_dlgt_dir}/domain/qos/DomainParticipantQosDelegate.cpp"
    "${source_dlgt_dir}/pub/AnyDataWriterDelegate.cpp"
    "${source_dlgt_dir}/pub/PublisherDelegate.cpp"
    "${source_dlgt_dir}/pub/qos/DataWriterQosDelegate.cpp"
    "${source_dlgt_dir}/pub/qos/PublisherQosDelegate.cpp"
    "${source_dlgt_dir}/sub/qos/DataReaderQosDelegate.cpp"
    "${source_dlgt_dir}/sub/AnyDataReaderDelegate.cpp"
    "${source_dlgt_dir}/sub/SubscriberDelegate.cpp"
    "${source_dlgt_dir}/sub/BuiltinSubscriberDelegate.cpp"
    "${source_dlgt_dir}/sub/QueryDelegate.cpp"
    "${source_dlgt_dir}/sub/cond/ReadConditionDelegate.cpp"
    "${source_dlgt_dir}/sub/cond/QueryConditionDelegate.cpp"
    "${source_dlgt_dir}/sub/qos/SubscriberQosDelegate.cpp"
    "${source_dlgt_dir}/topic/find.cpp"
    "${source_dlgt_dir}/topic/AnyTopicDelegate.cpp"
    "${source_dlgt_dir}/topic/FilterDelegate.cpp"
    "${source_dlgt_dir}/topic/TopicDescriptionDelegate.cpp"
    "${source_dlgt_dir}/topic/qos/TopicQosDelegate.cpp")

if (BUILD_SHARED_LIBS OR NOT DEFINED BUILD_SHARED_LIBS)
  add_library(ddscxx SHARED ${sources})
else()
  add_library(ddscxx ${sources})
endif()

# SOVERSION should increase on incompatible ABI change
set_target_properties(ddscxx PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_VERSION_MAJOR})

# Create a pseudo-target that other targets (i.e. examples, tests) can depend
# on and can also be provided as import-target by a package-file when building
# those targets outside the regular Cyclone build-tree (i.e. the installed tree)
add_library(${CMAKE_PROJECT_NAME}::ddscxx ALIAS ddscxx)

target_include_directories(
  ddscxx
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/ddscxx>)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter")
endif(CMAKE_COMPILER_IS_GNUCXX)
set_property(TARGET ddscxx PROPERTY CXX_STANDARD 11)
target_link_libraries(ddscxx PUBLIC CycloneDDS::ddsc)

generate_export_header(
  ddscxx
  BASE_NAME
    OMG_DDS_API_DETAIL
  EXPORT_MACRO_NAME
    OMG_DDS_API_DETAIL
  EXPORT_FILE_NAME
  "${CMAKE_CURRENT_BINARY_DIR}/include/dds/core/detail/export.hpp")

install(
  TARGETS ddscxx
  EXPORT "${CMAKE_PROJECT_NAME}"
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}" COMPONENT lib
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}" COMPONENT lib
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}" COMPONENT lib
)

install(
  DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/include/dds"
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/ddscxx"
  COMPONENT dev)

install(
  DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/include/org"
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/ddscxx"
  COMPONENT dev)

install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/include/dds/core/detail/export.hpp"
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/ddscxx/dds/core/detail/"
  COMPONENT dev)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()

if(USE_DOCS)
  add_subdirectory(docs)
endif()

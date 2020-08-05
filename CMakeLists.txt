#
# Copyright(c) 2006 to 2018 ADLINK Technology Limited and others
#
cmake_minimum_required(VERSION 3.7)

# Set module path before defining project so platform files will work.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/src/cmake/modules)
set(CMAKE_PROJECT_NAME_FULL "CycloneDDS CXX API")
set(PROJECT_NAME "CycloneDDS_CXX_API")
set(PROJECT_VERSION 0.5.0)
set(PROJECT_VERSION_UUID "f91c0f5b-7b42-41d9-8cea-103e25ab753a")
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})


# Set some convenience variants of the project-name
string(REPLACE " " "-" CMAKE_PROJECT_NAME_DASHED "${CMAKE_PROJECT_NAME_FULL}")
string(TOUPPER ${CMAKE_PROJECT_NAME} CMAKE_PROJECT_NAME_CAPS)
string(TOLOWER ${CMAKE_PROJECT_NAME} CMAKE_PROJECT_NAME_SMALL)

set(CMAKE_C_STANDARD 99)

if(${CMAKE_C_COMPILER_ID} STREQUAL "SunPro")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -xc99 -D__restrict=restrict -D__deprecated__=")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -m64")
endif()

# Conan
if(EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake" AND NOT CONAN_DEPENDENCIES)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  if(APPLE)
    # By default Conan strips all RPATHs (see conanbuildinfo.cmake), which
    # causes tests to fail as the executables cannot find the library target.
    # By setting KEEP_RPATHS, Conan does not set CMAKE_SKIP_RPATH and the
    # resulting binaries still have the RPATH information. This is fine because
    # CMake will strip the build RPATH information in the install step.
    #
    # NOTE:
    # Conan's default approach is to use the "imports" feature, which copies
    # all the dependencies into the bin directory. Of course, this doesn't work
    # quite that well for libraries generated in this Project (see Conan
    # documentation).
    #
    # See the links below for more information.
    # https://github.com/conan-io/conan/issues/337
    # https://docs.conan.io/en/latest/howtos/manage_shared_libraries/rpaths.html
    # https://gitlab.kitware.com/cmake/community/wikis/doc/cmake/RPATH-handling
    conan_basic_setup(KEEP_RPATHS)
  else()
    conan_basic_setup()
  endif()
  conan_define_targets()
endif()

option(BUILD_STRICT "Build with strict compiler warning conditions" ON)
option(BUILD_EXAMPLES "Build example applications" ON)

if(BUILD_STRICT)
  # Set reasonably strict warning options for clang, gcc, msvc
  # Enable coloured ouput if Ninja is used for building
  if("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_C_COMPILER_ID}" STREQUAL "AppleClang")
    add_definitions(-Wall -Wextra -Wconversion -Wunused)
    if("${CMAKE_GENERATOR}" STREQUAL "Ninja")
      add_definitions(-Xclang -fcolor-diagnostics)
    endif()
  elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
    add_definitions(-Wall -Wextra -Wconversion)
    if("${CMAKE_GENERATOR}" STREQUAL "Ninja")
      add_definitions(-fdiagnostics-color=always)
    endif()
  elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
    add_definitions(/W3)
  endif()
endif()

# Make it easy to enable one of Clang's/gcc's analyzers, and default to using
# the address sanitizer for ordinary debug builds; gcc is giving some grief on
# Travis, so don't enable it for gcc by default
if(NOT USE_SANITIZER)
  if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug" AND
      NOT ("${CMAKE_GENERATOR}" STREQUAL "Xcode") AND
      ("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang"
        OR "${CMAKE_C_COMPILER_ID}" STREQUAL "AppleClang"))
    message(STATUS "Enabling address sanitizer; set USE_SANITIZER=none to prevent this")
    set(USE_SANITIZER address)
  else()
    set(USE_SANITIZER none)
  endif()
endif()
if(NOT (${USE_SANITIZER} STREQUAL "none"))
  message(STATUS "Sanitizer set to ${USE_SANITIZER} for ${CMAKE_PROJECT_NAME}")
  add_compile_options(-fno-omit-frame-pointer -fsanitize=${USE_SANITIZER})
  link_libraries(-fno-omit-frame-pointer -fsanitize=${USE_SANITIZER})
endif()


include(GNUInstallDirs)

option(BUILD_TESTING "Build the testing tree." ON)
include(CTest)

# Overrule example installation locations.
set(CMAKE_INSTALL_EXAMPLESDIR "${CMAKE_INSTALL_DATADIR}/${CMAKE_PROJECT_NAME}/examples" CACHE STRING "Root location for examples installation.")
set(CMAKE_INSTALL_DDSCXX_EXAMPLESDIR "${CMAKE_INSTALL_EXAMPLESDIR}" CACHE STRING "Location for ddscxx examples location.")

# Overrule documentation installation locations.
set(CMAKE_INSTALL_DDSCXX_DOCDIR "${CMAKE_INSTALL_DOCDIR}/api/cxx" CACHE STRING "Location for CXX documentation location.")

# Build all executables and libraries into the top-level /bin and /lib folders.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

find_package(CycloneDDS REQUIRED)
if(NOT CycloneDDS_FOUND)
  message(WARNING "Could not find Eclipse Cyclone DDS - lease provide it through CMAKE_PREFIX_PATH")
  return()
endif()

find_package(Idlpp-cxx REQUIRED)
if(NOT Idlpp-cxx_FOUND)
  message(WARNING "Could not find Idlpp-cxx - please provide it through CMAKE_PREFIX_PATH")
  return()
endif()

if(APPLE)
  set(CMAKE_INSTALL_RPATH
     "@loader_path/../${CMAKE_INSTALL_LIBDIR}"
     "${CycloneDDS_DIR}/../..")
else()
  set(CMAKE_INSTALL_RPATH
     "$ORIGIN/../${CMAKE_INSTALL_LIBDIR}"
     "${CycloneDDS_DIR}/../..")
endif()

add_subdirectory(src)

if (USE_DOCS)
  file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/doc/)
  string(TOLOWER ${CMAKE_PROJECT_NAME_DASHED} LC_PROJECT_NAME)
  add_custom_target(docs ALL DEPENDS ddscxx_doxygen
  COMMAND ${CMAKE_COMMAND} -E tar "cfv" "${PROJECT_BINARY_DIR}/${LC_PROJECT_NAME}_${PROJECT_VERSION}_docs.zip" --format=zip "${PROJECT_BINARY_DIR}/doc"
  COMMENT "Generate documentation: ${PROJECT_BINARY_DIR}/${LC_PROJECT_NAME}_${PROJECT_VERSION}_docs.zip")
endif()

if (EXISTS "${PROJECT_BINARY_DIR}/doc/" AND IS_DIRECTORY "${PROJECT_BINARY_DIR}/doc/")
install(DIRECTORY ${PROJECT_BINARY_DIR}/doc/
    DESTINATION ${CMAKE_INSTALL_DOCDIR}
    COMPONENT dev)
else()
  message(STATUS "Not installing the ${CMAKE_PROJECT_NAME_DASHED} documentation ${PROJECT_BINARY_DIR}/doc/ is missing use -DUSE_DOCS=1 to generate documentation")
endif()

# Pull-in CPack and support for generating <Package>Config.cmake and packages.
include(Packaging)


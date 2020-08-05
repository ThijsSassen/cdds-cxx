cmake_minimum_required(VERSION 3.7)

add_subdirectory(ddscxx)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

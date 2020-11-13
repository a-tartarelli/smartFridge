cmake_minimum_required(VERSION 3.10)
project(mySmartFridge C)

set(CMAKE_C_STANDARD 99)


# Options
set(DEFAULT_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
if (NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif ()
if (NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif ()
if (NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif ()

# Set a default build type if none was specified
if (NOT CMAKE_BUILD_TYPE
        AND NOT CMAKE_CONFIGURATION_TYPES
        AND NOT CMAKE_BUILD_TYPE MATCHES Debug
        AND NOT CMAKE_BUILD_TYPE MATCHES Release)
    message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE
            STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
            "Debug" "Release")
endif ()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")


# copy files
message(STATUS "Copying the files into ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/files")
file(COPY files DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})


add_subdirectory(src)
add_subdirectory(test)

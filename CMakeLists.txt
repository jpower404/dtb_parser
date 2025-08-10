cmake_minimum_required(VERSION 3.10)

project(dtb_parser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find libfdt library and headers
find_library(LIBFDT_LIBRARY NAMES fdt PATHS /usr/lib/x86_64-linux-gnu)
find_path(LIBFDT_INCLUDE_DIR NAMES libfdt.h libfdt_env.h PATHS /usr/include)

# include directories for libfdt
include_directories(${LIBFDT_INCLUDE_DIR})

# add the source files to the project
set(SOURCES
    parse_dtb.cpp
)

# add the executable target
add_executable(parse_dtb ${SOURCES})

# link the executable with libfdt
target_link_libraries(parse_dtb ${LIBFDT_LIBRARY})
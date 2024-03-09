cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0079 NEW)

project(mochagen-assembler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

# -DJNGEN_DECLARE_ONLY")
SET(GCC_COVERAGE_COMPILE_FLAGS "--allow-multiple-definition")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(ASSEMBLER_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(ASSEMBLER_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(ASSEMBLER_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

include_directories(${ASSEMBLER_INSTALL_INCLUDE_DIR})

add_definitions(-w) # suppress warnings

add_subdirectory(src)

# add_subdirectory(test)

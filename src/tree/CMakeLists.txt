cmake_minimum_required(VERSION 3.2)
project(tree C CXX)

set(SOURCE_FILES
    tree.hpp
    tree.cpp
)

add_library(tree SHARED STATIC ${SOURCE_FILES})

install(TARGETS tree DESTINATION ${ASSEMBLER_INSTALL_LIB_DIR})
install(FILES tree.h DESTINATION ${ASSEMBLER_INSTALL_INCLUDE_DIR})

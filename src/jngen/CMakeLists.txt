cmake_minimum_required(VERSION 3.2)
project(jngen C CXX)

set(SOURCE_FILES
    jngen.hpp
    jngen.cpp
)

add_library(jngen OBJECT ${SOURCE_FILES})

install(TARGETS jngen DESTINATION ${ASSEMBLER_INSTALL_LIB_DIR})
install(FILES jngen.hpp DESTINATION ${ASSEMBLER_INSTALL_INCLUDE_DIR})

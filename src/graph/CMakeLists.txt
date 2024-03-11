cmake_minimum_required(VERSION 3.2)
project(graph C CXX)

set(SOURCE_FILES
    graph.hpp
    graph.cpp
)

add_library(graph OBJECT ${SOURCE_FILES})

install(TARGETS graph DESTINATION ${ASSEMBLER_INSTALL_LIB_DIR})
install(FILES graph.hpp DESTINATION ${ASSEMBLER_INSTALL_INCLUDE_DIR})
set_source_files_properties(graph.cpp PROPERTIES COMPILE_FLAGS -DJNGEN_DECLARE_ONLY)

cmake_minimum_required(VERSION 3.2)
project(array C CXX)

set(SOURCE_FILES
    array.cpp
    array.hpp
)

add_library(array OBJECT ${SOURCE_FILES})

install(TARGETS array DESTINATION ${ASSEMBLER_INSTALL_LIB_DIR})
install(FILES array.hpp DESTINATION ${ASSEMBLER_INSTALL_INCLUDE_DIR})
set_source_files_properties(array.cpp PROPERTIES COMPILE_FLAGS -DJNGEN_DECLARE_ONLY)

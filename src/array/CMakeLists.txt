cmake_minimum_required(VERSION 3.2)
project(mcg_array C CXX)

set(SOURCE_FILES
    mcg_array.cpp
    mcg_array.hpp
)

add_library(mcg_array OBJECT ${SOURCE_FILES})

install(TARGETS mcg_array DESTINATION ${ASSEMBLER_INSTALL_LIB_DIR})
install(FILES mcg_array.hpp DESTINATION ${ASSEMBLER_INSTALL_INCLUDE_DIR})
set_source_files_properties(mcg_array.cpp PROPERTIES COMPILE_FLAGS -DJNGEN_DECLARE_ONLY)

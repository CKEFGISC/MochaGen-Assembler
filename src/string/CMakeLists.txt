cmake_minimum_required(VERSION 3.2)
project(mcg_string C CXX)

set(SOURCE_FILES
    mcg_string.hpp
    mcg_string.cpp
)

add_library(mcg_string OBJECT ${SOURCE_FILES})

install(TARGETS mcg_string DESTINATION ${ASSEMBLER_INSTALL_LIB_DIR})
install(FILES mcg_string.hpp DESTINATION ${ASSEMBLER_INSTALL_INCLUDE_DIR})
set_source_files_properties(mcg_string.cpp PROPERTIES COMPILE_FLAGS -DJNGEN_DECLARE_ONLY)

cmake_minimum_required(VERSION 3.2)
project(assembler C CXX)

set(SOURCE_FILES
    assembler.h
    assembler.cpp
)

add_library(assembler SHARED STATIC ${SOURCE_FILES})

install(TARGETS assembler DESTINATION ${ASSEMBLER_INSTALL_LIB_DIR})
install(FILES assembler.h DESTINATION ${ASSEMBLER_INSTALL_INCLUDE_DIR})
set_source_files_properties(string.cpp PROPERTIES COMPILE_FLAGS -DJNGEN_DECLARE_ONLY)

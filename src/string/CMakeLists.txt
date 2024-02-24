cmake_minimum_required(VERSION 3.2)
project(string C CXX)

set(SOURCE_FILES
    string.hpp
    string.cpp
)

add_library(string SHARED STATIC ${SOURCE_FILES})

install(TARGETS string DESTINATION ${ASSEMBLER_INSTALL_LIB_DIR})
install(FILES string.h DESTINATION ${ASSEMBLER_INSTALL_INCLUDE_DIR})
set_source_files_properties(string.cpp PROPERTIES COMPILE_FLAGS -DJNGEN_DECLARE_ONLY)

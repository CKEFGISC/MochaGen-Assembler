cmake_minimum_required(VERSION 3.2)
project(array C CXX)

set(SOURCE_FILES
    array.hpp
    array.cpp
)

add_library(array SHARED STATIC ${SOURCE_FILES})

install(TARGETS array DESTINATION ${ASSEMBLER_INSTALL_LIB_DIR})
install(FILES array.hpp DESTINATION ${ASSEMBLER_INSTALL_INCLUDE_DIR})
set_source_files_properties(jngen.cpp PROPERTIES COMPILE_FLAGS -DJNGEN_DECLARE_ONLY)

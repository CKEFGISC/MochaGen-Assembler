cmake_minimum_required(VERSION 3.2)
project(number C CXX)

set(SOURCE_FILES
    number.hpp
    number.cpp
)

add_library(number SHARED STATIC ${SOURCE_FILES})
install(TARGETS number DESTINATION ${ASSEMBLER_INSTALL_LIB_DIR})
install(FILES number.hpp DESTINATION ${ASSEMBLER_INSTALL_INCLUDE_DIR})
set_source_files_properties(number.cpp PROPERTIES COMPILE_FLAGS -DJNGEN_DECLARE_ONLY)

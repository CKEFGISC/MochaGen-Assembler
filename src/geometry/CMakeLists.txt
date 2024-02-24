cmake_minimum_required(VERSION 3.2)
project(geometry C CXX)

set(SOURCE_FILES
    geometry.hpp
    geometry.cpp
)

add_library(geometry SHARED STATIC ${SOURCE_FILES})

install(TARGETS geometry DESTINATION ${ASSEMBLER_INSTALL_LIB_DIR})
install(FILES geometry.h DESTINATION ${ASSEMBLER_INSTALL_INCLUDE_DIR})
set_source_files_properties(geometry.cpp PROPERTIES COMPILE_FLAGS -DJNGEN_DECLARE_ONLY)

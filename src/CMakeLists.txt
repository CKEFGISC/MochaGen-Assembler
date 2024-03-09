cmake_minimum_required(VERSION 3.2)
project(MochaGen-Assembler)

add_subdirectory(array)
add_subdirectory(geometry)
add_subdirectory(graph)
add_subdirectory(number)
add_subdirectory(string)
add_subdirectory(jngen)
add_subdirectory(tree)

# For use of the assembler library in other projects
set(LIB_SOURCE_FILES
    assembler.h
    assembler.cpp
)

add_library(assembler ${LIB_SOURCE_FILES})
target_link_libraries(assembler jngen tree array geometry graph number string)
install(TARGETS assembler DESTINATION ${ASSEMBLER_INSTALL_LIB_DIR})

# For direct use of the assembler library
set(SOURCE_FILES
    main.cpp
)

add_executable(mochagen-assembler ${SOURCE_FILES})
target_link_libraries(mochagen-assembler jngen tree array geometry graph number string)
install(TARGETS mochagen-assembler DESTINATION ${ASSEMBLER_INSTALL_BIN_DIR})

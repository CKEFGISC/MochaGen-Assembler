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
    assembler.hpp
    assembler.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(assembler STATIC
    $<TARGET_OBJECTS:mcg_array>
    $<TARGET_OBJECTS:geometry>
    $<TARGET_OBJECTS:graph>
    $<TARGET_OBJECTS:number>
    $<TARGET_OBJECTS:mcg_string>
    $<TARGET_OBJECTS:jngen>
    $<TARGET_OBJECTS:tree>
    ${LIB_SOURCE_FILES}
)

# target_link_libraries(assembler jngen tree array geometry graph number string)
install(TARGETS assembler DESTINATION ${ASSEMBLER_INSTALL_LIB_DIR})
install(FILES assembler.hpp DESTINATION ${ASSEMBLER_INSTALL_INCLUDE_DIR})

# For direct use of the assembler library
set(SOURCE_FILES
    main.cpp
)

add_executable(mochagen-assembler ${SOURCE_FILES})
target_link_libraries(mochagen-assembler jngen tree mcg_array geometry graph number mcg_string)
install(TARGETS mochagen-assembler DESTINATION ${ASSEMBLER_INSTALL_BIN_DIR})

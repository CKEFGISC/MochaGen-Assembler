cmake_minimum_required(VERSION 3.2)
project(Assembler)

add_subdirectory(array)
add_subdirectory(geometry)
add_subdirectory(graph)
add_subdirectory(number)
add_subdirectory(string)
#add_subdirectory(tree)
set(SOURCE_FILES main.cpp)
link_directories(${ASSEMBLER_INSTALL_INCLUDE_DIR})

ADD_LIBRARY ( test_lib STATIC IMPORTED )
SET_PROPERTY ( TARGET test_lib PROPERTY IMPORTED_LOCATION ${ASSEMBLER_INSTALL_INCLUDE_DIR}/libjngen.a )


add_executable(assembler ${SOURCE_FILES})
#target_include_directories(src/number)
target_link_libraries(assembler array geometry graph number string )


target_link_libraries(assembler ${ASSEMBLER_INSTALL_INCLUDE_DIR}/libjngen.a)

#target_link_libraries(assembler graph)
#target_link_libraries(assembler string)

install(TARGETS assembler DESTINATION ${DIVISIBLE_INSTALL_BIN_DIR})

cmake_minimum_required(VERSION 3.2)
project(Assembler)

add_subdirectory(number)
set(SOURCE_FILES main.cpp)


add_executable(assembler ${SOURCE_FILES})
target_link_libraries(assembler number)
install(TARGETS assembler DESTINATION ${DIVISIBLE_INSTALL_BIN_DIR})

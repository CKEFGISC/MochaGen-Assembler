# MochaGen-Assembler

generate testdata generators for MochaGen

## Usage

### Use it directly to create generator

1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Modify the `src/main.cpp` for your own propose.
4. Create a build directory: `mkdir build && cd build`.
5. Generate the build files: `cmake ..`.
6. Build the project: `make install`.
7. Run your generator under `bin/mochagen-assembler`

### Use it as external library

To use this CMake project, follow these steps:

1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Create a build directory: `mkdir build && cd build`.
4. Generate the build files: `cmake ..`.
5. Build the project: `make install`.
6. Create Your Own `generator.cpp`, and link the `libassembler.a` to compile your generator.

Make sure to replace `<executable_name>` with the actual name of the generated executable.

Note: You may need to install any required dependencies before building the project.

## include

include the headers for parsing json and generating testdata

## src

main.cpp parses json and generates gen.cpp

## test

test the functions in src

## output

output of the test

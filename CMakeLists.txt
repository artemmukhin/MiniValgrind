cmake_minimum_required(VERSION 3.6)
project(MiniValgrind)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Src/Exceptions.h Src/Operators.cpp Src/Variable.cpp
        Src/Operators.h Src/Types.h Src/Variable.h Src/Visitor.h)
add_executable(MiniValgrind ${SOURCE_FILES})

add_custom_target(All COMMAND make -C ${MiniValgrind_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})

add_custom_target(Parser COMMAND make parser -C ${MiniValgrind_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})

add_custom_target(Valg COMMAND make valg -C ${MiniValgrind_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})
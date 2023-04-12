cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

project(emtest)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build.emscripten)

# Replace with your emscripten location
set(EMSCRIPTEN "C:/Users/alexa/work/emsdk/upstream/emscripten/system/include/emscripten")


add_definitions("-std=c++11")
set(SOURCES src/Application.cpp src/calculation.h src/libsweepcalculator.h)
add_executable(client ${SOURCES})
include_directories(${EMSCRIPTEN}) 
target_link_libraries(client  ${CMAKE_SOURCE_DIR}/src/lib-calc-emcc.a)
# target_link_libraries(client  ${CMAKE_SOURCE_DIR}/src/lib-calc-clang.a)
# target_link_libraries(client  ${CMAKE_SOURCE_DIR}/src/libsweepcalculator.a)
target_include_directories(client PRIVATE "src")
set_target_properties(client PROPERTIES LINK_FLAGS "-s MODULARIZE=1 --bind")
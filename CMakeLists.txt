cmake_minimum_required(VERSION 3.19)
project(SWPLAB-A3b)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCES "src/*.*")
add_executable(SWPLAB-A3b ${SOURCES} src/testVM.cpp src/vm.cpp src/vm.h src/main.cpp)

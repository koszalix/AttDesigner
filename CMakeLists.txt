cmake_minimum_required(VERSION 3.24)
project(AttDesigner)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall)
add_executable(AttDesigner main.cpp UITable.cpp UITable.h StorageTable.cpp StorageTable.h)

cmake_minimum_required(VERSION 3.24)
project(AttDesigner)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall)
add_executable(AttDesigner main.cpp UI/Table.cpp UI/Table.h Storage/Table.cpp Storage/Table.h Storage/AttenuatorParameters.cpp Storage/AttenuatorParameters.h UI/TableFormatting.h UI/AttenuatorParameters.cpp UI/AttenuatorParameters.h UI/_Utils.cpp UI/_Utils.h)

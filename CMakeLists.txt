cmake_minimum_required(VERSION 3.24)
project(AttDesigner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_compile_options(-Wall)
add_executable(AttDesigner main.cpp UI/Table.cpp UI/Table.h Storage/Table.cpp Storage/Table.h Storage/AttenuatorParameters.cpp Storage/AttenuatorParameters.h UI/TableFormatting.h UI/_Utils.cpp UI/_Utils.h App.cpp App.h UI/Prompts.cpp UI/Prompts.h Backend/Attenuators.cpp Backend/Attenuators.h Backend/PiAttenuator.cpp Backend/PiAttenuator.h Backend/BPiAttenuator.cpp Backend/BPiAttenuator.h Backend/TeeAttenuator.cpp Backend/TeeAttenuator.h Backend/BTeeAttenuator.cpp Backend/BTeeAttenuator.h Backend/Calc.cpp Backend/Calc.h Matcher/Match.cpp Matcher/Match.h)

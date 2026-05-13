cmake_minimum_required(VERSION 3.10) # set min. CMake version to 3.10
project(AxylithPhysicsEngine) # set project name

# set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(axylith_phys STATIC src/lexer.cpp src/parser.cpp) # create static library target named axylith_phys.a



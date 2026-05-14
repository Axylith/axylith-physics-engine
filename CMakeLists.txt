cmake_minimum_required(VERSION 3.20) # set min. CMake version to 3.20
project(AxylithPhysicsEngine) # set project name

# set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(axylith_phys STATIC src/evaluator.cpp) # create static library target named axylith_phys.a
target_include_directories(axylith_phys PUBLIC include/)

add_executable(tester tests/tester.cpp) # create executable target named tester
target_link_libraries(tester axylith_phys)

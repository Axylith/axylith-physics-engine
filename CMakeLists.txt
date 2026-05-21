cmake_minimum_required(VERSION 3.20)        # minimum CMake version
project(AxylithPhysicsEngine CXX)           # project name; CXX-only (no C toolchain probe)

# --- Language standard -----------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)               # use -std=c++20, not -std=gnu++20

# --- Library ---------------------------------------------------------------
# Static library target: axylith_phys
# NOTE: src/parser.cpp and src/bindings.cpp are currently empty (0 bytes).
#       Add them here once they contain definitions, otherwise they just
#       produce empty object files.
add_library(axylith_phys STATIC
    src/lexer.cpp
    src/parser.cpp
    src/evaluator.cpp
    # src/bindings.cpp
)
target_include_directories(axylith_phys PUBLIC include/)

# --- Test executable -------------------------------------------------------
add_executable(tester tests/tester.cpp)
target_link_libraries(tester PRIVATE axylith_phys)

# --- CTest registration ----------------------------------------------------
# Without these two lines `ctest` reports "No tests were found" and CI passes
# vacuously. enable_testing() turns on the test harness; add_test() registers
# the tester binary so `ctest --output-on-failure` actually runs it.
enable_testing()
add_test(NAME tester COMMAND tester)

#include <iostream>
#include "axylith_phys.h"

int main() {

    // TEST 1 --> "1 + 1 = 2"
    std::string expression = "1+1"; // test 1+1
    EvalResult result = evaluate(expression); // use EvalResult struct/object from header file to evaluate expression with 'evaluate' function 
    if (result.error_code == 0) { // if success (error code = 0)
        std::cout << "Input:" << expression << std::endl; // display input expression
        std::cout << "Output: " << result.value << " " << result.unit << std::endl; // display result
    } else {
        std::cout << "Error: [" << result.error_code << "]: " << result.error_message << std::endl; // display error message and code
    }

    return 0;
}

// HOW TO RUN TESTER:
// 1. run 'g++ -I./include -c src/evaluator.cpp -o evaluator.o' --> compiles evaluator.cpp to object file (evaluator.o) with include path for header files
// 2. then run 'ar rcs libaxylith_phys.a evaluator.o' --> creates static library from object file
// 3. then run 'g++ -I./include tests/tester.cpp libaxylith_phys.a -o tester && ./tester' --> compiles tester.cpp with static library and runs the tester executable to see results of test cases.
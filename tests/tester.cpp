#include <iostream>
#include "axylith_phys.h"

// run test helper function
void run_test(const std::string& expression) { 
    EvalResult result = evaluate(expression);
    if (result.error_code == 0) {
        std::cout << "Input: " << expression << std::endl;
        std::cout << "Output: " << result.value << " " << result.unit << std::endl;
    } else {
        std::cout << "Error: [" << result.error_code << "]: " << result.error_message << std::endl;
    }
}

// test cases
int main() {
    // simple arithmetic
    run_test("1+1");
    // run_test("2*(3+4)");
    // run_test("2^10");
    // run_test("10/4");

    return 0;
}

// HOW TO RUN TESTER:
// 1. open directory to 'build/' (cd build)
// 2. run 'cmake ..'
// 3. run 'cmake --build .'
// 4. run './tester'
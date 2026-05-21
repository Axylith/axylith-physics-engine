#include <cstdio>
#include "lexer.h"
#include "axylith_phys.h"

static int tests_run = 0;
static int tests_passed = 0;

#define TEST(name) \
    do { \
        tests_run++; \
        printf("[TEST] %-40s \n", (name).c_str()); \
    } while(0)

#define ASSERT(cond) \
    if (!(cond)) { \
        printf("FAIL (%s:%d)\n", __FILE__, __LINE__); \
        return false; \
    }

#define PASS() \
    do { \
        tests_passed++; \
        printf("OK\n\n"); \
        return true; \
    } while(0)

// function for testing evaluate() function
bool test(const std::string& expression, double expected_result) {
    TEST(expression);
    EvalResult r = evaluate(expression);
    ASSERT(r.error_code == 0);
    ASSERT(r.value == expected_result);
    printf("Result = %f\n", r.value);
    PASS();
}


// test cases go here
int main() {
    printf("\n╔═══════════════════════════════════╗\n");
    printf("║   Axylith Physics Engine v0.1     ║\n");
    printf("╚═══════════════════════════════════╝\n\n");

    // TEST CASES 1-4 (Basic Arithmetic):
    test("1+1", 2.0); // test 1+1 = 2
    test("2*(3+4)", 14.0); // test order of operations and parentheses (2*(3+4) = 2*7 = 14)
    test("2^10", 1024.0); // test exponentiation operator (2^10 = 1024)
    test("10/4", 2.5); // test division operator and floating point result (10/4 = 2.5)

    // TEST CASES 5-10:
    // Add more test cases here

    printf("%d / %d tests passed\n\n", tests_passed, tests_run);
    return (tests_passed == tests_run) ? 0 : 1;
}

// HOW TO RUN:
// 1. cd build
// 2. cmake ..
// 3. cmake --build .
// 4. ./tester
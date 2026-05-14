#include <cstdio>
#include "axylith_phys.h"

static int tests_run = 0;
static int tests_passed = 0;

#define TEST(name) \
    do { \
        tests_run++; \
        printf("  [TEST] %-40s ", name); \
    } while(0)

#define ASSERT(cond) \
    if (!(cond)) { \
        printf("FAIL (%s:%d)\n", __FILE__, __LINE__); \
        return false; \
    }

#define PASS() \
    do { \
        tests_passed++; \
        printf("OK\n"); \
        return true; \
    } while(0)

bool test_addition() {
    TEST("1+1 = 2");
    EvalResult r = evaluate("1+1");
    ASSERT(r.error_code == 0);
    ASSERT(r.value == 2.0);
    PASS();
}

bool test_brackets() {
    TEST("2*(3+4) = 14");
    EvalResult r = evaluate("2*(3+4)");
    ASSERT(r.error_code == 0);
    ASSERT(r.value == 14.0);
    PASS();
}

bool test_power() {
    TEST("2^10 = 1024");
    EvalResult r = evaluate("2^10");
    ASSERT(r.error_code == 0);
    ASSERT(r.value == 1024.0);
    PASS();
}

bool test_division() {
    TEST("10/4 = 2.5");
    EvalResult r = evaluate("10/4");
    ASSERT(r.error_code == 0);
    ASSERT(r.value == 2.5);
    PASS();
}

int main() {
    printf("\n╔═══════════════════════════════════╗\n");
    printf("║   Axylith Physics Engine v0.1     ║\n");
    printf("╚═══════════════════════════════════╝\n\n");

    test_addition();
    test_brackets();
    test_power();
    test_division();

    printf("\n  %d / %d tests passed\n\n", tests_passed, tests_run);
    return (tests_passed == tests_run) ? 0 : 1;
}

// HOW TO RUN:
// 1. cd build
// 2. cmake ..
// 3. cmake --build .
// 4. ./tester
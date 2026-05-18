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
        printf("OK\n"); \
        return true; \
    } while(0)

// // function for testing evaluate() function
// bool test(const std::string& expression, double expected_result) {
//     TEST(expression);
//     EvalResult r = evaluate(expression);
//     ASSERT(r.error_code == 0);
//     ASSERT(r.value == expected_result);
//     PASS();
// }

// function for testing tokenizer
bool test_tokenizer(const std::string& input, const std::vector<axylith::Token>& expected_tokens) {
    TEST("tokenizer: " + input);
    auto tokens = axylith::tokenize(input); // generate token vector from input

    // for each token, print its kind, value, raw text, and position in token vector
    for (const auto& token : tokens) {
        printf("kind=%d value=%f text=%-10s pos=%zu\n", (int)token.kind, token.value, token.text.c_str(), token.pos);
    }

    ASSERT(tokens.size() == expected_tokens.size()); // assert that the number of tokens generated matches the expected number of tokens 
    for (size_t i = 0; i < tokens.size(); i++) { // assert that each token's kind, value, text, and position matches the expected token's kind, value, text, and position
        ASSERT(tokens[i].kind == expected_tokens[i].kind);
        ASSERT(tokens[i].value == expected_tokens[i].value);
        ASSERT(tokens[i].text == expected_tokens[i].text);
        ASSERT(tokens[i].pos == expected_tokens[i].pos);
    }
    PASS();
}

int main() {
    printf("\n╔═══════════════════════════════════╗\n");
    printf("║   Axylith Physics Engine v0.1     ║\n");
    printf("╚═══════════════════════════════════╝\n\n");

    // test("1+1", 2.0);
    // test("2*(3+4)", 14.0);
    // test("2^10", 1024.0);
    // test("10/4", 2.5);

    // printf("\n  %d / %d tests passed\n\n", tests_passed, tests_run);
    // return (tests_passed == tests_run) ? 0 : 1;

    // test tokenizer for 1+1, which should generate 4 tokens: NUMBER(1), PLUS, NUMBER(1), END
    test_tokenizer("1+1", {
        {axylith::TokKind::NUMBER, 1.0, "1", 0},
        {axylith::TokKind::PLUS, 0.0, "+", 1},
        {axylith::TokKind::NUMBER, 1.0, "1", 2},
        {axylith::TokKind::END, 0.0, "", 3}
    });
    printf("\n");

    // test tokenizer for 2*(3+4), which should generate 8 tokens: NUMBER(2), MULTIPLY, LPAREN, NUMBER(3), PLUS, NUMBER(4), RPAREN, END
    test_tokenizer("2*(3+4)", {
        {axylith::TokKind::NUMBER, 2.0, "2", 0},
        {axylith::TokKind::MULTIPLY, 0.0, "*", 1},
        {axylith::TokKind::LPAREN, 0.0, "(", 2},
        {axylith::TokKind::NUMBER, 3.0, "3", 3},
        {axylith::TokKind::PLUS, 0.0, "+", 4},
        {axylith::TokKind::NUMBER, 4.0, "4", 5},
        {axylith::TokKind::RPAREN, 0.0, ")", 6},
        {axylith::TokKind::END, 0.0, "", 7}
    });
    printf("\n");

    // test tokenizer for scientific notation 1e-3, which should generate 2 tokens: NUMBER(0.001), END
    test_tokenizer("1e-3", {
        {axylith::TokKind::NUMBER, 0.001, "1e-3", 0},
        {axylith::TokKind::END, 0.0, "", 4}
    });
}

// HOW TO RUN:
// 1. cd build
// 2. cmake ..
// 3. cmake --build .
// 4. ./tester
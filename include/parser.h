#pragma once
#include "lexer.h"
#include <vector>

namespace axylith {
    struct Parser { // parser struct, takes in list of tokens from lexer, and position of current token being looked at
        std::vector<Token> tokens;
        size_t current_token; // index of current token being looked at in the token list

        // constructor
        Parser(std::vector<Token> tokens);

        // helper functions to access succeeding token, and to get current token and parse it
        Token peek()
        Token consume()

        // parser rules for expresions
        double parseExpression();
        double parseTerm();
        double parseFactor();
        double parseUnary();
        double parsePrimary();
    };
}

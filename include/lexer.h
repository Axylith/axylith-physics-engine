#pragma once
#include <string>
#include <vector>

namespace axylith { // namespace for the physics engine
    enum class TokKind { // all token types used for reading an input/unit input
        NUMBER,
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        EXP,
        LPAREN,
        RPAREN,
        VAR,
        END
    };

    struct Token { // represents a token --> type of token, its value if a number, its string representation, and its position in the input for error reporting
        TokKind kind; // type of token (e.g., number, +, -, etc.)
        double value; // if the kind is a number, this holds its value
        std::string text; // string representation of the token (e.g. 1 --> "1", kg --> "kg", + --> "PLUS", etc.)
        size_t pos; // tracks the position of the token in the input string for error reporting
    }; 

    std::vector<Token> tokenize(const std::string& input); // function declaration for tokenizer 
}



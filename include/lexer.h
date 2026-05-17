#include <string>
#include <vector>
#include <cctype>

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

    struct Token { // represents a token with its 
        TokKind kind; // type of token (e.g., number, +, -, etc.)
        double value; // if the kind is a number, this holds its value
        std::string text; // string representation of the token (e.g. 1 --> "1", kg --> "kg", + --> "PLUS", etc.)
        int pos; // tracks the position of the token in the input string for error reporting
    }; 

    std::vector<Token> tokenize(const std::string& input) { // splits an input into individual tokens (e.g. 1+1--> [1, +, 1, END])
        std::vector<Token> token;
        for (char c : input) {
            // create a token and set to current character and position
            Token t;
            t.kind = c;
            t.pos = &c - &input[0]; 

            // check token kind and set correct text
            switch (c) {
                case '+': // if plus
                    t.text = "PLUS";
                    break;
                case '-': // if minus
                    t.text = "MINUS";
                    break;
                case '*': // if multiply
                    t.text = "MULTIPLY";
                    break;
                case '/': // if divide
                    t.text = "DIVIDE";
                    break;
                case '(': // if left parenthesis
                    t.text = "LPAREN";
                    break;
                case ')': // if right parenthesis
                    t.text = "RPAREN";
                    break;
                default: // if number or invalid character
                    if (isdigit(c)) {
                        t.kind = TokKind::NUMBER;
                        t.value = c - '0'; 
                        t.text = std::string(1, c);
                    } else if (!isspace(c)) {
                        throw std::runtime_error("Invalid character in input: " + std::string(1, c));
                    }
            }
            token.push_back(t); // add token to vector of tokens
        }
        token.push_back({TokKind::END, 0, "END", input.length()}); // add END token
        return token;
    }; 


}


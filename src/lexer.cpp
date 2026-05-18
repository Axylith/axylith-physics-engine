#include "lexer.h"
#include <stdexcept>
#include <cctype>

namespace axylith { // namespace for the physics engine
    std::vector<Token> tokenize(const std::string& input) { // splits an input into individual tokens (e.g. 1+1--> [1, +, 1, END])
            std::vector<Token> tokens; // create vector to hold tokens
            size_t i = 0; // set position index to 0

            // loop through the input string character by character
            while (i < input.size()) {
                char c = input[i]; // get current character

                // use a switch statement to determine the type of token based on the current character
                switch (c) {
                    case ' ': // skip whitespace
                        i++;
                        break;

                    case '+': // if token is plus (+)
                        tokens.push_back({TokKind::PLUS, 0.0, "+", i});
                        i++;
                        break;

                    case '-': // if token is minus (-)
                        tokens.push_back({TokKind::MINUS, 0.0, "-", i});
                        i++;
                        break;

                    case '*': // if token is multiply (*)
                        tokens.push_back({TokKind::MULTIPLY, 0.0, "*", i});
                        i++;
                        break;

                    case '/': // if token is divide (/)
                        tokens.push_back({TokKind::DIVIDE, 0.0, "/", i});
                        i++;
                        break;
                    case '^': // if token is exponent (^)
                        tokens.push_back({TokKind::EXP, 0.0, "^", i});
                        i++;
                        break;

                    case '(': // if token is left parenthesis (()
                        tokens.push_back({TokKind::LPAREN, 0.0, "(", i});
                        i++;
                        break; 

                    case ')': // if token is right parenthesis ())
                        tokens.push_back({TokKind::RPAREN, 0.0, ")", i});
                        i++;
                        break;

                    default:
                        // if token is a number (e.g. 1, 3.14, etc.)
                        if (std::isdigit((unsigned char)c) || (c == '.' && i + 1 < input.size() && std::isdigit((unsigned char)input[i + 1]))) { 
                            size_t start = i; // store starting position index
                            while (i < input.size() && (std::isdigit((unsigned char)input[i]))) { // increase position index if a digit appears
                                i++;
                            }

                            if (i < input.size() && input[i] == '.') { // then increase position index if a decimal point appears
                                i++;
                                while (i < input.size() && std::isdigit((unsigned char)input[i])) { // increase again for digits that appear after the decimal point
                                    i++;
                                }
                            }

                            if (i < input.size() && (input[i] == 'e' || input[i] == 'E')) { // then increase position index if an exponent appears
                                size_t j = i + 1; // store position index after 'e' or 'E'
                                if (j < input.size() && (input[j] == '+' || input[j] == '-')) { // if there is a sign after 'e' or 'E', skip the sign
                                    j++;
                                }

                                if (j < input.size() && std::isdigit((unsigned char)input[j])) { // if digits after the sign
                                    i = j;
                                    while (i < input.size() && std::isdigit((unsigned char)input[i])) { // increase position index for digits in the exponent
                                        i++;
                                    }
                                }
                            }

                            std::string num_string = input.substr(start, i - start); // get substring whcih consists of the number
                            tokens.push_back({TokKind::NUMBER, std::stod(num_string), num_string, start}); // add number token to vector with its value and string representation
                        }

                        // if token is an identifier (e.g. units, function names, etc.)
                        else if (std::isalpha((unsigned char)c)) { 
                            size_t start = i;
                            while (i < input.size() && std::isalpha((unsigned char)input[i])) { // increase position index for letter characters in the identifier
                                i++;
                            }
                            std::string id_string = input.substr(start, i - start); // get substring which consists of the identifier
                            tokens.push_back({TokKind::VAR, 0.0, id_string, start}); // add identifier token to vector with its string representation
                        }

                        else { // throw an error otherwise
                            throw std::runtime_error("Unexpected character: " + std::string(1, c) + " at position " + std::to_string(i));
                        }
                        break;
                }
            }

            tokens.push_back({TokKind::END, 0.0, "", i}); // add END token
            return tokens; // return vector of tokens
        }
}

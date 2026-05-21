#include "lexer.h"
#include "parser.h"
#include <stdexcept>
#include <cmath>

namespace axylith {
    // create parser constructor instance with token vector, and set current token index to 0
    Parser::Parser(std::vector<Token> tokens) : tokens(tokens), current_token(0) {} 

    // peek function --> get current token
    Token Parser::peek() {
        if (current_token < tokens.size()) {
            return tokens[current_token];
        }
        return tokens.back();
    }

    // consume function --> 'consume' current token to advance to the next token
    Token Parser::consume() {
        if (current_token < tokens.size()) {
            current_token++;
            return tokens[current_token - 1];
        }
        return tokens.back();
    }


    // parse primary expressions (numbers itself, or expressions enclosed in parentheses)
    double Parser::parsePrimary() {
        if (peek().kind == TokKind::NUMBER) { // if token is a number --> consume it and return its value
            return consume().value;
        }

        else if (peek().kind == TokKind::LPAREN){ // if token is a left parenthesis --> consume it, parse the expression inside the parentheses, and expect a right parenthesis to close it
            consume();
            double expr = parseExpression(); // parses expression inside parentheses
            if (peek().kind == TokKind::RPAREN) { // if closed in a right parenthesis, consume and return expression
                consume();
                return expr;
            }
            else { // if not closed in a right parenthesis, throw an error
                throw std::runtime_error("Expected ')' at position " + std::to_string(peek().pos));
            }
        }
        
        else { // if token is not a number or left parenthesis, throw an error
            throw std::runtime_error("Unexpected character: " + peek().text + " at position " + std::to_string(peek().pos));
        }
    }

    // parse unary operators for expression (e.g. negation)
    double Parser::parseUnary() {
        if (peek().kind == TokKind::MINUS) { // if token is a minus sign, consume to move forward and return negation of the next expression (e.g. -(3+4) --> -7) 
            consume();
            return -parsePrimary();
        }
        else if (peek().kind == TokKind::PLUS) { // otherwise if token is a plus sign, consume to move forward and return the next expression itself (e.g. +3 --> 3)
            consume();
            return parsePrimary();
        }
        else { // otherwise return the next expression
            return parsePrimary();
        }
    }

    // handles exponentiation of expressions, ensuring right-associativity (e.g. 2^3^2 --> 2^(3^2) --> 512 instead of (2^3)^2 --> 64)
    double Parser::parseFactor() {
        double base = parseUnary(); // parse the base of the exponentiation (e.g. 2 in 2^3)
        if (peek().kind == TokKind::EXP) { // if token is an exponentiation operator, consume to move forward and return the result of the exponentiation
            consume();
            double power = parseFactor(); // parse the exponent (recursively call parseFactor to handle cases of multiple exponentiations in a row, e.g. 2^3^2)
            return std::pow(base, power); // return the result of the exponentiation
        }
        return base; // otherwise return the base
    }

    // handles multiplication and division of expressions
    double Parser::parseTerm() {
        double left = parseFactor(); // parse the first factor in the term
        while (peek().kind == TokKind::MULTIPLY || peek().kind == TokKind::DIVIDE) { 
            Token next = consume(); // save the multiplication/division operator token and consume to move forward
            double right = parseFactor(); // get the next factor 
            if (next.kind == TokKind::MULTIPLY) { // if token is a multiplication operator, multiply the left and right factors and set left to the result
                left *= right;
            }
            else { // if token is a division operator, check for division by zero and divide the left factor by the right factor
                if (right == 0) { // check for division by zero and throw an error if right factor is zero
                    throw std::runtime_error("Division by zero at position " + std::to_string(next.pos));
                }
                left /= right; // otherwise, divide the left factor by the right factor and set left to the result
            }
        }
        return left; // return result of multiplication/division
    }

    // handles addition and subtraction of expressions
    double Parser::parseExpression() {
        double left = parseTerm(); // parse the first term in the expression
        while (peek().kind == TokKind::PLUS || peek().kind == TokKind::MINUS) {
            Token next = consume(); // save the addition/subtraction operator token and consume to move forward
            double right = parseTerm(); // parse the next term in the expression
            if (next.kind == TokKind::PLUS) { // if token is a plus sign, add the left and right terms and set left to the result
                left += right; 
            }
            else { // if token is a minus sign, subtract the right term from the left term and set left to the result
                left -= right;
            }
        }
        return left; // return result of addition/subtraction
    }
}
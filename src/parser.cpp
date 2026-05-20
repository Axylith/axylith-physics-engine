#include "lexer.h"
#include "parser.h"

namespace Axylith {
    // peek function --> get current token
    Token Parser::peek() {
        if (current_token < tokens.size()) {
            return tokens[current_token];
        }
        return tokens.back();
    }

    Token Parser::consume() {
        
    }

    double Parser::parseExpression() {

    }

    double Parser::parseTerm() {

    }

    double Parser::parseFactor() {

    }

    // parse unary (e.g. negation)
    double Parser::parseUnary() {
        if {
            return 
        }
    }

    // DO THIS FIRST
    double Parser::parsePrimary() {
        if (tokens[current_token].kind == TokKind::NUMBER) {
            current_token++;
            return tokens[current_token].value;
        }
        else if (tokens[current_token].kind == TokKind::LPAREN){ 
            
        }
        else {
            throw std::runtime_error("Unexpected character:");
        }
    }
}
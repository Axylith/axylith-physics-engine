#include "parser.h"
#include "lexer.h"
#include "axylith_phys.h"
#include <stdexcept>

EvalResult evaluate(const std::string& expression) {
    try {
        auto tokens = axylith::tokenize(expression);
        axylith::Parser parser(tokens);
        double result = parser.parseExpression();
        return EvalResult{result, "", 0, ""}; // return the evaluated result with code 0 for success
    }
    catch (const std::exception& e) {
        return EvalResult{0, "", -1, e.what()}; // return no value, error code -1 and error message if a runtime error occurs during parsing
    }
}

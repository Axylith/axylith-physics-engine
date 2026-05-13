#include <string>

struct EvalResult {
    double value;
    std::string unit;   
    int error_code;
    std::string error_message;
};

EvalResult evaluate(const std::string& expression);
#pragma once
#include <string> 

struct EvalResult { 
    double value; // value of the unit
    std::string unit; // unit
    int error_code; // error code, 0 for success, non-zero for errors
    std::string error_message; // error message
};

EvalResult evaluate(const std::string& expression); 
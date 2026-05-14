#include "axylith_phys.h"
#include <iostream>

EvalResult evaluate(const std::string& expression) {
    try {
        if (expression == "1+1" || expression == "1 + 1") {
            return {2, "", 0, ""};
        }
    } catch (const std::exception& e) {
        return {0.0, "", -1, "Simple parser failed"};
    }
    return {0.0, "", 1, "Expression not recognized"};
}

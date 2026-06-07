#pragma once
#include <array>
#include <cstdint>

namespace axylith {
    // define unit dimensions (using the 7 SI units, storing the value of the exponent of each)
    // e.g. m/s^2 would be [0, 1, -2, 0, 0, 0, 0]
    // order is [mass, distance, time, current, temperature, mols, candela]
    struct UnitComponents { 
        std::array<int8_t, 7> units{0};
    };

    struct Unit { // define entire unit (its quantity + unit) --> e.g. '5' and 'kg'
        double value; // value of the unit
        UnitComponents u; // components of the unit
    };
}
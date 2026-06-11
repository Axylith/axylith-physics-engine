#pragma once
#include <array>
#include <unordered_map>
#include <string>
#include <cstdint>

namespace axylith {
    // define unit dimensions (using the 7 SI units, storing the value of the exponent of each)
    // e.g. m/s^2 would be [0, 1, -2, 0, 0, 0, 0]
    // order is [mass (g), distance (m), time (s), current (A), temperature (K), mols (mol), candela (cd)]
    struct UnitComponents { 
        std::array<int8_t, 7> units{0};
    };

    struct Unit { // define entire unit (its quantity + unit) --> e.g. '5' and 'kg'
        double value; // value of the unit
        UnitComponents u; // components of the unit
    };

    // define unit array + factor (for converting to larger scale units)
    struct StandardUnits{
        UnitComponents u;
        double scalar;
    };

    class UnitLookup { // comment
        public:
            std::unordered_map<std::string, StandardUnits> common_units_table; // define lookup table for standard units
            std::unordered_map<std::string, double> prefix_table; // define lookup table for prefix
            
            UnitLookup() { // asdf
                // define lookups for commonly used units (including derived and miscellaneous)
                // SI units
                common_units_table["g"] = {UnitComponents{1,0,0,0,0,0,0}, 1.0};
                common_units_table["m"] = {UnitComponents{0,1,0,0,0,0,0}, 1.0};
                common_units_table["s"] = {UnitComponents{0,0,1,0,0,0,0}, 1.0};
                common_units_table["A"] = {UnitComponents{0,0,0,1,0,0,0}, 1.0};
                common_units_table["K"] = {UnitComponents{0,0,0,0,1,0,0}, 1.0};
                common_units_table["mol"] = {UnitComponents{0,0,0,0,0,1,0}, 1.0};
                common_units_table["cd"] = {UnitComponents{0,0,0,0,0,0,1}, 1.0};

                // derived units
                common_units_table["N"] = {UnitComponents{1,1,-2,0,0,0,0}, 1000.0};
                common_units_table["J"] = {UnitComponents{1,2,-2,0,0,0,0}, 1000.0};
                common_units_table["Hz"] = {UnitComponents{0,0,-1,0,0,0,0}, 1.0};

                // misc units
                common_units_table["min"] = {UnitComponents{0,0,1,0,0,0,0}, 60.0};

                // define lookups for prefixes
                prefix_table["k"] = {1000.0};
            }
    };
}
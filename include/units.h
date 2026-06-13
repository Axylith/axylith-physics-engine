#pragma once
#include <array>
#include <unordered_map>
#include <string>
#include <cstdint>
#include <numbers>

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
                common_units_table["kg"]  = {UnitComponents{1,0,0,0,0,0,0}, 1.0};
                common_units_table["g"]   = {UnitComponents{1,0,0,0,0,0,0}, 1e-3}; 
                common_units_table["m"]   = {UnitComponents{0,1,0,0,0,0,0}, 1.0};
                common_units_table["s"]   = {UnitComponents{0,0,1,0,0,0,0}, 1.0};
                common_units_table["A"]   = {UnitComponents{0,0,0,1,0,0,0}, 1.0};
                common_units_table["K"]   = {UnitComponents{0,0,0,0,1,0,0}, 1.0};
                common_units_table["mol"] = {UnitComponents{0,0,0,0,0,1,0}, 1.0};
                common_units_table["cd"]  = {UnitComponents{0,0,0,0,0,0,1}, 1.0};

                // derived units
                common_units_table["N"]   = {UnitComponents{1,1,-2,0,0,0,0}, 1.0};
                common_units_table["J"]   = {UnitComponents{1,2,-2,0,0,0,0}, 1.0};
                common_units_table["Hz"]  = {UnitComponents{0,0,-1,0,0,0,0}, 1.0};
                common_units_table["Pa"]  = {UnitComponents{1,-1,-2,0,0,0,0}, 1.0};
                common_units_table["V"]   = {UnitComponents{1,-1,-2,0,0,0,0}, 1.0};
                common_units_table["W"]   = {UnitComponents{1,2,-3,0,0,0,0}, 1.0};
                common_units_table["rad"] = {UnitComponents{0,0,0,0,0,0,0}, 1.0}
                common_units_table["C"]   = {UnitComponents{0,0,1,1,0,0,0}, 1.0};
                common_units_table["ohm"] = {UnitComponents{1,2,-3,-2,0,0,0}, 1.0};
                common_units_table["F"]   = {UnitComponents{-1,-2,4,2,0,0,0}, 1.0}
                common_units_table["Wb"]  = {UnitComponents{-1,-2,4,2,0,0,0}, 1.0}
                common_units_table["S"]   = {UnitComponents{-1,-2,3,2,0,0,0}, 1.0};
                common_units_table["T"]   = {UnitComponents{1,0,-2,-1,0,0,0}, 1.0};
                common_units_table["H"]   = {UnitComponents{1,2,-2,-2,0,0,0}, 1.0};
                common_units_table["rad"] = {UnitComponents{0,0,0,0,0,0,0}, 1.0};
                common_units_table["lm"]  = {UnitComponents{0,0,0,0,0,0,1}, 1.0};
                common_units_table["lx"]  = {UnitComponents{0,-2,0,0,0,0,1}, 1.0};
                common_units_table["Bq"]  = {UnitComponents{0,0,-1,0,0,0,0}, 1.0};
                common_units_table["Gy"]  = {UnitComponents{0,2,-2,0,0,0,0}, 1.0};
                common_units_table["Sv"]  = {UnitComponents{0,2,-2,0,0,0,0}, 1.0};

                // misc units
                common_units_table["min"]  = {UnitComponents{0,0,1,0,0,0,0}, 60.0};
                common_units_table["h"]    = {UnitComponents{0,0,1,0,0,0,0}, 3600.0};
                common_units_table["degC"] = {UnitComponents{0,0,0,0,1,0,0}, 1.0};
                common_units_table["day"]  = {UnitComponents{0,0,1,0,0,0,0}, 86400.0};
                common_units_table["deg"]  = {UnitComponents{0,0,0,0,0,0,0}, std::numbers::pi / 180.0};
                common_units_table["L"]    = {UnitComponents{0,3,0,0,0,0,0}, 1e-3};

                // define lookups for prefixes
                prefix_table["Q"]  = 1e30;  // quetta
                prefix_table["R"]  = 1e27;  // ronna
                prefix_table["Y"]  = 1e24;  // yotta
                prefix_table["Z"]  = 1e21;  // zetta
                prefix_table["E"]  = 1e18;  // exa
                prefix_table["P"]  = 1e15;  // peta
                prefix_table["T"]  = 1e12;  // tera
                prefix_table["G"]  = 1e9;   // giga
                prefix_table["M"]  = 1e6;   // mega
                prefix_table["k"]  = 1e3;   // kilo
                prefix_table["h"]  = 1e2;   // hecto
                prefix_table["da"] = 1e1;   // deca

                prefix_table["d"]  = 1e-1;  // deci
                prefix_table["c"]  = 1e-2;  // centi
                prefix_table["m"]  = 1e-3;  // milli
                prefix_table["u"]  = 1e-6;  // micro 
                prefix_table["n"]  = 1e-9;  // nano
                prefix_table["p"]  = 1e-12; // pico
                prefix_table["f"]  = 1e-15; // femto
                prefix_table["a"]  = 1e-18; // atto
                prefix_table["z"]  = 1e-21; // zepto
                prefix_table["y"]  = 1e-24; // yocto
                prefix_table["r"]  = 1e-27; // ronto
                prefix_table["q"]  = 1e-30; // quecto
            };
    };
}
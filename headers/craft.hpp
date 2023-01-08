#ifndef CRAFT_HPP
#define CRAFT_HPP

#include "item.hpp"
#include <iostream>
#include <vector>
#include <sstream>

class Craft {
    public:
        Craft();

    private:    
        std::vector<std::string> _recipesnames;
        std::vector<std::string> _recipes;
};

#endif
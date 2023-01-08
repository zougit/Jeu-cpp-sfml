#ifndef SAVE_HPP
#define SAVE_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

class Save
{
    public:
        Save();
        void saveMap(std::vector<std::vector<int>> m);
        std::vector<std::vector<int>> loadMap();

    private:
        std::vector<std::vector<int>> _map;
};

#endif
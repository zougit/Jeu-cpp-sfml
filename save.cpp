#include "headers/save.hpp"
using namespace std;

Save::Save() {}

void Save::saveMap(vector<vector<int>> map)
{
    ofstream myfile;
    myfile.open("save.txt");

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            myfile << to_string(map[i][j]);
        }
    }

    myfile.close();
}

vector<vector<int>> Save::loadMap()
{
    string myText;
    int i=0;
    ifstream myfile;
    myfile.open("save.txt");

    while (getline(myfile, myText))
    {
        for (int j = 0; j < 30; j++)
        {
           _map[i].push_back(myText[0]) ;
        }
        i++;
    }
    myfile.close();
    return _map;
}
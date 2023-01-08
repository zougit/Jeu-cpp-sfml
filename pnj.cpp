#include "headers/pnj.hpp"
using namespace std;

Pnj::Pnj() : _name("Paulo"), _job("fourtout")
{
}

Pnj::Pnj(string name, string job) : _name(name), _job(job)
{
}

void Pnj::displayPnj()
{
    cout << "name: " << _name << endl
         << "job: " << _job << endl
         << endl;
}

Pnj::~Pnj()
{
}
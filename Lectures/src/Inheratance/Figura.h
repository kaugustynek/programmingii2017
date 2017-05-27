#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class Figura
{
protected:
    string nazwa;
public:
    Figura();
    ~Figura();
    virtual double Obwod() = 0;
    virtual double Pole() = 0;
};


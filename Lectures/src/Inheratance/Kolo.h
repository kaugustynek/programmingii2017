#pragma once
#include "Figura.h"

class Kolo : public Figura
{
private:
    double r;
public:
    Kolo(double r);
    virtual ~Kolo();

    virtual double Obwod();
    virtual double Pole();
};


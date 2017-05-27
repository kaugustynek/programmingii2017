#pragma once
#include "Figura.h"

class Prostokat : public Figura
{
private:
    double a, b;
public:
    Prostokat(double a, double b);
    virtual ~Prostokat();

    virtual double Obwod();
    virtual double Pole();
};


#include "Prostokat.h"

Prostokat::Prostokat(double a, double b)
{
    this->a = a;
    this->b = b;
}

Prostokat::~Prostokat()
{
}

double Prostokat::Obwod()
{
    return 2*a+2*b;
}

double Prostokat::Pole()
{
    return a*b;
}

#define _USE_MATH_DEFINES
#include <cmath>
#include "Kolo.h"

Kolo::Kolo(double r)
{
    this->r = r;
}

Kolo::~Kolo()
{
}

double Kolo::Obwod()
{
    return 2*M_PI*r;
}

double Kolo::Pole()
{
    return M_PI*r*r;
}

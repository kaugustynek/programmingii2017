#include "Punkt.h"

int Point::numberOfInstances = 0;

// konstruktor domyœlny
Point::Point()
{
    ++numberOfInstances;
    x = 0; y = 0;
}
// konstruktor z parametrami
Point::Point(double x, double y) : x(x) // lista inicjalizacyjna
{
    ++numberOfInstances;
    this->y = y;
}
// konstruktor kopiuj¹cy
Point::Point(const Point& other) : x(other.x)
{
    ++numberOfInstances;
    this->y = other.y;
}

Point::~Point(void)
{
    --numberOfInstances;
}

double Point::GetX() const
{
    return this->x;
}

double Point::GetY() const
{
    return this->y;
}

void Point::SetX(double value)
{
    x = value;
}

void Point::SetY(double value)
{
    y = value;
}

int Point::SizeOfAllPoints()
{
    return numberOfInstances * sizeof(Point);
}

// this = other
Point & Point::operator=(const Point & other)
{
    x = other.x;
    y = other.y;

    return *this;
}

//this + other
Point Point::operator+(const Point & other)
{
    Point result = *this;

    result.x += other.x;
    result.y += other.y;

    return result;
}

// result = this * factor
Point Point::operator*(double factor)
{
    Point result = *this;

    result.x *= factor;
    result.y *= factor;

    return result;
}

bool Point::operator==(const Point & other)
{
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point & other)
{
    return !(*this == other);
}

double Point::operator()(int i)
{
    return i == 0 ? x : y;
}

double Point::operator[](int i)
{
    return (*this)(i);
}

Point operator*(double factor, const Point & other)
{
    Point result = other;

    result.x *= factor;
    result.y *= factor;

    return result;
}

ostream & operator<<(ostream & out, const Point & other)
{
    out << other.GetX() << ", " << other.GetY() << endl;

    return out;
}

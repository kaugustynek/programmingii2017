#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
    double x;
    double y;
public:
    static int numberOfInstances;
    // konstruktory
    Point(void);
    Point(double x, double y);
    Point(const Point & other);
    // destruktor
    ~Point(void);
    // selektory
    double GetX() const;
    double GetY() const;
    // modyfikatory
    void SetX(double value);
    void SetY(double value);
    static int SizeOfAllPoints();
    //double DistanceTo(double x, double y) const;
    //static double DistanceTo(const Point& p1, const Point& p2);
    //void Move(double dx, double dy);
    //void MoveTo(const Point& destination);
    //void MoveToCenter(const Point& topLeft, const Point& bottomRight);
    // operatory
    Point& operator = (const Point & other);
    Point operator + (const Point & other);
    Point operator * (double factor);
    bool operator == (const Point & other);
    bool operator != (const Point & other);

    friend Point operator* (double factor, const Point & other);

    // zaprzyjaznienie z funkcjami
    friend ostream &operator <<(ostream &out, const Point & other);
    //friend ostream &operator >> (istream &out, Point & other);

    //P(0) P(1)
    double operator()(int i);
    double operator[](int i);
};






#include "Point.hpp"
#include <cmath>

c_Point::c_Point(double x, double y)
{
    c_Point::x = x;
    c_Point::y = y;
}

double c_Point::get_mag()
{
    return std::sqrt(x*x+y*y);
}

double c_Point::get_unit_x()
{
    return x/get_mag();
}

double c_Point::get_unit_y()
{
    return y/get_mag();
}

double c_Point::get_x()
{
    return x;
}

double c_Point::get_y()
{
    return y;
}

c_Point::~c_Point()
{
}
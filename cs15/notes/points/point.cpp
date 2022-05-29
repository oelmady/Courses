#include "point.h"
#include <iostream>
//
// initialize a new point with given coordinates
//

Point::Point(int x_coord, int y_coord)
{
    x = x_coord;
    y = y_coord;
}

Point::Point()
{
    x = y = 0;
}

Point Point::add(Point other) 
{
    int x_coord = x + other.x;
    int y_coord = y + other.y;
    return Point(x_coord, y_coord);
}
void Point::print()
{
    std::cout << "( " << x << ", " << y << " )\n";

}

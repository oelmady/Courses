#ifndef POINT_H //if not defined, define it here
#define POINT_H

class Point
{
public:
    Point(int x_coord, int y_coord);
    Point();

    int get_x();
    int get_y();
    Point add(Point other);
    void print();

private:
    int x, y;
};

#endif

#include <iostream>
#include "point.h"

using namespace std;

int main() {
    Point p1(1,-2), p2(3,4);

    Point p3 = p1.add(p2);

    cout << "p3: ";
    p3.print();

    return 0;
}

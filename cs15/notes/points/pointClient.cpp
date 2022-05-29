#include <iostream>
#include "point.h"

using namespace std;

int main() {
    Point p1(1,-2), p2(3,4);
    
    cout << "p1: "; 
    p1.print();
    cout << "p2: "; 
    p2.print();

    Point p3 = p1.add(p2);

    cout << "p3: ";
    p3.print();

    return 0;
}

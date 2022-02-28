#include <iostream>;

int myvar[5];
int foo = 42;
int * pointy;

double average(double a, double b) {
    return a*b/2;
}

int main(){
    pointy = &foo;    
    *pointy = foo+1;
    int bar = 100;
    pointy = &bar;
    *pointy = bar + 1;
    std::cout << pointy << std::endl;
    pointy = myvar;
    for (int i = 0; i <5; i++) {
        myvar[i] = i;
    }
    double z = average(foo, bar);

    return -1;
}














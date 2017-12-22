#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Polygon{
protected:
    double width, height;
public:
    void set_values(double a, double b) {
        width=a; 
        height=b;
    }
};

class Rectangle: public Polygon{
public:
    double area(){
        return width*height;
    }
};

class Triangle: public Polygon{
public:
    double area(){
        return width*height/2;
    }
};

int main(){
    Rectangle rect;
    Triangle trgl;
    rect.set_values(3,4);
    trgl.set_values(3,5);
    cout << "area of rectangle is " <<  rect.area() << endl;
    cout << "area of triangle is "<< trgl.area() << endl;

    return 0;
}
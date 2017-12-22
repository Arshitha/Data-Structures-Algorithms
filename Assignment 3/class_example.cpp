#include <iostream>
#include <cmath>

using namespace std;

class Circle {
        double radius;
public:
        Circle(double r) : radius(r){ }
        double area() { return pow(radius,2)*3.14159;
        }
};

class Cylinder{
        Circle base;
        double height;  
public: 
        Cylinder (double r, double h) : base(r), height(h){ } //constructor
        double volume(){
            return base.area() * height;
        }
};

int main (){
        Cylinder a(10,20);

        cout << "a's Volume is: "<< a.volume();
        cout << endl;
        return 0;
}
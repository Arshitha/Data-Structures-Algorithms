#include <iostream>
#include <string>
using namespace std;

class Square;

class Rectangle{
    int width, height;
public:
    int area(){ return width*height;}
    void convert(Square a);
};

class Square{
    friend class Rectangle;
private:
    int side;
public:
    Square (int a): side(a){}
};

void Rectangle::convert(Square a){
    width=a.side;
    height=a.side;
}

int main(){
    Square sqr(5);
    Rectangle rect;
    rect.convert(sqr);
    cout<< "area of the square is "<< rect.area()<<endl;
    return 0;
}
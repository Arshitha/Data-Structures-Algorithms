//example of a destructor
#include <iostream>
#include <string>
using namespace std;

class Example4{
private:
    string *ptr;
public:
    Example4() : ptr(new string) {} //default constructor
    Example4 (const string& str): ptr(new string(str)){} //constructor

    ~Example4(){delete ptr;} //destructor

    const string& content() const {return *ptr;} 
};

int main(){
    Example4 foo;
    Example4 bar("whats up");

    cout << "contents of bar: "<< bar.content()<<endl;

    return 0;
}
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){
    string item;
    //string *p;
    item = "abced";
    int size = item.size();
    bool bitStr[size*8];
    int a;
    int res;
    //p = &item;
    //bool bitStr;

    //printing each char of the string
    for (int i=0; i<item.size(); i++){
        cout<< item[i] << "\t";
    }
    cout<<endl;
    //converting to int
    a = (int)'s';
    cout << a << endl;
    //apply hash function
    // x mod 7
    res = a % 7;
    cout << res << endl;

    //initialising bitstr
    for (int j=0; j<(size*8); j++){
        bitStr[j] = 0;
        cout << bitStr[j];
    }
    cout << endl;
    /*int a = stoi(*(p+2));
    cout << a<< endl;*/
    return 0;

}
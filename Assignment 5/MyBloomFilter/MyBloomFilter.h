#include "BloomFilter.h"
#include <vector>
#include <iostream>


using namespace std;


#ifndef MyBloomFilter_h
#define MyBloomFilter_h

class MyBloomFilter:public BloomFilter{
public:

    MyBloomFilter(int len);
    void insert(string item);
    bool exists(string item); 
    int hashFn1(string item);
    int hashFn2(string item);
    //int hashFn3(string item);
    
    vector<int> FilterArr;
    string output();
    
private:
    //int size;
    //size = length *8;
    //int FilterArr[length*8];

};
#endif
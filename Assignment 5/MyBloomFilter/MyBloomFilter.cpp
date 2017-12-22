//#include "BloomFilter.h"
#include "MyBloomFilter.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>

MyBloomFilter::MyBloomFilter(int len) : BloomFilter(len){
    
    FilterArr.assign(length*8, 0);
}

void MyBloomFilter::insert(string item){
    int index1 = 0;
    int index2 = 0;
    //int index3 = 0;
    //cout << item << " hashed to " << hashFn1(item) << endl;

    index1 = hashFn1(item);
    index2 = hashFn2(item);
    //index3 = hashFn3(item);
    
    FilterArr[index1] = 1;
    FilterArr[index2] = 1;
    //FilterArr[index3] = 1;
    

}

bool MyBloomFilter::exists(string item){
    int index1;
    int index2;
    //int index3;

    index1 = hashFn1(item);
    index2 = hashFn2(item);
    //index3 = hashFn3(item);

    //cout << item << " hashed to " << hashFn1(item) << endl;
    
    if (FilterArr[index1] == 1 && FilterArr[index2]==1 /*&& FilterArr[index3]==1*/){
        return true;
    }
    else 
        return false;
}

string MyBloomFilter::output(){
    int i;
    string out="";
    string temp;
    
    for(i=0; i<(length*8); i++){
        temp = to_string(FilterArr[i]);
        out.append(temp);
    }
    cout << endl;
    return out;

}


int MyBloomFilter::hashFn1(string item){
    int m=18593;
    int p = length *8;
    int sizeStr = item.size(); 
    int resHashFn1 = item[0];

    for (int k=0; k<sizeStr; k++){
        resHashFn1 = ((resHashFn1*256) + item[k]) % m;    
    }
    return (resHashFn1%p);

}

int MyBloomFilter::hashFn2(string item){
    int m=125639;
    int p = length *8;
    int sizeStr = item.size(); 
    int resHashFn2 = item[0];

    for (int k=0; k<sizeStr; k++){
        resHashFn2 = ((resHashFn2*256) + item[k]) % m;    
    }
    return (resHashFn2%p);

}

/*int MyBloomFilter::hashFn3(string item){
    int m=1693;
    int p = length *8;
    int sizeStr = item.size(); 
    int resHashFn3 = item[0];

    for (int k=0; k<sizeStr; k++){
        resHashFn3 = ((resHashFn3*256) + item[k]) % m;    
    }
    return (resHashFn3%p);
}*/
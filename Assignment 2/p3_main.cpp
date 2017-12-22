#include <iostream>
#include <vector>
#include <array>

using namespace std;

#include "Problem3.cpp"

typedef vector<int> NumVec;

int main(){
	NumVec num;
	int len;
	
	cout << "Enter length of your integer vector:"<<endl;
	cin >> len;
	
	num.assign(len,0);                                //initialization of the vector
	
	int* p = num.data();                              //accessing the array through a pointer
													  //.data returns a pointer to the first element of the vector
	cout << "Enter the integers line by line:\n";
	for (int i=0; i<len; i++)
		cin >> num[i];
	MaxIncSeq (p,len);
	return 0;
}


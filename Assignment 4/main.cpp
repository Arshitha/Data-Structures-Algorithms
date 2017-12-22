//Submitted by Arshitha Basavaraj arshitha@bu.edu

/* This program runs in O(nlog n). 
** The function missingNum takes the maximum no. of bits to represent n and n itself as arguments.
** Maximum no. of bits required to represent n is equal to log n (base 2). 
** Within the missingNum function there are two for loops. The first for loop runs log n (base 2 ) times.
** The second for loop runs n times. 
** Therefore, the time complexity of this program is O(nlog n).
** Comments in the program will describe the logic.
*/

#include <iostream>
#include "InputArray.h"
#include "InputArray.cpp"
#include <cmath>

int missingNum(int, int);

InputArray arrayIn;

int main(){
    
    //variable declarations
    int n;
    int NumBits;
    int miss;
    
    //extracting from InputArray type object
    n = arrayIn.n;

    //finding the max. no. of bits
    NumBits = floor(log2 (double(n))) + 1;
    
    //calling the missing number function
    miss = missingNum(n, NumBits);

    //prints the missing number in the array
    cout << miss << endl;       
}

int missingNum(int n, int NumBits){
    int temp[NumBits];
    
    for (int j=0; j<NumBits; j++){        
        int count1 = 0;    
        for (int i=0; i<n; i++){
            if (arrayIn.findBit(i,j) == 1)
                count1++;
            }
            
            if (count1 == (2 * (NumBits-1)))
                temp[j] = 0;

            else
                temp[j] = 1;
        }
        
        //converts binary string to integer
        int x = 0;
        for (int k=NumBits - 1; k>=0; k--){
            if (temp[k] == 1)
                x = x +  pow(2,k);
            else 
                x = x + 0;
        }

    return x;
}
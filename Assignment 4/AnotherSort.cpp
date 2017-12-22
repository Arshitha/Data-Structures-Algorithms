#include <iostream>
#include <cmath>
#include <array>

using namespace std;

int main(){
    //int n = 10;
    int A[] = {78, 564, 6, 5, 4, 1, 90, 5, 6,0, 11, 120, 1827, 54645, -9};
    int n = 15;
    int tmp;
    int i, j, k;

    for (k = floor(n/2); k>0; k /=2){
        for (i = k; i<n; i++){
            tmp = A[i];
            for (j=i; j >=k && A[j-k]>tmp; j -=k)
                A[j] =A[j-k];
            A[j] = tmp;

        }
    }
    
    for (int p=0; p < n; p++)
        cout << A[p] << " ";
    cout << "\n";

}
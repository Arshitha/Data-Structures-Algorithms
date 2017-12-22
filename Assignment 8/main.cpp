#include <iostream>
#include <string>

using namespace std;

// Given two sequences A and B, finds the longest sequence C such that
// C is a subsequence (not necessarily contiguous) of both A and B
string findMaxSubSeq(string str1, string str2)
{
	//length of str1 and str2 respectively
    int m = str1.length();
    int n = str2.length();

    //declare a 2D array to count the max
    int L[m+1][n+1];
    
    // the maximum common subsequence
	string subseq;

    //creates a L[m+1][n+1] table to keep track of common characters
    for(int i=0; i<=m; i++){
        for (int j=0; j<=n; j++){
            if( i==0 || j==0)
                L[i][j] = 0;
            
            else if(str1[i-1] == str2[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
            }
               
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);

        }
    }

    //stores the subsequence chars in a string variable
    while(L[m][n] != 0){
        if(str1[m-1] == str2[n-1]){
            subseq += str1[m-1];
            m = m-1;
            n = n-1;
        }
        else{
            if (L[m-1][n] > L[m][n-1])
                m = m-1;
            else
                n = n-1;
        }

    }
    
    //reverses the subseq string
    subseq = string ( subseq.rbegin(), subseq.rend() );

	return subseq;
}

// (sample) main to test findMaxSubSeq
// The actual test cases may be different, this file is for demonstration of format only
int main(int argc, char const *argv[])
{
	// example sequences A, B
	string a;
	string b;

    if (argc < 3 || argc >3){
        return -1;
    }
    else{
        a = argv[1];
        b = argv[2];
    }

	// maximum subsequence in example sequences
	string maxSubSeq = findMaxSubSeq(a, b);

	cout << "Maximum common subsequence for " << a << " and " << b << " : " << maxSubSeq << endl;

	return 0;
}

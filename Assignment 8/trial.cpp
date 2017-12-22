#include <iostream>
#include <string>

using namespace std;
  
int max(int a, int b);
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
string lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
    
        cout << L[i][j];
        cout << " ";

    }
     printf("\n");
   }
   int length=L[i][j];

   char result[length];


   while(L[m][n] != 0){
       if(X[m] == Y[n]){
           result[length-1] = X[m];
           m = m-1;
           n = n-1;
           length = length + 1;
       }
       else {
           if (L[m-1][n] > L[n][m-1]){
               m = m-1;
               n = n;
           }
           else{
               m = m;
               n = n -1;
           }
           
       }

   }


   
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return result;
}
  
/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}
  
/* Driver program to test above function */
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  
  int m = strlen(X);
  int n = strlen(Y);
  
  printf("Length of LCS is %s \n", lcs( X, Y, m, n ) );
 
  return 0;
}




// int main(){
//     int m =5;
//     int n = 6;

//     for (int i=0; i<m; i++ ){
//         for(int j=0; j<n; j++){
//             cout << i << j;
//             cout << " ";
//         }

//         cout << "\n";
//     }

//     return 0;
// }
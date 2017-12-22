//Written by Arshitha Basavaraj (arshitha@bu.edu)
#include <iostream>

using namespace std;

int main(){
	
	const int ROWS=12;
	const int COLUMNS=12;
	int i,j;
	int n;
	
	char array1[ROWS+1][COLUMNS+1];
	char array2[ROWS+1][COLUMNS+1];
	
	cout << "Enter an integer between 0 to 7\n";
	cin >> n;
	
	// assigning values to the 2D array
	for (i=0; i<=ROWS; i++)
		for (j=0; j<=COLUMNS; j++)
			array2[i][j]=' ';
	//assigning 0's
	if ((n%2)==0)
		array2[ROWS-(n+1)][n+1]='O';
	else {
		array2[ROWS-n][n+2]='O';
		array2[ROWS-n-2][n+2]='O';
	}
	
	//assigning X's
	i=ROWS;
	for (j=0; j<=n; j++){
		array2[i][j]='X';
		array2[i-1][j]='X';	
		i--;	
	}
	
	//printing out the grid
	for (i=0; i<=ROWS; i++){
		for (j=0; j<=COLUMNS; j++){
			array1[i][j]= '_';
			cout << array1[i][j]<< array2[i][j];
			cout << " "<<"|"<<" ";	
		}
		cout<<"\n";
		cout<<"\n";
	}
}
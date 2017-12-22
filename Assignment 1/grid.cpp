#include <iostream>

using namespace std;

int main(){
	
	const int ROWS=10;
	const int COLUMNS=10;
	int i,j;
	int n;
	
	char array1[ROWS][COLUMNS];
	char array2[ROWS][COLUMNS];
	
	cout << "Enter an integer between 0 to 7\n";
	cin >> n;
	
	// assigning values to the 2D array
	for (i=ROWS; i>=1; i--)
		for (j=1; j<=COLUMNS; j++)
			array2[i][j]=' ';
	//assigning 0's
	if ((n%2)==0)
		array2[n+1][n+2]='O';
	else {
		array2[ROWS-(n+2)][n+3]='O';
		array2[ROWS-n][n+3]='O';
	}
	
	//assigning X's
	i=ROWS;
	for (j=1; j<=(n+1); j++){
		array2[i][j]='X';
		array2[i-1][j]='X';	
		i--;	
	}
	
	//printing out the grid
	cout << "GRID\n";
	for (i=1; i<=ROWS; i++){
		for (j=1; j<=COLUMNS; j++){
			array1[i][j]= '_';
			cout << array1[i][j]<< array2[i][j];
			cout << " "<<"|"<<" ";	
		}
		cout<<"\n";
		cout<<"\n";
	}
	
	return 0;
}
	
		
			
	
	
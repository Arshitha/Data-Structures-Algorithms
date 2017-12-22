//Written by Arshitha Basavaraj (arshitha@bu.edu)
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argCount, char **arguments) {
	string line;
    string longest_line;
    int line_num= 0;
    
    //creates an object and opens the file
    ifstream file;
    file.open(arguments[1]);   
	
	//checks for the longest line
	if(file.is_open()){
    for (line_num = 1 ; getline(file, line) ; line_num++) {
        if (line.length() > longest_line.length()) {
            longest_line.swap(line);
        }
    }
    }
    
    //prints out the longest line
    cout << longest_line << endl;
    file.close();
    return 0;    
}
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include <string>

using namespace std;

int main(int argCount, char **arguments){
    char c;
    char buid[10];
    
    //creates an object and opens the file
    ifstream file;
    file.open(arguments[1]);   
    
    int sum = 0;
    //cout << "before first for loop" << endl;

    int counter =0;
    int idTotal = 0;

    /*for (int k =0; k<10; k++){
        buid[i] = '0';
    }*/

    if(file.is_open()){
        while(((c=file.get()) != EOF)){
            if (c=='u'|| c=='U'){
                counter=1;
                //cout << "counter initial val " << counter << endl;
                buid[counter-1] =c;
                sum = 0;

            }
            else if ((buid[0]=='u' || buid[0] =='U') && isdigit(c) && (counter>=1 && counter<10)){
                counter++;
                //cout << "counter val " << counter << endl;
                //cout << "Digit " << counter-1 << "is ";
                //cout << c << endl;
                sum = sum + (int)(c-'0'); 
                //cout << "checking sum " << sum << endl;  
                buid[counter-1] = c; 
                //cout << "counter val " << counter << endl;
            }
            
            if ((counter == 9) && (isdigit(c)) && c!=' ' && c!='\n'){

                
                counter++;
                    
                cout << "counter val " << counter << endl;
                cout << "val of the !isdigit(c) function " << (isdigit(c)) << endl;
                //cout << "the non digit char at " << counter-1 <<" is " << c << endl;
                
                buid[counter-1] = c;
                
            }

            if ((counter==10) && (sum >= 31 && sum <= 68)){

                for (int i=0; i<10; i++){
                    cout << buid[i];
                }
                //cout << " checking sum " << sum << endl; 
                cout << endl;
                idTotal++;
                sum = 0;
            }    
        }
       
    }

    cout << "Total Number of BU IDs found are " << idTotal << endl;

    file.close();
    return 0;

}

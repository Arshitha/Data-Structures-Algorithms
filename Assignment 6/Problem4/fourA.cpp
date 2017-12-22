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
    file.open("BigData.txt");
    //file.open(arguments[1]);   
    
    int sum = 0;

    int counter =0;
    int idTotal = 0;

    if(file.is_open()){
        while(((c=file.get()) != EOF)){
            
            if (c=='U'){
                counter=1;
                //cout << "counter initial val " << counter << endl;
                buid[counter-1] =c;
                //buid[8] = '*';
                sum = 0;

            }
            else if ((buid[0] =='U') && isdigit(c) && (counter>=1 && counter<9)){
                counter++;
                //cout << "counter val is " << counter << endl;
                //cout << "Digit " << counter-1 << " is ";
                //cout << c << endl;
                sum = sum + (int)(c-'0'); 
                //cout << "checking sum " << sum << endl;  
                buid[counter-1] = c; 
                //cout << "buid[counter - 1] is " << buid[counter-1] << endl;
            }

            else if ((buid[0] =='U') && (counter>=1 && counter<9) && ((isdigit(c) != 1)  || c == ' ' || c=='\n')){
                counter = 0;
                sum =0;
                //uid[8] ='*';
            }

            /*if (counter==9){
                //cout << c << "this is the char when counter is 9" << endl;
            }*/
            
            if ((counter == 9) && (isdigit(c) != 1) && (c!=' ') && (c!='\n')){
                
                counter++;
                    
                //cout << "counter val " << counter << endl;
                //cout << "counter val " << counter << endl;
                //cout << "val of the isdigit(c) function is " << (isdigit(c)) << endl;
                //cout << "the non digit char at " << counter-1 <<" is " << c << endl;
                
                buid[counter-1] = c;
                
            }
            /*else if (isdigit(buid[8]) && ((isdigit(c) == 1) || (c==' ') || (c=='\n'))){
                cout << "this is here" <<endl;
                counter = 0;
                sum =0;
            }*/

            if ((counter==10) && (sum >= 31 && sum <= 68)){

                for (int i=0; i<10; i++){
                    cout << buid[i];
                }
                //cout << " checking sum " << sum << endl; 
                //cout << " " << sum << endl;
                idTotal++;
                sum = 0;
            }    
        }
       
    }

    cout << "Total Number of BU IDs found are " << idTotal << endl;

    file.close();
    return 0;

}

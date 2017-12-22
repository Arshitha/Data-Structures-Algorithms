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
    //int i = 0;
    //string str;
    int sum = 0;
    //c = getchar();
    cout << "before first for loop" << endl;

    //str = arguments[1];
    //cout << str <<endl;
    
    //ifstream is(str);     // open file


   /* while((c=is.get(str)) != EOF){
        for (i =0; i<10; i++){
            
            cout << "here" << endl;
            buid[i] = c;
        }

    }*/
    int counter =0;

    if(file.is_open()){
        while(((c=file.get()) != EOF)){
            if (c=='u'|| c=='U'){
                counter=1;
                //cout << "counter initial val " << counter << endl;
                buid[counter-1] =c;

            }
            if ((buid[0]=='u' || buid[0] =='U') && isdigit(c) && (counter>=1 && counter<10)){
                counter++;
                //cout << "counter val " << counter << endl;
                cout << c << endl;
                sum = sum + (int)(c-'0'); 
                //cout << "checking sum " << sum << endl;  
                buid[counter-1] = c; 
            }
            if (counter == 9){
                counter++;
                if (!isdigit(c)){

                    //cout << "counter val " << counter << endl;
                    cout << "the non digit char at " << counter-1<<" is " << c << endl;
                    
                    buid[counter-1] = c;
                    
                }
            }
            if (sum >= 31 && sum <= 68){

                for (int i=0; i<10; i++){
                    cout << buid[i];
                }
                cout << " checking sum " << sum << endl; 
                cout << endl;
                sum = 0;
            }    
        }
        /*for (i =0; i<10; i++){
            c = file.get();
            //cout << "here" << endl;
            buid[i] = c;    
        }
    
        for (i=0; i<10; i++){
            cout << buid[i];
            //cout << "next character in the file is " << getchar() << endl;
        }*/

    }

    file.close();
    return 0;
    
    












	//checks for the longest line
	/*if(file.is_open()){ 
        while(i <=9 && ((c=getchar())!= EOF)){
            if (i == 0){
                buid[i] = c;
                cout << "buid[0] is "<< buid[0] <<endl;
            }
            if (buid[0]=='u' || buid[0] == 'U'){
                cout << "inside the second if "<<endl;
                
                for (int j = 1; j<9; j++){
                    buid[j] = getchar();
                    if(isdigit(buid[j])){
                        sum = sum + buid[j];
                        continue;
                    }
                    else if (buid[j]=='u' || buid[j] == 'U'){
                        buid[0] = buid[j];
                        i=0;
                        break;
                    }
                    else{
                        buid[0] = '0';
                        buid[j] = '0';
                        break;
                    }
                    
                    if (!isdigit(buid[9])){
                        continue;
                    }
                    else{
                        buid[9] = '0';
                    }
                    if (sum>=31 && sum<=68){
                        cout << "BU-ID:" << endl;
                        for (int k=0; k<10; k++){
                            cout << buid[k];
                        }
                        cout << endl;
                    }
                    
                    
                }
            }
            if (i>9){
                i=0;
            }
            else{
                i++;
            }
        }
        
    }

    int a;
    string alpha;
    int i;

    a = 'a';
    alpha = "u27704208&";
    for (i=0; i<=9; i++){

        if (isdigit(alpha[i])){
            cout << "alpha[%d] is a digit" << i << endl;
        }
    }

    cout << alpha << endl;*/






}

/* 
Create an array of size 10. 
Once you find a U/u save it and the 9 following characters in the array. 
check if all the 8 characters after u are digits. 
If even one of those isn't a digit, then discard and reinitialise the array with zeros,break
and continue searching after the 9 characters. 
{nope. what if one of those characters is a U, I'll have to start from there}
else if the following 8 are digits then check if the last char is non digit. 
Then find the sum. 


u u u 567 u 
u&yi[]
*/
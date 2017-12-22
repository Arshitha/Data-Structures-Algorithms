// extract to string
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main (int argCount, char **arguments)
{
  
  string line, temp;
  int i,j=0,k;
  
  ifstream myfile (arguments[1]);
  
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      j++;
    }
    string line1[j];
    
    for (i=0; i<j; i++)
    {
    	getline (myfile,line) ;
   		line1[i]=line;  
    }
    for (i=0; i<j-1; i++)
    	for (k=i+1; k<j; k++)
    	{
    		if (line[i].length() < line[k].length())
    		{
    			temp=line[i];
    			line[i]=line[k];
    			line[k]=temp;
    		}
    		
    	}
    	
    cout << getline(myfile,line[0])<<endl;
    		
    myfile.close();
  }

  else cout << "Unable to open file"; 
  
  return 0;
}

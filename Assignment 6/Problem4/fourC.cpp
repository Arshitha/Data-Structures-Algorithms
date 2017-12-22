#include <iostream>
#include <stdlib.h>
#include <string>
//#include <new> 

char *copyFile(char *file) {

    FILE    *inputFile;
    char    *buffer;
    long  sizeBytes;
     
    inputFile = fopen(file, "r");
     
    // returns size of the file in number of bytes
    fseek(inputFile, 0L, SEEK_END);
    sizeBytes = ftell(inputFile);
     
    // set the position indicator to the beginning of the file
    fseek(inputFile, 0L, SEEK_SET);    
     
    // allocating memory for the buffer to hold the text
    buffer = (char*)calloc(sizeBytes, sizeof(char)); 
     
    // copy all the text into the buffer
    fread(buffer, sizeof(char), sizeBytes, inputFile);
    fclose(inputFile);
     
    return buffer; 
}


char *substring(char *string, size_t start, size_t length) {
    
    int slength = strlen(string);
    if (string == 0 || slength == 0 || slength < start || slength < (start+length)) 
        return 0; 
    return strndup(string + start, length); 
}

typedef struct pair { int x; int y; } pair;

const char *spaces = " \t\r\n";

int spaceCheck(char s) {
    int i;
    for (i = 0; i < 4; i++) {
        if (spaces[i] == s) return 1;
    }
    return 0;    
}




pair longestPalindromeString(char *data) {

    int textLength = strlen(data);
    int maxStrLen  = 0;
    int maxlow  = 0;
    int maxhigh = 0;
    int low     = 0;
    int high    = 0;
    int i;
    int j;
    char current = ' ';
    char previous = ' ';
    pair res = { 0, 0 }; 

    for (i = 0; i < textLength; i++) {
        
        if (data[i] <= 'Z' && data[i] >= 'A') 
            data[i] += 32;         
        for (j = i; j < (i + 2) && j < textLength; j++) {

            low  = i; 
            high = j;

           
            while (data[low] == data[high]) {

                
                current = data[low];
                if (spaceCheck(current) && spaceCheck(previous)) 
                    break;

                
                if (high - low > maxStrLen) {
                    maxlow  = low;
                    maxhigh = high;
                    maxStrLen  = maxhigh - maxlow;
                }

                previous = current;

                if (low > 0) { 
                    low--; 
                } 
                else { 
                    break; 
                }

                if (high < (textLength - 1)) { 
                    high++; 
                } 
                else { 
                    break; 
                }
            }
        }

    }

    maxhigh++; 
    if (maxhigh > textLength) { maxhigh = textLength; }

    res.x = maxlow;
    res.y = maxhigh;

    return res;
}

int main(int argc, char *argv[]) {
    
        
    
        // copy whole file into memory
        char *data = copyFile("BigData.txt");
    
        // get start and end indices of longest found palindrome
        pair longest = longestPalindromeString(data);
        
        char *found = substring(data, longest.x, longest.y - longest.x);
    
        printf("%d %d\n", longest.x, longest.y);
        printf("%s\n", found);
    
        free(found);
        free(data);
    
        return 0;
}

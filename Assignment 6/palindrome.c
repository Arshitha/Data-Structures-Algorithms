#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Usage: ./pals war_and_peace.txt

char *readFile(char *filename) {

    FILE    *infile;
    char    *buffer;
    long    numbytes;
     
    infile = fopen(filename, "r");
    if (infile == NULL) return 0;
     
    // Get the number of bytes
    fseek(infile, 0L, SEEK_END);
    numbytes = ftell(infile);
     
    // reset the file position indicator to the beginning of the file
    fseek(infile, 0L, SEEK_SET);    
     
    // grab sufficient memory for the buffer to hold the text
    buffer = (char*)calloc(numbytes, sizeof(char)); 
    if (buffer == NULL) return 0;
     
    // copy all the text into the buffer
    fread(buffer, sizeof(char), numbytes, infile);
    fclose(infile);
     
    return buffer; 
}


char *substring(char *str, size_t begin, size_t len) {
    
    int slen = strlen(str);
    if (str == 0 || slen == 0 || slen < begin || slen < (begin+len)) 
        return 0; 
    return strndup(str + begin, len); 
}


typedef struct pair { int x; int y; } pair;


const char *spaces = " \t\r\n";


int isSpace(char b) {
    int i;
    for (i = 0; i < 4; i++) {
        if (spaces[i] == b) return 1;
    }
    return 0;    
}


pair longestPalindrome(char *text) {

    int textlen = strlen(text);
    int maxlen  = 0;
    int maxlow  = 0;
    int maxhigh = 0;
    int low     = 0;
    int high    = 0;
    int i;
    int j;
    char current = ' ';
    char previous = ' ';
    pair res = { 0, 0 }; 

    for (i = 0; i < textlen; i++) {

        
        if (text[i] <= 'Z' && text[i] >= 'A') 
            text[i] += 32; 


        for (j = i; j < (i + 2) && j < textlen; j++) {

            low  = i; 
            high = j;

            // while subregion is a valid palindrome
            while (text[low] == text[high]) {

                // discount multiple spaces
                current = text[low];
                if (isSpace(current) && isSpace(previous)) 
                    break;

                // if longest found, update
                if (high - low > maxlen) {
                    maxlow  = low;
                    maxhigh = high;
                    maxlen  = maxhigh - maxlow;
                }

                // update prev
                previous = current;

                // expand subregion indexes
                if (low > 0) { low--; } else { break; }
                if (high < (textlen - 1)) { high++; } else { break; }
            }
        }

    }

    maxhigh++; 
    if (maxhigh > textlen) { maxhigh = textlen; }

    res.x = maxlow;
    res.y = maxhigh;

    return res;
}


int main(int argc, char *argv[]) {

    if (argc < 2) return 0;

    // read whole file into memory
    char *text = readFile(argv[1]);

    // get start and end indices of longest found palindrome
    pair longest = longestPalindrome(text);
    
    char *found = substring(text, longest.x, longest.y - longest.x);

    printf("%d %d\n", longest.x, longest.y);
    printf("%s\n", found);

    free(found);
    free(text);

    return 0;
}
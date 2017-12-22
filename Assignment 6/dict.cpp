/*#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>

using namespace std;

class Node {
public:
    Node();                                         // default constructor
    Node(const T& data, Node<T>* next = nullptr);   // constructor
    T data;                                         // node data
    Node<T>* next;                                  // node next pointer
}; 




#endif*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct trie{
    int words;
    int prefixes;
    char edges[26];
    char *pEdges;
    //pEdges = edges;
};

trie initialize(trie vertex){
    vertex.words=0;
    vertex.prefixes = 0;
    vertex.pEdges = vertex.edges;
    for (int i=0; i<26; i++){
        *(vertex.pEdges+i) = (char)(i+65);
        cout << i << "initialising";   
    }
    cout << endl;
    return vertex;

}

int main(){
    int j;
    trie node;

    node = initialize(node);

    for(j=0; j<26; j++){
        cout << node.edges[j] << endl;
        cout << "trying to print" << endl;
    }
}


/*int main(int argCount, char **arguments){
    int counter =0;
    //int idTotal = 0;
    string line;
    string longest_line;
    int line_num= 0;

    ifstream file;
    file.open(arguments[1]);   
	
	//checks for the longest line
	if(file.is_open()){
        for (line_num = 1 ; getline(file, line) ; line_num++) {*/
            /*if (line.length() > longest_line.length()) {
                longest_line.swap(line);
            }*/
            /* if (line[0] == 'a' || line[0] == 'A'){
                //cout << "this is here "<< endl;    
                continue;
            }
            else {
                cout << "starting letter is " << line[0] << endl;
                counter++;
                
            }
        }

    }
    else{
        cout << "file is not open" << endl;
    }
    
    //prints out the longest line
    cout << counter << endl;
    file.close();

    return 0;

}*/
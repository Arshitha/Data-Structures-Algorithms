#include <iostream>
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

int main(int argc, char *argv[]){

    set<int> vertices;
    typedef set<int>::iterator it;

    int outVer;
    int inVer;
    
    typedef pair<int, int> directedEdge;
    set<directedEdge> edges;
    typedef set<directedEdge>::iterator it_1;       
    
    map<directedEdge, int> weights;
    // typedef map<directedEdge, int>::iterator it_2; 

    string line;
    // string longest_line;
    int line_num= 0;
    
    int i=0;
    int totalVer; 
    directedEdge newEdge;
    newEdge = make_pair(2,5);
    
    
    it iterator;
    it_1 iterator1;
    
    ifstream file;
    string tempStr;
    istringstream iss(tempStr);

    file.open(argv[1]);

    if(file.is_open()){
        
        for (line_num = 1 ; getline(file, line) ; line_num++) {
            
            i = 0;
            // cout << line << endl;
            istringstream iss(line);
            
            if (line_num == 1){
                
                while (iss >> tempStr && i<2) {
                    i++;
                    
                    // call the addVertex fucntion here
                    if (i==1){
                        totalVer = stoi(tempStr);
                        for (int n=0; n < totalVer; n++){
                            vertices.insert(n);                  
                        }

                    }
                    
                    //cout << tempStr << endl;    
                }

            }
            else{

                while (iss >> tempStr) {
                    
                    i++;

                    // add a new edge
                    if (i==1){
                        outVer = stoi(tempStr);
                        // cout << "OutVer is " << outVer << endl;  
                    }
                    else if (i==2){
                        inVer = stoi(tempStr);
                        edges.insert(make_pair(outVer, inVer));
                        // cout << "directed edge goes from vertex " << outVer << " to vertex " <<inVer <<endl;
                    }
                    else{
                        weights[make_pair(outVer, inVer)] = stoi(tempStr);
                        // cout << "weights are " << weights[make_pair(outVer, inVer)] << endl;
                    } 
                    
                    //cout << tempStr << endl;
                }

            }
        }
    }
    // for isEdge member function
    for(iterator1 = edges.begin(); iterator1 != edges.end(); iterator1++){
        if (newEdge.first == (*iterator1).first && newEdge.second ==(*iterator1).second){
            cout << "the edge exists " << endl;
            break;
        }
        else{
            continue;
        }

        // cout <<"( "<< (*iterator1).first << "," << (*iterator1).second<< " )" << " ";
        // cout << "Weight of the edge is " << weights[make_pair((*iterator1).first,(*iterator1).second)] << endl;
    }

    // getWeight function
    for(iterator1 = edges.begin(); iterator1 != edges.end(); iterator1++){
        if (newEdge.first == (*iterator1).first && newEdge.second ==(*iterator1).second){
            int wt;
            wt = weights[newEdge];

            cout << "the edge exists and it's weight is " << wt << endl;
            break;
        }
        else{
            continue;
        }

        // cout <<"( "<< (*iterator1).first << "," << (*iterator1).second<< " )" << " ";
        // cout << "Weight of the edge is " << weights[make_pair((*iterator1).first,(*iterator1).second)] << endl;
    }




    // this whole block will go into print()
    cout << "printing the stored veritices" << endl;
    for(iterator = vertices.begin(); iterator != vertices.end(); iterator++){
        cout << *iterator << " ";
    }
    cout << endl;
    
    cout << "printing the stored edges" << endl;
    for(iterator1 = edges.begin(); iterator1 != edges.end(); iterator1++){
        cout <<"( "<< (*iterator1).first << "," << (*iterator1).second<< " )" << " ";
        cout << "Weight of the edge is " << weights[make_pair((*iterator1).first,(*iterator1).second)] << endl;
    }

    file.close();
    return 0;
}
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm> 

#include "Graph.h"

using namespace std;

int i=0;

Graph::Graph(){

}

int Graph::addVertex(){
    int newVertex = getNumVertices();

    vertices.insert(newVertex);

    return newVertex;
}

void Graph::addEdge(directedEdge newEdge, int weight){
    bool checkVer1;
    bool checkVer2; 

    checkVer1 = vertices.find(newEdge.first) != vertices.end();
    checkVer2 = vertices.find(newEdge.second) != vertices.end();
    if(checkVer1 == true && checkVer2 == true){
        edges.insert(make_pair(newEdge.first, newEdge.second));
        weights[make_pair(newEdge.first, newEdge.second)] = weight;
    }
}

int Graph::getNumVertices(){
    int size;
    size = vertices.size();

    return size;
}

int Graph::getWeight(directedEdge edge){
    int weight;

    weight = weights[make_pair(edge.first, edge.second)];
    return weight;
}

bool Graph::isEdge(directedEdge newEdge){
    bool checkEdge;
    
    checkEdge = edges.find(newEdge) != edges.end();

    return checkEdge;
}

void Graph::print(){
    typedef set<int>::iterator it;
    it iterator;

    typedef set<directedEdge>::iterator it_1;
    it_1 iterator1;

    for(iterator = vertices.begin(); iterator != vertices.end(); iterator++){
        cout << *iterator << ": ";
        for(iterator1 = edges.begin(); iterator1 != edges.end(); iterator1++){
            if(*iterator == (*iterator1).first){
                cout << (*iterator1).second << " ";
                cout << "(" << weights[make_pair((*iterator1).first,(*iterator1).second)] << ")";
                cout << " ";
            }
        }
        cout << endl;
    }
}

void Graph::generateGraph(string fileName){
    ifstream file;
    string tempStr;
    istringstream iss(tempStr);

    string line;
    int line_num= 0;

    int totalVer;

    directedEdge newEdge;
    
    file.open(fileName);
    if(file.is_open()){
    
        for (line_num = 1 ; getline(file, line) ; line_num++) {
            i = 0;
            
            istringstream iss(line);
        
            if (line_num == 1){
                while (iss >> tempStr && i<2) {
                    i++;
                    
                    if (i==1){
                        totalVer = stoi(tempStr);
                        for (int n=0; n < totalVer; n++){
                            addVertex();                  
                        }
                    }
                        
                }
            }
            else{
                while (iss >> tempStr) {
                    i++;
                    
                    if (i==1){
                        newEdge.first = stoi(tempStr);  
                    }
                    else if (i==2){
                        newEdge.second = stoi(tempStr);
                    }
                    else{
                        int newWeight;
                        newWeight = stoi(tempStr);
                        addEdge(newEdge, newWeight);
                    } 
                }
            }
        }
    }

}

void Graph::modifiedDijkstra(int source){
    vector<int> dist;
    // int dist[getNumVertices()];
    vector<int> tempDist;
    map<int,int>::iterator it_2;
    
    set<int> sptSet;

    vector <int> sptCountVec;
    
    typedef set<int>::iterator it;
    it iterator;

    typedef set<directedEdge>::iterator it_1;
    it_1 iterator1;

    int INF = numeric_limits<int>::max();
    
    int currVertex;
    int min;

    dist.assign(getNumVertices(), INF);
    tempDist.assign(getNumVertices(), INF);
    sptCountVec.assign(getNumVertices(),0);


    dist[source] = 0;
    tempDist[source] = 0;

    while(!tempDist.empty()){
        
        min = *min_element(begin(tempDist), end(tempDist));
        
        for(int i=0; i < dist.size(); i++){
            if(min == dist[i]){
                currVertex = i;
            }
        }
        
        bool exist = sptSet.find(currVertex) != sptSet.end();

        //cout << "min is " << min << " and currVertex is " << currVertex << endl;
        
        for(iterator1 = edges.begin(); iterator1 != edges.end(); iterator1++){
            if(currVertex == (*iterator1).first && exist == false){
                //cout << "this is the edge " << (*iterator1).first << "," << (*iterator1).second << endl;
                if(dist[(*iterator1).second] > (dist[currVertex] + weights[make_pair((*iterator1).first,(*iterator1).second)])){
                    dist[(*iterator1).second] = (dist[currVertex] + weights[make_pair((*iterator1).first,(*iterator1).second)]);
                    sptCountVec[(*iterator1).second] += 1;
                    //tempDist.erase(tempDist.begin()+(*iterator1).second);
                    tempDist.push_back(dist[(*iterator1).second]);                    
                    
                    //cout << "dist of " << (*iterator1).second << " is " << tempDist[(*iterator1).second] << endl;
                }
                else if(dist[(*iterator1).second] == (dist[currVertex] + weights[make_pair((*iterator1).first,(*iterator1).second)])){
                    sptCountVec[(*iterator1).second] += 1;
                }
    
            }
        }
        sptSet.insert(currVertex);
        //cout << "min outside for loop " << min << endl;
        tempDist.erase(remove(tempDist.begin(), tempDist.end(), min), tempDist.end());

        //cout << "size of tempDist is " <<tempDist.size() << endl;
    }

    //printing
    cout << endl;
    cout << "Shortest paths from node " << source << ":" << endl;
    for (int i=0; i < getNumVertices(); i++){
        if(i != source){
            cout << "Distance to vertex " << i << " is " << dist[i] << " ";
            cout << "and there are " << sptCountVec[i] << " shortest paths" << endl;
        }        
    }

}
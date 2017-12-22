//Submitted by Arshitha Basavaraj arshitha@bu.edu
#ifndef Problem3a_h
#define Problem3a_h

#include <iostream>

using namespace std;

template <class T = int>
class Node {
public:
    Node();                                         // default constructor
    Node(const T& data, Node<T>* next = nullptr);   // constructor
    T data;                                         // node data
    Node<T>* next;                                  // node next pointer
};

template <class T = int>
class LinkedList {
public:
    LinkedList();                                   // constructor
    ~LinkedList();                                  // destructor
    T deleteFromHead() throw (runtime_error);       // removes and returns content of head
    T deleteFromTail() throw (runtime_error);       // removes and returns content of tail
    void deleteNode(T data) throw (runtime_error);  // removes node with specified data
    void InsertToHead(T data);                      // insert node with data at the head
    void InsertToTail(T data);                      // insert node with data at the tail
    int getSize();                                  // returns size of linked list
    void print();                                   // prints linked list
private:
    Node<T>* head;                                  // head of linked list
};


/******* From here down is the content of the LinkedList.cpp file: ***********************/

 /* Implementation of Node */

 // default constructor
 template<class T>
 Node<T>::Node()
 {
 }
 
 // constructor
 template<class T>
 Node<T>::Node(const T& data, Node<T>* next)
 {
     this->data = data;
     this->next = next;
 }
 
 /* Implementation of linked list */

 // constructor
 template <class T>
 LinkedList<T>::LinkedList()
 {
     head = nullptr;
 }

 // destructor
 template <class T>
 LinkedList<T>::~LinkedList()
 {
    Node<T> *temp = nullptr;
    if (head != nullptr) {
        while(head->next != 0){
            temp = head;
            delete head;
            head=temp->next;
        }
    }
    delete temp;        
 }

 template <class T>
 T LinkedList<T>::deleteFromHead() throw (runtime_error)
 {
    T element;

    if (head == nullptr)
        cout<<"List is empty "<<endl;

    else{
        Node<T> *currNode = head;
        element = head->data;
        head = head->next;
        delete currNode;
    } 
    
    return element;
 }

 template <class T>
 T LinkedList<T>::deleteFromTail() throw (runtime_error)
 {
    T element;
    
    if (head == nullptr)
        cout << "The list is empty "<< endl;

    else if (head->next == nullptr)
    {
        element = head->data;
        delete head;
        head=nullptr;
    }
    else 
    {
        Node<T>* currNode = head;
        Node<T>* prevNode = nullptr;
    
        
        while (currNode->next != nullptr)
        {  
            prevNode = currNode;
            currNode = currNode->next;
        }
        
        element = currNode->data;
        prevNode->next = nullptr;
        delete currNode;                  
    }   
    return element;
 }
 

 template <class T>
 void LinkedList<T>::deleteNode(T data) throw (runtime_error)
 {
    if (head == nullptr)
        cout<<"Linked list is empty"<<endl;
    else
    {
        Node<T>* currNode = head;
        Node<T>* prevNode = nullptr;

        while(currNode != nullptr){
            if (currNode->data == data)
                break;
            else{
                prevNode = currNode;
                currNode = currNode->next;
            }
        }
        
        if (head == currNode){
            head = head->next;
            delete currNode;
        }
        else{
            prevNode->next = currNode->next;
            delete currNode; 
        }    
    }
 }
 

 template <class T>
 void LinkedList<T>::InsertToHead(T data)
 {
     Node<T> * newNode = new Node<T>(data, nullptr);
     
     if (head == nullptr)
         head = newNode;
     else
     {
         newNode->next = head;
         head = newNode;
     }
 }


 template <class T>
 void LinkedList<T>::InsertToTail(T data)
 {
    Node<T> * newNode = new Node<T>(data, nullptr);
    
    if (head == nullptr)                         
        head = newNode;                         
    
    else 
    {
        Node<T>* currNode = head;
        while(currNode->next != nullptr)
        {                                        
            currNode = currNode->next;           
        }
        
        currNode->next = newNode;                
    }
}


 template <class T>
 int LinkedList<T>::getSize()
 {
    int size = 0;
    if (head == nullptr)
    {
        size = 0;
        return size;
    }     
    else
    {
        Node<T>* currNode = head;
        while(currNode->next != nullptr)
        {                                 
            currNode = currNode->next;   
            size++;                          
        }
        return size+1;
    }
 }

 template <class T>
 void LinkedList<T>::print()
 {
     if (head == nullptr)
     {
         cout << "Linked list is empty" << endl;;
         return;
     }
     
     cout << head->data << " ";
     
     if (head->next == nullptr)
     {
         cout << endl;
         return;
     }
 
     Node<T>* currNode = head->next;
     Node<T>* prevNode = head;
 
     
     while (currNode->next != nullptr)
     {  
         cout << currNode->data << " ";
         prevNode = currNode;
         currNode = currNode->next;
     }
 
     cout << currNode->data << endl;
     return;
 }
     
     
#endif /* LinkedList_h */

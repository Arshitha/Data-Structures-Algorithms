//Submitted by Arshitha Basavaraj arshitha@bu.edu
#ifndef StackTest_h
#define StackTest_h

#include <iostream>
#include "ListTest.h"

using namespace std;

template <class T = int>
class StackFromList {
public:
    StackFromList();                                   // constructor
    ~StackFromList();                                  // destructor
    T pop() throw (runtime_error);       // removes and returns content of head
    void push(T data);  
    bool isEmpty();                    // insert node with data at the head
private:
    Node<T>* top;                                  // head of linked list
};

 /*Implementation of linked list */

 // constructor
 template <class T>
 StackFromList<T>::StackFromList()
 {
     top = nullptr;
 }

 // destructor
 /***template <class T>
 LinkedList<T>::~LinkedList()
 {
    //to be implemented 
 }
*/
 template <class T>
 T StackFromList<T>::pop() throw (runtime_error)
 {
    T element=0;

    if (top == nullptr)
        cout<<"Stack is empty "<<endl;

    else{
        Node<T> *currNode = top;
        element = top->data;
        top = top->next;
        delete currNode;
    } 
    
    return element;
 }


 template <class T>
 void StackFromList<T>::push(T data)
 {
     Node<T> * newNode = new Node<T>(data, nullptr);
     
     if (top == nullptr)
         top = newNode;
     else
     {
         newNode->next = top;
         top = newNode;
     }
 }

 template <class T>
 bool StackFromList<T>::isEmpty()
 {
     if (top == nullptr)
        return true;
    else 
        return false;
 }
#endif /* LinkedList_h */

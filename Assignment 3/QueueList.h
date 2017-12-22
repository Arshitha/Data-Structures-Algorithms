//Submitted by Arshitha Basavaraj arshitha@bu.edu
#ifndef Problem3c_h
#define Problem3c_h

#include <iostream>
#include "Problem3a.h"

using namespace std;

template <class T = int>
class QueueFromList {
public:
    QueueFromList();                                     // constructor
    //~QueueFromList();                                  // destructor
    T dequeue() throw (runtime_error);                   //removes the element from the front of the queue
    void enqueue(T data);  
    bool isEmpty();                    // insert node with data at the head
private:
    Node<T>* front; 
    Node<T>* rear;                               // head of linked list
};


 // constructor
 template <class T>
 QueueFromList<T>::QueueFromList()
 {
     front= nullptr;
     rear = nullptr;
 }

 // destructor
 /***template <class T>
 LinkedList<T>::~LinkedList()
 {
    //to be implemented 
 }
*/
 template <class T>
 T QueueFromList<T>::dequeue() throw (runtime_error)
 {

    T element = ' ';

    if (front == nullptr && rear == nullptr)
        cout<<"Queue is empty "<<endl;
    
    else if (front->next == nullptr && rear->next == nullptr){
        Node<T> *temp = front;
        element = front->data;
        delete temp;
        front = rear = nullptr;
    }
    else{
        Node<T> *temp = front;
        element = front->data;
        front = front->next;
        delete temp;
    }

    return element;   
 }


 template <class T>
 void QueueFromList<T>::enqueue(T data)
 {
     Node<T> * newNode = new Node<T>(data, nullptr);
     
     if (front == nullptr && rear == nullptr){
        front = rear = newNode;
     }

     else {
         rear->next = newNode;
         rear = newNode;
         rear->next = nullptr;
     }
}

 template <class T>
 bool QueueFromList<T>::isEmpty()
 {
     if (front == nullptr && rear == nullptr)
        return true;
    else 
        return false;
 }
#endif /* LinkedList_h */

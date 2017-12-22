//Submitted by Arshitha Basavaraj arshitha@bu.edu
#ifndef Problem3c_h
#define Problem3c_h

#include <iostream>
#include "Problem3a.h"

using namespace std;

template <class T = int>
class QueueFromList {
public:
    QueueFromList();                                    // default constructor
    ~QueueFromList();                                   // destructor
    T dequeue() throw (runtime_error);                  // deletes from tail of the queue
    void enqueue(T data);                               // inserts to the head of the queue
    bool isEmpty();                                     // checks if queue is empty
private:
    LinkedList<T> queue;                                // private member of the linked list
};


 // default constructor
 template <class T>
 QueueFromList<T>::QueueFromList()
 {}

 // destructor
 template <class T>
 QueueFromList<T>::~QueueFromList()
 {
     queue.~LinkedList();
 }

//dequeue function definition
 template <class T>
 T QueueFromList<T>::dequeue() throw (runtime_error)
 {
    T element;
    element = queue.deleteFromTail();
    return element;
    
 }

//enqueue function definition
 template <class T>
 void QueueFromList<T>::enqueue(T data)
 {
     queue.InsertToHead(data);
 }

//isEmpty function definition
 template <class T>
 bool QueueFromList<T>::isEmpty()
 {
    int size;
    size = queue.getSize();
     if (size == 0)
        return true;
    else 
        return false;
 }
 
#endif /* LinkedList_h */

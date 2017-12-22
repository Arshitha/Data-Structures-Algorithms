//Submitted by Arshitha Basavaraj arshitha@bu.edu
#ifndef Problem3b_h
#define Problem3b_h

#include <iostream>
#include "Problem3a.h"

using namespace std;

template <class T >
class StackFromList{
public:
    StackFromList();                                    // default constructor
    ~StackFromList();                                   // destructor
    T pop() throw (runtime_error);                      // removes from head
    void push(T data);                                  // inserts an element to head
    bool isEmpty();                                     // checks if stack is empty
private:
    LinkedList<T> stack;                                // private member of linked list
};

//default constructor
template <class T>
StackFromList<T>::StackFromList()
{}

//destructor
template <class T>
StackFromList<T>::~StackFromList(){
    stack.~LinkedList();
}

//pop function definition
 template <class T>
 T StackFromList<T>::pop() throw (runtime_error)
 {
    T element;
    element = stack.deleteFromHead();
    return element;
 }
 
 //push function definition
 template <class T>
 void StackFromList<T>::push(T data)
 {
    stack.InsertToHead(data);
 }

//isEmpty function definition
 template <class T>
 bool StackFromList<T>::isEmpty()
 {
    int size;
    size = stack.getSize();
     if (size == 0)
        return true;
    else 
        return false;
 }
 
#endif /* LinkedList_h */

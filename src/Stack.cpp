#include "../include/Stack.h"
// #include ".LinkedList.h"
#include <iostream>

// Checks if the linked stack is empty
bool LinkedStack::isEmpty() { 
  return this->linkedList.isEmpty(); 
}

// Adds data to the top of the linked stack
void LinkedStack::push(const int data) {
  this->linkedList.addToHead(data);
}

// Removes and returns the value stored at top
int LinkedStack::pop() {
    int data = this->linkedList.removeFromHead();
    return data;
}

// Returns the value stored at top
int LinkedStack::top() {
    int top = linkedList.getHeadInfo();
    return top;
}

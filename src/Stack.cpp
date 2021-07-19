#include "../include/Stack.h"
// #include ".LinkedList.h"
#include <iostream>

// Checks if the linked stack is empty
bool LinkedStack::isEmpty() { 
  return this->linkedList.isEmpty(); 
}

// Adds data to the top of the linked stack
void LinkedStack::push(const unsigned long long data) {
  this->linkedList.addToHead(data);
}

// Removes and returns the value stored at top
unsigned long long LinkedStack::pop() {
    unsigned long long data = this->linkedList.removeFromHead();
    return data;
}

// Returns the value stored at top
unsigned long long LinkedStack::top() {
    int top = linkedList.getHeadInfo();
    return top;
}

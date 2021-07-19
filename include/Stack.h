#pragma once
#include "LinkedList.h"

class Stack {

public:
  virtual ~Stack() {}
  virtual bool isEmpty() = 0;
  virtual void push(const unsigned long long data) = 0;
  virtual unsigned long long pop() = 0;
  virtual unsigned long long top() = 0;
};

class LinkedStack : public Stack {
private:
  // A LinkedList object
  LinkedList linkedList;

public:
  // Checks if the linked stack is empty
  virtual bool isEmpty();
  
  // Adds data to the top of the linked stack
  virtual void push(const unsigned long long data);

  // Removes and returns the value stored at top
  virtual unsigned long long pop();

  // Returns the value stored at top
  virtual unsigned long long top();

  // Destructor
  virtual ~LinkedStack() {}
};
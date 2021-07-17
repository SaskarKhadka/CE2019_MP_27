#pragma once
#include "LinkedList.h"

class Stack {

public:
  virtual ~Stack() {}
  virtual bool isEmpty() = 0;
  virtual void push(const int data) = 0;
  virtual int pop() = 0;
  virtual int top() = 0;
};

class LinkedStack : public Stack {
private:
  // A LinkedList object
  LinkedList linkedList;

public:
  // Checks if the linked stack is empty
  virtual bool isEmpty();
  
  // Adds data to the top of the linked stack
  virtual void push(const int data);

  // Removes and returns the value stored at top
  virtual int pop();

  // Returns the value stored at top
  virtual int top();

  // Destructor
  virtual ~LinkedStack() {}
};
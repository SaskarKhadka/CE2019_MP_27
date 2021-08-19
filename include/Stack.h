#pragma once
#include "LinkedList.h"
#include <iostream>


template <typename T> class Stack {

public:
  virtual ~Stack() {}
  virtual bool isEmpty() = 0;
  virtual void push(const T data) = 0;
  virtual T pop() = 0;
  virtual T top() = 0;
};

template <typename T> class LinkedStack : public Stack<T> {
private:
  // A LinkedList object
  LinkedList<T> linkedList;

public:
  // Checks if the linked stack is empty
  virtual bool isEmpty() { return this->linkedList.isEmpty(); }

  // Adds data to the top of the linked stack
  virtual void push(const T data) { this->linkedList.addToHead(data); }

  // Removes and returns the value stored at top
  virtual T pop() {
    T data = this->linkedList.removeFromHead();
    return data;
  }

  // Returns the value stored at top
  virtual T top() {
    T top = linkedList.getHeadInfo();
    return top;
  }

  // Destructor
  virtual ~LinkedStack() {}
};
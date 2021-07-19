#pragma once

class Node {
public:
  unsigned long long info;
  Node *next;

  // Initializes a node
  Node(unsigned long long info, Node *next) : info(info), next(next) {}
  Node() : next(nullptr) {}
};

class LinkedList {
private:
  // Node objects
  Node *HEAD;
  Node *TAIL;

public:
  // Initializes a LinkedList
  LinkedList(Node *head, Node *tail) : HEAD(head), TAIL(tail) {}
  LinkedList() : HEAD(nullptr), TAIL(nullptr) {}

  // Destructor
  ~LinkedList(){};

  // Returns the value stored at head
  unsigned long long getHeadInfo();

  // Returns the value stored at tail
  unsigned long long getTailInfo();

  // Checks if the list is empty or not
  bool isEmpty();

  // Adds data at the top(head) of list
  void addToHead(unsigned long long data);

  // Adds data at the bottom(tail) of list
  void addToTail(unsigned long long data);

  // Goes through every single elements(if present) of the list
  void traverse(char seperator = ' ');

  // Adds data next to the given predecessor
  void add(unsigned long long data, Node *predecessor);

  // Removes and returns data from the top(head)
  unsigned long long removeFromHead();

  // Removes and returns data from the bottom(tail)
  unsigned long long removeFromTail();

  // Removes the given data from the list
  void remove(unsigned long long data);

  // Searches if the given data exists in the list
  bool search(unsigned long long data);

  // Searches and returns the node which contains the given data
  Node *retrive(unsigned long long data, Node *dataOutPointer);
};

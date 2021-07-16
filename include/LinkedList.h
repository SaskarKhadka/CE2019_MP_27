#pragma once

class Node {
public:
  int info;
  Node *next;

  // Initializes a node
  Node(int info, Node *next) : info(info), next(next) {}
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
  int getHeadInfo();

  // Returns the value stored at tail
  int getTailInfo();

  // Checks if the list is empty or not
  bool isEmpty();

  // Adds data at the top(head) of list
  void addToHead(int data);

  // Adds data at the bottom(tail) of list
  void addToTail(int data);

  // Goes through every single elements(if present) of the list
  void traverse(char seperator = ' ');

  // Adds data next to the given predecessor
  void add(int data, Node *predecessor);

  // Removes and returns data from the top(head)
  int removeFromHead();

  // Removes and returns data from the bottom(tail)
  int removeFromTail();

  // Removes the given data from the list
  void remove(int data);

  // Searches if the given data exists in the list
  bool search(int data);

  // Searches and returns the node which contains the given data
  Node *retrive(int data, Node *dataOutPointer);
};

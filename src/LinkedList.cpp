#include "../include/LinkedList.h"
#include <iostream>

// Returns the value stored at head
unsigned long long LinkedList::getHeadInfo() {
  if (!isEmpty())
    return this->HEAD->info;
  else
    throw std::string("Your list is empty");
}

// Returns the value stored at tail
unsigned long long LinkedList::getTailInfo() {
  if (!isEmpty())
    return this->TAIL->info;
  else
    throw std::string("Your list is empty");
}

// Checks if the list is empty or not
bool LinkedList::isEmpty() { return this->HEAD == nullptr ? true : false; }

// Adds data at the top(head) of list
void LinkedList::addToHead(unsigned long long data) {
  Node *newNode = new Node();
  newNode->info = data;
  newNode->next = this->HEAD;
  this->HEAD = newNode;
  if (this->TAIL == nullptr) {
    this->TAIL = this->HEAD;
  }
  // std::cout << data << " was added to head" << std::endl;
}

// Adds data at the bottom(tail) of list
void LinkedList::addToTail(unsigned long long data) {
  Node *newNode = new Node();
  newNode->info = data;
  newNode->next = nullptr;
  if (isEmpty()) {
    this->TAIL = newNode;
    this->HEAD = this->TAIL;
  } else {
    TAIL->next = newNode;

    TAIL = newNode;
  }
  std::cout << data << " was added to tail" << std::endl;
}

// Goes through every single elements(if present) of the list
void LinkedList::traverse(char seperator) {
  if (!isEmpty()) {
    Node *temp = this->HEAD;
    while (temp != nullptr) {
      std::cout << temp->info << seperator;
      temp = temp->next;
    }
    std::cout << '\n';
  } else
    throw std::string("[Empty-List], Cannot traverse");
}

// Adds data next to the given predecessor
void LinkedList::add(unsigned long long data, Node *predecessor) {
  if (predecessor == TAIL)
    addToTail(data);
  else if (predecessor == nullptr)
    addToHead(data);
  else {
    Node *newNode = new Node();
    newNode->info = data;
    newNode->next = predecessor->next;
    predecessor->next = newNode;
  std::cout << data << " was added after " << predecessor->info << std::endl;
  }
}

// Removes and returns data from the top(head)
unsigned long long LinkedList::removeFromHead() {
  unsigned long long data;
  if (!isEmpty()) {
    Node *nodeToDelete = this->HEAD;
    data = nodeToDelete->info;
    this->HEAD = this->HEAD->next;

    if (this->HEAD == nullptr) {
      this->TAIL = nullptr;
    }

    delete nodeToDelete;

  } else {
    throw std::string("[Empty-List], Cannot remove from head");
  }
  // std::cout << data << " was removed from head" << std::endl;
  return data;
}

// Removes and returns data from the bottom(tail)
unsigned long long LinkedList::removeFromTail() {
  unsigned long long data;
  if (!isEmpty()) {
    Node *nodeToDelete = this->TAIL;
    data = nodeToDelete->info;
    if (this->HEAD == this->TAIL) {
      this->HEAD = nullptr;
      this->TAIL = nullptr;
    } else {
      Node *temp = this->HEAD;
      while (temp->next != this->TAIL) {
        temp = temp->next;
      }
      this->TAIL = temp;
      temp->next = nullptr;
    }
    delete nodeToDelete;
  } else
    throw std::string("[Empty-List], Cannot remove from tail");

  // std::cout << data << " was removed from tail" << std::endl;
  return data;
}

// Removes the given data from the list
void LinkedList::remove(unsigned long long data) {

  if (!isEmpty()) {

    if (this->HEAD->info == data) {
      this->removeFromHead();
    } else if (this->TAIL->info == data) {
      this->removeFromTail();
    }

    else {
      Node *temp = this->HEAD->next;
      Node *prev = this->HEAD;
      while (temp != nullptr && temp->info != data) {
        prev = prev->next;
        temp = temp->next;
      }
      if (temp != nullptr) {
        prev->next = temp->next;
        delete temp;
      } else
        throw std::string("Your list doesnot contain " + std::to_string(data));
    }
  } else
    throw std::string("[Empty-List], Cannot remove " + std::to_string(data));

  std::cout << data << " was removed" << std::endl;
}

// Searches if the given data exists in the list
bool LinkedList::search(unsigned long long data) {

  if (!isEmpty()) {
    Node *temp = this->HEAD;
    while (temp != nullptr && temp->info != data) {
      temp = temp->next;
    }
    if (temp == nullptr)
      return false;
    else
      return true;
  } else
    throw std::string("[Empty-List], Cannot search for" + std::to_string(data));
}

// Searches and returns the node which contains the given data
Node *LinkedList::retrive(unsigned long long data, Node *dataOutPointer) {

  if (!isEmpty()) {
    Node *temp = this->HEAD;
    while (temp != nullptr && temp->info != data) {
      temp = temp->next;
    }
    if (temp == nullptr)
      throw std::string("Your list doesnot contain" + std::to_string(data));
    else {
      *dataOutPointer = *temp;
      return temp;
    }
  } else
    throw std::string("[Empty-List], Cannot retrive your data");
}

#include "../include/LinkedList.h"
// #include "Stack.h"
#include <iostream>

int main() {
  // LinkedStack lStack;
  LinkedList lList;
  Node *data = new Node();

  std::cout << "\nLinked List" << std::endl;

  try {
    std::cout << "1 = TRUE/FOUND, "
              << " 0 = FALSE/NOT FOUND" << std::endl;
    std::cout << lList.isEmpty() << std::endl;
    lList.addToHead(23);
    lList.addToHead(21);
    lList.traverse();
    lList.addToTail(67);
    lList.addToTail(43);
    lList.addToHead(95);
    lList.traverse();
    std::cout << lList.getHeadInfo() << " is the HEAD element" << std::endl;
    std::cout << lList.getTailInfo() << " is the TAIL element" << std::endl;
    lList.traverse();
    std::cout << lList.removeFromHead() << " was removed from HEAD"
              << std::endl;
    std::cout << lList.removeFromTail() << " was removed from TAIL"
              << std::endl;
    std::cout << lList.getHeadInfo() << " is the HEAD element" << std::endl;
    std::cout << lList.getTailInfo() << " is the TAIL element" << std::endl;
    lList.traverse();
    lList.remove(67);
        std::cout << lList.getHeadInfo() << " is the HEAD element" << std::endl;
    std::cout << lList.getTailInfo() << " is the TAIL element" << std::endl;
    lList.remove(21);
    
  std::cout << lList.getHeadInfo() << " is the HEAD element" << std::endl;
    std::cout << lList.getTailInfo() << " is the TAIL element" << std::endl;
    lList.traverse();
    std::cout << lList.search(43) << std::endl;
    data = lList.retrive(23, data);
    lList.add(44, nullptr);
  std::cout << lList.getHeadInfo() << " is the HEAD element" << std::endl;
    std::cout << lList.getTailInfo() << " is the TAIL element" << std::endl;
    lList.traverse();

  } catch (std::string error) {
    std::cout << error << std ::endl;
  }
}

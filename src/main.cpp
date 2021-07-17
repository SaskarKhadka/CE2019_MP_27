#include "../include/LinkedList.h"
#include "../include/Stack.h"
#include <iostream>

int main() {
  LinkedStack lStack;
  try {
    lStack.push(66);
    lStack.push(32);
    lStack.push(64);
    lStack.push(11);
    lStack.push(111);
    lStack.push(77);
    lStack.push(19);
    lStack.push(121);
    std::cout << lStack.top() << std::endl;
    std::cout << lStack.pop() << std::endl;
    std::cout << lStack.pop() << std::endl;
    std::cout << lStack.pop() << std::endl;
    std::cout << lStack.pop() << std::endl;
    std::cout << lStack.pop() << std::endl;
    std::cout << lStack.pop() << std::endl;
    std::cout << lStack.top() << std::endl;
    std::cout << lStack.pop() << std::endl;
    std::cout << lStack.pop() << std::endl;
    std::cout << lStack.isEmpty() << std::endl;
  } catch (std::string error) {
    std::cout << error << std::endl;
  }
}

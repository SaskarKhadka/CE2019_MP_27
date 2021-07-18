#include "../include/LinkedList.h"
#include "../include/NumberConverter.h"
#include <iostream>
#include <string.h>

int main() {
  NumberConverter numConverter;
  try {
    std::string a = "1100000000000011bcde111111111111111111111111111111111110000aaaaaaaaaaaaaaaaf";
    std::cout << (char)67 << std::endl;
    int size = a.length();
    char b[size];
    strcpy(b, a.c_str());
    std::cout << numConverter.isHexadecimalNumberValid(b) << std::endl;
  } catch (std::string error) {
    std::cout << error << std::endl;
  }
}

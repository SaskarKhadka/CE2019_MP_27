#include "../include/LinkedList.h"
#include "../include/NumberConverter.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
int main() {
  NumberConverter numConverter;
  try {
   std::string a;
   std::cin >> a;
   int size = a.length();
   char b[size];
   strcpy(b, a.c_str());
   std::cout << numConverter.decimalToHexadecimal(b) << std::endl;
  } catch (const char* error) {
    std::string err(error);
    std::cout << err << std::endl;
  }
}

#include "../include/LinkedList.h"
#include "../include/NumberConverter.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
int main() {
  NumberConverter numConverter;
  try {
   std::string a;
   std::cin >> a;
   int size = a.length();
   char b[size];
   strcpy(b, a.c_str());
  //  std::cout << 7 * pow(8, 18)  << std::endl;
   std::cout << numConverter.octalToBinary(b) << std::endl;
  } catch (const char* error) {
    std::string err(error);
    std::cout << err << std::endl;
  }
}

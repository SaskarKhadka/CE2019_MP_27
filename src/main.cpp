#include "../include/LinkedList.h"
#include "../include/NumberConverter.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
int main() {
  NumberConverter numConverter;
  try {
    std::string a;
    std::cin >> a;
    int size = a.length();
    char b[size];
    strcpy(b, a.c_str());
    // unsigned long long hi = 15 * pow(16, 15) + 15 * pow(16, 14);
    // std::cout <<hi
    //           << std::endl;
     std::cout << numConverter.hexadecimalToDecimal(b) << std::endl;
  } catch (const char *error) {
    std::string err(error);
    std::cout << err << std::endl;
  }
}

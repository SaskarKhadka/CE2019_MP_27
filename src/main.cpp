#include "../include/LinkedList.h"
#include "../include/NumberConverter.h"
#include <array>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
  NumberConverter numConverter;
  try {
    std::cout.precision(6);
    std::string a;
    std::cin >> a;
    int length = a.length();
    char b[length];
    strcpy(b, a.c_str());
    bool isValid = numConverter.isHexadecimalNumberValid(a);
    // std::cout << isValid << std::endl;
    if (isValid) {
      unsigned int location = a.find(".");
      if (location == length - 1) {
        a.replace(a.size() - 1, a.size(), "");
        char num[a.size()];
        strcpy(num, a.c_str());
        std::cout << numConverter.hexadecimalToBinary(num) << std::endl;
      } else if (location == 0) {
        a.replace(0, 1, "");
        char num[a.size()];
        strcpy(num, a.c_str());
        std::cout << numConverter.hexadecimalToBinary(nullptr, num) << std::endl;
      }
      else if (location < length) {
        std::string integral = "";
        std::string floating = "";
        for (int i = 0; i < length; i++) {
          if (i < location) {
            integral += b[i];
          }
          if (i > location) {
            floating += b[i];
          }
        }

        char intPart[integral.size()];
        char floatPart[floating.size()];

        strcpy(intPart, integral.c_str());
        strcpy(floatPart, floating.c_str());

        std::cout << "The decimal no is: " << std::fixed
                  << numConverter.hexadecimalToBinary(intPart, floatPart)
                  << std::endl;
      } else {
        std::cout << numConverter.hexadecimalToBinary(b) << std::endl;
      }
    }
  } catch (const char *error) {
    std::string err(error);
    std::cout << err << std::endl;
  }
}

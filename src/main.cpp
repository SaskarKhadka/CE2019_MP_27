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
    // std::cout << a.find(".") << std::endl;
    // std::cout << (int)1.9999 << std::endl;
    std::cout.precision(6);
    int size = a.length();
    char b[size];
    strcpy(b, a.c_str());
    // std::cout << a << std::endl;
    if (a.find(".") == size - 1) {
      // std::string newString =
      a.replace(a.size() - 1, a.size(), ""); // no need to store in new string
      char num[a.size()];
      strcpy(num, a.c_str());
      std::cout << numConverter.binaryToOctal(num) << std::endl;
    } else if (a.find(".") < a.size()) {
      std::string integral = "";
      std::string floating = "";
      bool isFloatingPart = false;
      for (int i = 0; i < a.size(); i++) {
        if (i < a.find(".")) {
          integral += b[i];
        }
        if (i > a.find(".")) {
          floating += b[i];
        }
      }
      char intPart[integral.size()];
      char floatPart[floating.size()];
      strcpy(intPart, integral.c_str());
      strcpy(floatPart, floating.c_str());
      std::string intOctal = numConverter.binaryToHexadecimal(intPart, floatPart);
      std::cout << "The decimal no is: " << std::fixed << intOctal << std::endl;

    } else {
      std::cout << numConverter.octalToDecimal(b) << std::endl;
    }
    // int size = a.length();
    // char b[size];
    // strcpy(b, a.c_str());
    // // for (int i = size - 1; i >= 0; i--) {
    // //   std::cout << b[i] << std::endl;
    // // }

    // unsigned long long hi = 15 * pow(16, 15) + 15 * pow(16, 14);
    // std::cout << hi << std::endl;
    //  std::cout << numConverter.hexadecimalToDecimal(b) << std::endl;
  } catch (const char *error) {
    std::string err(error);
    std::cout << err << std::endl;
  }
}

#include "../include/NumberConverter.h"
#include <iostream>
#include <string.h>

// checks if the given binary number is valid
bool NumberConverter::isBinaryNumberValid(char *binaryNo) { // unsigned int
  int length = strlen(binaryNo);
  bool isValid = false;
  for (int i = length - 1; i >= 0; i--) {
    isValid = (binaryNo[i] - '0') > 1 ? false : true;
    if (!isValid)
      return false;
  }
  return true;
}

// checks if the given decimal number is valid
bool NumberConverter::isDecimalNumberValid(char *decimalNo) {
  int length = strlen(decimalNo);
  bool isValid = false;
  for (int i = length - 1; i >= 0; i--) {
    isValid = (decimalNo[i] >= 48 && decimalNo[i] <= 57) ? true : false;
    if (!isValid)
      return false;
  }
  return true;
}

// checks if the given octal number is valid
bool NumberConverter::isOctalNumberValid(char *octalNo) {
  int length = strlen(octalNo);
  bool isValid = false;
  for (int i = length - 1; i >= 0; i--) {
    isValid = (octalNo[i] - '0') > 7 ? false : true;
    if (!isValid)
      return false;
  }
  return true;
}

// checks if the given hexadecimal number is valid
bool NumberConverter::isHexadecimalNumberValid(char *hexadecimalNo) {
  int length = strlen(hexadecimalNo);
  bool isValid = false;
  // 48 to 57 -> 0 to 9
  // 65 to 70 -> A to F
  // 97 to 102 -> a to f
  for (int i = length - 1; i >= 0; i--) {

    isValid = (hexadecimalNo[i] >= 48 && hexadecimalNo[i] <= 57)    ? true
              : (hexadecimalNo[i] >= 65 && hexadecimalNo[i] <= 70)  ? true
              : (hexadecimalNo[i] >= 97 && hexadecimalNo[i] <= 102) ? true
                                                                    : false;
    // isValid = (hexadecimalNo[i] >= 48 && hexadecimalNo[i] <= 57) ||
    //                   (hexadecimalNo[i] >= 65 && hexadecimalNo[i] <= 70) ||
    //                   (hexadecimalNo[i] >= 97 && hexadecimalNo[i] <= 102)
    //               ? true
    //               : false;
    if (!isValid)
      return false;
  }
  return isValid;
}
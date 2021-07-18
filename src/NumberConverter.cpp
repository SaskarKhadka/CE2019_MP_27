#include "../include/NumberConverter.h"
#include <iostream>
#include <string.h>

// checks if the given binary number is valid
bool NumberConverter::isBinaryNumberValid(char *binaryNo) { // unsigned int
  int length = strlen(binaryNo);
  if (length > 19)
    throw "Only 19 digit numbers are allowed";
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
  if (length > 19)
    throw "Only 19 digit numbers are allowed";
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
  if (length > 19)
    throw "Only 19 digit numbers are allowed";
  bool isValid = false;
  for (int i = length - 1; i >= 0; i--) {
    isValid = (octalNo[i] >= 48 && octalNo[i] <= 55) ? false : true;
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

// converts a decimal number to binary number
std::string NumberConverter::decimalToBinary(char *decimalNo) {
  int length = strlen(decimalNo);

  bool isValid = isDecimalNumberValid(decimalNo);
  if (isValid) {
    unsigned long long decimal = strtoull(decimalNo, nullptr, 10);
    while (decimal != 0) {
      int rem = decimal % 2;
      stack.push(rem);
      decimal = decimal / 2;
    }
    std::string binaryNo = "";
    while (!stack.isEmpty()) {
      int binary = stack.pop();
      binaryNo += std::to_string(binary);
    }
    std::cout << sizeof(binaryNo) << std::endl;
    return binaryNo;
  }
  throw "The decimal number is not valid";
}

// converts a decimal number to octal number
std::string NumberConverter::decimalToOctal(char *decimalNo) {
  int length = strlen(decimalNo);

  bool isValid = isDecimalNumberValid(decimalNo);
  if (isValid) {
    unsigned long long decimal = strtoull(decimalNo, nullptr, 10);
    while (decimal != 0) {
      int rem = decimal % 8;
      stack.push(rem);
      decimal = decimal / 8;
    }
    std::string octalNo = "";
    while (!stack.isEmpty()) {
      int octal = stack.pop();
      octalNo += std::to_string(octal);
    }
    return octalNo;
  }
  throw "The decimal number is not valid";
}

// converts a decimal number to hexadecimal number
std::string NumberConverter::decimalToHexadecimal(char *decimalNo) {
  int length = strlen(decimalNo);

  bool isValid = isDecimalNumberValid(decimalNo);
  if (isValid) {
    unsigned long long decimal = strtoull(decimalNo, nullptr, 10);
    while (decimal != 0) {
      int rem = decimal % 16;
      stack.push(rem);
      decimal = decimal / 16;
    }
    char charHex;
    std::string hexadecimalNo = "";
    while (!stack.isEmpty()) {
      int hex = stack.pop();
      switch (hex) {
      case 10:
        charHex = 'A';
        break;

      case 11:
        charHex = 'B';
        break;

      case 12:
        charHex = 'C';
        break;

      case 13:
        charHex = 'D';
        break;

      case 14:
        charHex = 'E';

        break;

      case 15:
        charHex = 'F';
        break;

      default:
        charHex = '0' + hex;
        break;
      }

      hexadecimalNo += charHex;
    }
    return hexadecimalNo;
  }
  throw "The decimal number is not valid";
}
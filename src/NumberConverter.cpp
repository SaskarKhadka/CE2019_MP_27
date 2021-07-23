#include "../include/NumberConverter.h"
#include <iostream>
#include <math.h>
#include <string.h>

// checks if the given binary number is valid
bool NumberConverter::isBinaryNumberValid(char *binaryNo) { // unsigned int
  int length = strlen(binaryNo);
  if (length > 19)
    throw "Only 19 digit numbers are allowed for binary manipulations";
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
    throw "Only 19 digit numbers are allowed for decimal manipulations";
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
    throw "Only 19 digit numbers are allowed for octal manipulations";
  bool isValid = false;
  for (int i = length - 1; i >= 0; i--) {
    isValid = (octalNo[i] >= 48 && octalNo[i] <= 55) ? true : false;
    if (!isValid)
      return false;
  }
  return true;
}

// checks if the given hexadecimal number is valid
bool NumberConverter::isHexadecimalNumberValid(char *hexadecimalNo) {
  int length = strlen(hexadecimalNo);
  if (length > 16)
    throw "Only 16 digit numbers are allowed for hexadecimal manipulations";
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
std::string NumberConverter::decimalToBinary(char *decimalNo,
                                             char *floatDecimalNo) {
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
    // std::cout << sizeof(binaryNo) << std::endl;
    // return binaryNo;

    if (floatDecimalNo != nullptr) {
      // binaryNo = binaryNo + "0";
      int length = strlen(floatDecimalNo);
      unsigned long long floatDec = strtoull(floatDecimalNo, nullptr, 10);
      long double floatDecimal = (long double)floatDec / pow(10, length);
      int temp = 0;
      for (int i = 0; i < 6 && floatDecimal != 0; i++) {
        // floatDecimal -= temp; // See below
        floatDecimal *= 2;
        temp = (int)floatDecimal;
        stack.push(temp);
        floatDecimal -= temp;
      }
      std::string floatBinaryNo = "";
      while (!stack.isEmpty()) {
        int binary = stack.pop();
        floatBinaryNo = std::to_string(binary) + floatBinaryNo;
      }
      return binaryNo + "." + floatBinaryNo;
    }
    return binaryNo;
  }
  throw "The decimal number is not valid";
}

// converts a decimal number to octal number
std::string NumberConverter::decimalToOctal(char *decimalNo,
                                            char *floatDecimalNo) {
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
    // return octalNo;
    if (floatDecimalNo != nullptr) {
      int length = strlen(floatDecimalNo);
      unsigned long long floatDec = strtoull(floatDecimalNo, nullptr, 10);
      long double floatDecimal = (long double)floatDec / pow(10, length);
      int temp = 0;
      for (int i = 0; i < 6 && floatDecimal != 0; i++) {
        // floatDecimal -= temp; // See below
        floatDecimal *= 8;
        temp = (int)floatDecimal;
        stack.push(temp);
        floatDecimal -= temp;
      }
      std::string floatOctalNo = "";
      while (!stack.isEmpty()) {
        int octal = stack.pop();
        floatOctalNo = std::to_string(octal) + floatOctalNo;
      }
      return octalNo + "." + floatOctalNo;
    }
    return octalNo;
  }
  throw "The decimal number is not valid";
}

// converts a decimal number to hexadecimal number
std::string NumberConverter::decimalToHexadecimal(char *decimalNo,
                                                  char *floatDecimalNo) {
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
    // return hexadecimalNo;

    if (floatDecimalNo != nullptr) {
      int length = strlen(floatDecimalNo);
      unsigned long long floatDec = strtoull(floatDecimalNo, nullptr, 10);
      long double floatDecimal = (long double)floatDec / pow(10, length);
      int temp = 0;
      for (int i = 0; i < 6 && floatDecimal != 0; i++) {
        // floatHexadecimal -= temp;
        floatDecimal *= 16;
        temp = (int)floatDecimal;
        stack.push(temp);
        floatDecimal -= temp;
      }
      std::string floatHexadecimalNo = "";
      char floatCharHex;
      while (!stack.isEmpty()) {
        int hex = stack.pop();
        switch (hex) {
        case 10:
          floatCharHex = 'A';
          break;

        case 11:
          floatCharHex = 'B';
          break;

        case 12:
          floatCharHex = 'C';
          break;

        case 13:
          floatCharHex = 'D';
          break;

        case 14:
          floatCharHex = 'E';

          break;

        case 15:
          floatCharHex = 'F';
          break;

        default:
          floatCharHex = '0' + hex;
          break;
        }
        floatHexadecimalNo = floatCharHex + floatHexadecimalNo;
      }
      return hexadecimalNo + "." + floatHexadecimalNo;
    }
    return hexadecimalNo;
  }
  throw "The decimal number is not valid";
}

// converts a binary number to decimal number
unsigned int NumberConverter::binaryToDecimal(char *binaryNo) {
  int length = strlen(binaryNo);
  bool isValid = isBinaryNumberValid(binaryNo);
  if (isValid) {
    int power = 0;
    for (int i = length - 1; i >= 0; i--) {
      int digit = binaryNo[i] - '0';
      unsigned int decimal = digit * pow(2, power);
      stack.push(decimal);
      power++;
    }
    unsigned int decimalNo = 0;
    while (!stack.isEmpty()) {
      decimalNo += stack.pop();
    }
    return decimalNo;
  } else {
    throw "The binary number is not valid";
  }
}

// converts a binary number to octal number
std::string NumberConverter::binaryToOctal(char *binaryNo) {
  unsigned int decimal = binaryToDecimal(binaryNo);
  std::string dec = std::to_string(decimal);
  char decimalNo[dec.size()];
  strcpy(decimalNo, dec.c_str());
  std::string octalNo = decimalToOctal(decimalNo);
  return octalNo;
}

// converts a binary number to hexadecimal number
std::string NumberConverter::binaryToHexadecimal(char *binaryNo) {
  unsigned int decimal = binaryToDecimal(binaryNo);
  std::string dec = std::to_string(decimal);
  char decimalNo[dec.size()];
  strcpy(decimalNo, dec.c_str());
  std::string octalNo = decimalToHexadecimal(decimalNo);
  return octalNo;
}

// converts a octal number to decimal number
unsigned long long NumberConverter::octalToDecimal(char *octalNo) {
  int length = strlen(octalNo);
  bool isValid = isOctalNumberValid(octalNo);
  if (isValid) {
    int power = 0;
    for (int i = length - 1; i >= 0; i--) {
      int digit = octalNo[i] - '0';
      unsigned long long decimal = digit * pow(8, power);
      stack.push(decimal);
      power++;
    }
    unsigned long long int decimalNo = 0;
    while (!stack.isEmpty()) {
      decimalNo += stack.pop();
    }
    return decimalNo;
  } else {
    throw "The octal number is not valid";
  }
}

// converts a octal number to binary number
std::string NumberConverter::octalToBinary(char *octalNo) {
  unsigned long long decimal = octalToDecimal(octalNo);
  std::string dec = std::to_string(decimal);
  char decimalNo[dec.size()];
  strcpy(decimalNo, dec.c_str());
  std::string binaryNo = decimalToBinary(decimalNo);
  return binaryNo;
}

// converts a octal number to hexadecimal number
std::string NumberConverter::octalToHexadecimal(char *octalNo) {
  unsigned long long decimal = octalToDecimal(octalNo);
  std::string dec = std::to_string(decimal);
  char decimalNo[dec.size()];
  strcpy(decimalNo, dec.c_str());
  std::string hexadecimalNo = decimalToHexadecimal(decimalNo);
  return hexadecimalNo;
}

// converts a hexadecimal number to decimal number
unsigned long long NumberConverter::hexadecimalToDecimal(char *hexadecimalNo) {
  int length = strlen(hexadecimalNo);
  bool isValid = isHexadecimalNumberValid(hexadecimalNo);
  if (isValid) {
    int power = 0;
    int hexNum;
    for (int i = length - 1; i >= 0; i--) {
      switch (hexadecimalNo[i]) {

      case 'A':
      case 'a':
        hexNum = 10;
        break;

      case 'B':
      case 'b':
        hexNum = 11;
        break;

      case 'C':
      case 'c':
        hexNum = 12;
        break;

      case 'D':
      case 'd':
        hexNum = 13;
        break;

      case 'E':
      case 'e':
        hexNum = 14;
        break;

      case 'F':
      case 'f':
        hexNum = 15;
        break;

      default:
        hexNum = hexadecimalNo[i] - '0';
        break;
      }
      unsigned long long decimal = hexNum * pow(16, power);
      stack.push(decimal);
      power++;
    }
    unsigned long long decimalNo = 0;
    while (!stack.isEmpty()) {
      decimalNo += stack.pop();
    }
    return decimalNo;
  } else {
    throw "The hexadecimal number is not valid";
  }
}

// converts a hexadecimal number to binary number
std::string NumberConverter::hexadecimalToBinary(char *hexadecimalNo) {
  unsigned long long decimal = hexadecimalToDecimal(hexadecimalNo);
  std::string dec = std::to_string(decimal);
  char decimalNo[dec.size()];
  strcpy(decimalNo, dec.c_str());
  std::string binaryNo = decimalToBinary(decimalNo);
  return binaryNo;
}

// converts a hexadecimal number to octal number
std::string NumberConverter::hexadecimalToOctal(char *hexadecimalNo) {
  unsigned long long decimal = hexadecimalToDecimal(hexadecimalNo);
  std::string dec = std::to_string(decimal);
  char decimalNo[dec.size()];
  strcpy(decimalNo, dec.c_str());
  std::string octalNo = decimalToOctal(decimalNo);
  return octalNo;
}
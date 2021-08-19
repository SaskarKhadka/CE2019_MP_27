#include "../include/NumberConverter.h"
#include <iostream>
#include <math.h>
#include <string.h>

/*
48 to 57 -> 0 to 9
65 to 70 -> A to F
97 to 102 -> a to f
*/

// checks if the given binary number is valid
bool NumberConverter::isBinaryNumberValid(std::string binaryNo) {
  int length = binaryNo.length();
  unsigned int location = binaryNo.find(".");

  if (length == 1 && location == 0)
    return false;
  if (location > (length - 1) && length > 19)
    throw "Only 19 integer digit are allowed for binary manipulations";

  if (location < length && location > 19)
    throw "Only 19 integer digit are allowed for binary manipulations";
  // std::cout << length - location +1 << std::endl;
  if (location < length && (length - location - 1) > 19)
    throw "Only 19 floating digits are allowed for binary manipulations";

  bool isValid = false;
  int index = 0;
  for (int i = 0; i < length; i++) {
    isValid = binaryNo[i] == '0' || binaryNo[i] == '1' || binaryNo[i] == '.'
                  ? true
                  : false;
    index = binaryNo[i] == '.' ? ++index : index;
    if (!isValid || index > 1)
      return false;
  }
  return true;
}

// checks if the given decimal number is valid
bool NumberConverter::isDecimalNumberValid(std::string decimalNo) {
  int length = decimalNo.length();
  unsigned int location = decimalNo.find(".");

  if (length == 1 && location == 0)
    return false;
  if (location > (length - 1) && length > 19)
    throw "Only 19 integer digit are allowed for decimal manipulations";

  if (location < length && location > 19)
    throw "Only 19 integer digit are allowed for decimal manipulations";
  // std::cout << length - location +1 << std::endl;
  if (location < length && (length - location - 1) > 19)
    throw "Only 19 floating digits are allowed for decimal manipulations";

  bool isValid = false;
  int index = 0;
  for (int i = 0; i < length; i++) {
    isValid = (decimalNo[i] >= 48 && decimalNo[i] <= 57) ? true
              : decimalNo[i] == '.'                      ? true
                                                         : false;
    index = decimalNo[i] == '.' ? ++index : index;
    if (!isValid || index > 1)
      return false;
  }
  return true;
}

// checks if the given octal number is valid
bool NumberConverter::isOctalNumberValid(std::string octalNo) {
  int length = octalNo.length();
  unsigned int location = octalNo.find(".");

  if (length == 1 && location == 0)
    return false;
  if (location > (length - 1) && length > 19)
    throw "Only 19 integer digit are allowed for octal manipulations";

  if (location < length && location > 19)
    throw "Only 19 integer digit are allowed for octal manipulations";
  // std::cout << length - location +1 << std::endl;
  if (location < length && (length - location - 1) > 19)
    throw "Only 19 floating digits are allowed for octal manipulations";

  bool isValid = false;
  int index = 0;
  for (int i = 0; i < length; i++) {
    isValid = (octalNo[i] >= 48 && octalNo[i] <= 55) ? true
              : octalNo[i] == '.'                    ? true
                                                     : false;

    index = octalNo[i] == '.' ? ++index : index;
    if (!isValid || index > 1)
      return false;
  }
  return true;
}

// checks if the given hexadecimal number is valid
bool NumberConverter::isHexadecimalNumberValid(std::string hexadecimalNo) {
  int length = hexadecimalNo.length();
  unsigned int location = hexadecimalNo.find(".");

  if (length == 1 && location == 0)
    return false;

  if (location > (length - 1) && length > 16)
    throw "Only 16 integer digit are allowed for heaxdecimal manipulations";

  if (location < length && location > 16)
    throw "Only 19 integer digit are allowed for hexadecimal manipulations";
  // std::cout << length - location +1 << std::endl;
  if (location < length && (length - location - 1) > 19)
    throw "Only 19 floating digits are allowed for hexadecimal manipulations";

  bool isValid = false;
  int index = 0;
  for (int i = 0; i < length; i++) {
    isValid = (hexadecimalNo[i] >= 48 && hexadecimalNo[i] <= 57)    ? true
              : (hexadecimalNo[i] >= 65 && hexadecimalNo[i] <= 70)  ? true
              : (hexadecimalNo[i] >= 97 && hexadecimalNo[i] <= 102) ? true
              : hexadecimalNo[i] == '.'                             ? true
                                                                    : false;

    index = hexadecimalNo[i] == '.' ? ++index : index;
    if (!isValid || index > 1)
      return false;
  }
  return true;
}

// converts a decimal number to binary number
std::string NumberConverter::decimalToBinary(char *decimalNo,
                                             char *floatDecimalNo) {
  std::string binaryNo = "";
  bool isZero = strlen(decimalNo) == 1 && decimalNo[0] == '0' ? true : false;
  if (decimalNo != nullptr && !isZero) {
    int length = strlen(decimalNo);
    unsigned long long decimal = strtoull(decimalNo, nullptr, 10);
    while (decimal != 0) {
      int rem = decimal % 2;
      stack.push(rem);
      decimal = decimal / 2;
    }
    while (!stack.isEmpty()) {
      int binary = stack.top();
      binaryNo += std::to_string(binary);
      stack.pop();
    }

  } else
    binaryNo += "0";

  if (floatDecimalNo != nullptr) {
    int length = strlen(floatDecimalNo);
    unsigned long long floatDec = strtoull(floatDecimalNo, nullptr, 10);
    long double floatDecimal = (long double)floatDec / pow(10, length);
    int temp = 0;
    for (int i = 0; i < 6 && floatDecimal != 0; i++) {
      floatDecimal *= 2;
      temp = (int)floatDecimal;
      stack.push(temp);
      floatDecimal -= temp;
    }
    std::string floatBinaryNo = "";
    while (!stack.isEmpty()) {
      int binary = stack.top();
      floatBinaryNo = std::to_string(binary) + floatBinaryNo;
      stack.pop();
    }
    return binaryNo + "." + (floatBinaryNo == "" ? "0" : floatBinaryNo);
  }
  return binaryNo;
}

// converts a decimal number to octal number
std::string NumberConverter::decimalToOctal(char *decimalNo,
                                            char *floatDecimalNo) {
  std::string octalNo = "";
  bool isZero = strlen(decimalNo) == 1 && decimalNo[0] == '0' ? true : false;
  if (decimalNo != nullptr && !isZero) {
    int length = strlen(decimalNo);
    unsigned long long decimal = strtoull(decimalNo, nullptr, 10);
    while (decimal != 0) {
      int rem = decimal % 8;
      stack.push(rem);
      decimal = decimal / 8;
    }
    while (!stack.isEmpty()) {
      int octal = stack.top();
      octalNo += std::to_string(octal);
      stack.pop();
    }
  } else
    octalNo += "0";

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
      int octal = stack.top();
      floatOctalNo = std::to_string(octal) + floatOctalNo;
      stack.pop();
    }
    return octalNo + "." + (floatOctalNo == "" ? "0" : floatOctalNo);
  }
  return octalNo;
}

// converts a decimal number to hexadecimal number
std::string NumberConverter::decimalToHexadecimal(char *decimalNo,
                                                  char *floatDecimalNo) {

  std::string hexadecimalNo = "";
  bool isZero = strlen(decimalNo) == 1 && decimalNo[0] == '0' ? true : false;
  if (decimalNo != nullptr && !isZero) {
    int length = strlen(decimalNo);
    unsigned long long decimal = strtoull(decimalNo, nullptr, 10);
    while (decimal != 0) {
      int rem = decimal % 16;
      stack.push(rem);
      decimal = decimal / 16;
    }
    char charHex;
    while (!stack.isEmpty()) {
      int hex = stack.top();
      if (hex <= 9)
        charHex = hex + '0';
      else
        charHex = hex + '7';

      hexadecimalNo += charHex;
      stack.top();
    }
  } else
    hexadecimalNo += "0";

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
      int hex = stack.top();
      if (hex <= 9)
        floatCharHex = hex + '0';
      else
        floatCharHex = hex + '7';

      floatHexadecimalNo = floatCharHex + floatHexadecimalNo;
      stack.pop();
    }
    return hexadecimalNo + "." +
           (floatHexadecimalNo == "" ? "0" : floatHexadecimalNo);
  }
  return hexadecimalNo;
}

// converts a binary number to decimal number
std::string NumberConverter::binaryToDecimal(char *binaryNo,
                                             char *floatBinaryNo) {
  unsigned int decimalNo = 0;
  if (binaryNo != nullptr) {
    int length = strlen(binaryNo);
    int power = 0;
    for (int i = length - 1; i >= 0; i--) {
      int digit = binaryNo[i] - '0';
      unsigned int decimal = digit * pow(2, power);
      stack.push(decimal);
      power++;
    }
    while (!stack.isEmpty()) {
      decimalNo += stack.pop();
    }
  }

  if (floatBinaryNo != nullptr) {
    int length = strlen(floatBinaryNo);
    for (int i = length - 1; i >= 0; i--) {
      int digit = floatBinaryNo[i] - '0';
      stack.push(digit);
    }
    int power = -1;
    long double floatDecimalNo = 0;
    while (!stack.isEmpty()) {
      int digit = stack.top();
      floatDecimalNo += digit * pow(2, power);
      power--;
      stack.pop();
    }
    return std::to_string(decimalNo + floatDecimalNo);
  }
  return std::to_string(decimalNo);
}

// converts a binary number to octal number
std::string NumberConverter::binaryToOctal(char *binaryNo,
                                           char *floatBinaryNo) {
  std::string dec = binaryToDecimal(binaryNo, floatBinaryNo);
  unsigned int location = dec.find(".");
  int length = dec.length();
  if (location < length) {
    std::string integralDec = "";
    std::string floatDec = "";
    for (int i = 0; i < length; i++) {
      if (i < location) {
        integralDec += dec[i];
      }
      if (i > location) {
        floatDec += dec[i];
      }
    }
    char intPart[integralDec.size()];
    char floatPart[floatDec.size()];
    strcpy(intPart, integralDec.c_str());
    strcpy(floatPart, floatDec.c_str());
    std::string octalNo = decimalToOctal(intPart, floatPart);
    return octalNo;
  }
  char decimalNo[dec.size()];
  strcpy(decimalNo, dec.c_str());
  std::string octalNo = decimalToOctal(decimalNo);
  return octalNo;
}

// converts a binary number to hexadecimal number
std::string NumberConverter::binaryToHexadecimal(char *binaryNo,
                                                 char *floatBinaryNo) {
  std::string dec = binaryToDecimal(binaryNo, floatBinaryNo);
  unsigned int location = dec.find(".");
  int length = dec.length();
  if (location < length) {
    std::string integralDec = "";
    std::string floatDec = "";
    for (int i = 0; i < dec.size(); i++) {
      if (i < location) {
        integralDec += dec[i];
      }
      if (i > location) {
        floatDec += dec[i];
      }
    }
    char intPart[integralDec.size()];
    char floatPart[floatDec.size()];
    strcpy(intPart, integralDec.c_str());
    strcpy(floatPart, floatDec.c_str());
    std::string hexadecimalNo = decimalToHexadecimal(intPart, floatPart);
    return hexadecimalNo;
  }
  char decimalNo[dec.size()];
  strcpy(decimalNo, dec.c_str());
  std::string hexadecimalNo = decimalToHexadecimal(decimalNo);
  return hexadecimalNo;
}

// converts a octal number to decimal number
std::string NumberConverter::octalToDecimal(char *octalNo, char *floatOctalNo) {

  unsigned long long decimalNo = 0;
  if (octalNo != nullptr) {
    int length = strlen(octalNo);
    int power = 0;
    for (int i = length - 1; i >= 0; i--) {
      int digit = octalNo[i] - '0';
      unsigned long long decimal = digit * pow(8, power);
      stack.push(decimal);
      power++;
    }
    while (!stack.isEmpty()) {
      decimalNo += stack.pop();
    }
  }
  if (floatOctalNo != nullptr) {
    int length = strlen(floatOctalNo);

    for (int i = length - 1; i >= 0; i--) {
      int digit = floatOctalNo[i] - '0';
      stack.push(digit);
    }
    int power = -1;
    long double floatDecimalNo = 0;
    while (!stack.isEmpty()) {
      int digit = stack.top();
      floatDecimalNo += digit * pow(8, power);
      power--;
      stack.pop();
    }
    return std::to_string(decimalNo + floatDecimalNo);
  }
  return std::to_string(decimalNo);
}

// converts a octal number to binary number
std::string NumberConverter::octalToBinary(char *octalNo, char *floatOctalNo) {
  std::string dec = octalToDecimal(octalNo, floatOctalNo);
  unsigned int location = dec.find(".");
  int length = dec.length();
  if (location < length) {
    std::string integralDec = "";
    std::string floatDec = "";
    for (int i = 0; i < dec.size(); i++) {
      if (i < location) {
        integralDec += dec[i];
      }
      if (i > location) {
        floatDec += dec[i];
      }
    }
    char intPart[integralDec.size()];
    char floatPart[floatDec.size()];
    strcpy(intPart, integralDec.c_str());
    strcpy(floatPart, floatDec.c_str());
    std::string binaryNo = decimalToBinary(intPart, floatPart);
    return binaryNo;
  }
  char decimalNo[dec.size()];
  strcpy(decimalNo, dec.c_str());
  std::string binaryNo = decimalToBinary(decimalNo);
  return binaryNo;
}

// converts a octal number to hexadecimal number
std::string NumberConverter::octalToHexadecimal(char *octalNo,
                                                char *floatOctalNo) {
  std::string dec = octalToDecimal(octalNo, floatOctalNo);
  unsigned int location = dec.find(".");
  int length = dec.length();
  if (location < length) {
    std::string integralDec = "";
    std::string floatDec = "";
    for (int i = 0; i < dec.size(); i++) {
      if (i < location) {
        integralDec += dec[i];
      }
      if (i > location) {
        floatDec += dec[i];
      }
    }
    char intPart[integralDec.size()];
    char floatPart[floatDec.size()];
    strcpy(intPart, integralDec.c_str());
    strcpy(floatPart, floatDec.c_str());
    std::string hexadecimalNo = decimalToHexadecimal(intPart, floatPart);
    return hexadecimalNo;
  }
  char decimalNo[dec.size()];
  strcpy(decimalNo, dec.c_str());
  std::string hexadecimalNo = decimalToHexadecimal(decimalNo);
  return hexadecimalNo;
}

// converts a hexadecimal number to decimal number
std::string NumberConverter::hexadecimalToDecimal(char *hexadecimalNo,
                                                  char *floatHexadecimalNo) {
    unsigned long long decimalNo = 0;
  if (hexadecimalNo != nullptr) {
    int length = strlen(hexadecimalNo);
    int power = 0;
    int hexNum;
    for (int i = length - 1; i >= 0; i--) {
      if (hexadecimalNo[i] >= 48 && hexadecimalNo[i] <= 57)
        hexNum = hexadecimalNo[i] - '0';
      else if (hexadecimalNo[i] >= 97 && hexadecimalNo[i] <= 102)
        hexNum = hexadecimalNo[i] - 'a' + 10;
      else
        hexNum = hexadecimalNo[i] - 'A' + 10;

      unsigned long long decimal = hexNum * pow(16, power);
      stack.push(decimal);
      power++;
    }
    while (!stack.isEmpty()) {
      decimalNo += stack.pop();
    }
  }

  if (floatHexadecimalNo != nullptr) {
    int length = strlen(floatHexadecimalNo);
    int floatHexNum;
    for (int i = length - 1; i >= 0; i--) {
      if (floatHexadecimalNo[i] >= 48 && floatHexadecimalNo[i] <= 57)
        floatHexNum = floatHexadecimalNo[i] - '0';
      else if (floatHexadecimalNo[i] >= 97 && floatHexadecimalNo[i] <= 102)
        floatHexNum = floatHexadecimalNo[i] - 'a' + 10;
      else
        floatHexNum = floatHexadecimalNo[i] - 'A' + 10;

      stack.push(floatHexNum);
    }
    int power = -1;
    long double floatDecimalNo = 0;
    while (!stack.isEmpty()) {
      int digit = stack.top();
      floatDecimalNo += digit * pow(16, power);
      power--;
      stack.pop();
    }
    return std::to_string(decimalNo + floatDecimalNo);
  }
  return std::to_string(decimalNo);
}

// converts a hexadecimal number to binary number
std::string NumberConverter::hexadecimalToBinary(char *hexadecimalNo,
                                                 char *floatHexadecimalNo) {
  std::string dec = hexadecimalToDecimal(hexadecimalNo, floatHexadecimalNo);
  unsigned int location = dec.find(".");
  int length = dec.length();
  if (location < length) {
    std::string integralDec = "";
    std::string floatDec = "";
    for (int i = 0; i < dec.size(); i++) {
      if (i < location) {
        integralDec += dec[i];
      }
      if (i > location) {
        floatDec += dec[i];
      }
    }
    char intPart[integralDec.size()];
    char floatPart[floatDec.size()];
    strcpy(intPart, integralDec.c_str());
    strcpy(floatPart, floatDec.c_str());
    std::string binaryNo = decimalToBinary(intPart, floatPart);
    return binaryNo;
  }
  char decimalNo[dec.size()];
  strcpy(decimalNo, dec.c_str());
  std::string binaryNo = decimalToBinary(decimalNo);
  return binaryNo;
}

// converts a hexadecimal number to octal number
std::string NumberConverter::hexadecimalToOctal(char *hexadecimalNo,
                                                char *floatHexadecimalNo) {
  std::string dec = hexadecimalToDecimal(hexadecimalNo, floatHexadecimalNo);
  unsigned int location = dec.find(".");
  int length = dec.length();
  if (location < length) {
    std::string integralDec = "";
    std::string floatDec = "";
    for (int i = 0; i < dec.size(); i++) {
      if (i < location) {
        integralDec += dec[i];
      }
      if (i > location) {
        floatDec += dec[i];
      }
    }
    char intPart[integralDec.size()];
    char floatPart[floatDec.size()];
    strcpy(intPart, integralDec.c_str());
    strcpy(floatPart, floatDec.c_str());
    std::string octalNo = decimalToOctal(intPart, floatPart);
    return octalNo;
  }
  char decimalNo[dec.size()];
  strcpy(decimalNo, dec.c_str());
  std::string octalNo = decimalToOctal(decimalNo);
  return octalNo;
}
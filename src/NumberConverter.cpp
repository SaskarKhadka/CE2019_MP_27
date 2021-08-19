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
  unsigned int location = binaryNo.find(".");
  int length = binaryNo.length();

  if (location < length)
    throw "Only integers are allowed";

  unsigned long long binary;
  try {
    binary = stoull(binaryNo, nullptr, 10);
  } catch (const std::out_of_range &error) {
    throw "Only 19 digit numbers are allowed for binary manipulations";
  } catch (const std::invalid_argument &error) {
    return false;
  }

  bool isValid = false;
  for (int i = 0; i < length; i++) {
    isValid = binaryNo[i] == '0' || binaryNo[i] == '1' ? true : false;
    if (!isValid)
      return false;
  }
  return true;
}

// checks if the given decimal number is valid
bool NumberConverter::isDecimalNumberValid(std::string decimalNo) {
  unsigned int location = decimalNo.find(".");
  int length = decimalNo.length();

  if (location < length)
    throw "Only integers are allowed";

  unsigned long long decimal;
  try {
    decimal = stoull(decimalNo, nullptr, 10);
  } catch (const std::out_of_range &error) {
    throw "Only 19 digit numbers are allowed for decimal manipulations";
  } catch (const std::invalid_argument &error) {
    return false;
  }

  bool isValid = false;
  for (int i = 0; i < length; i++) {
    isValid = (decimalNo[i] >= 48 && decimalNo[i] <= 57) ? true : false;
    if (!isValid)
      return false;
  }
  return true;
}

// checks if the given octal number is valid
bool NumberConverter::isOctalNumberValid(std::string octalNo) {
  unsigned int location = octalNo.find(".");
  int length = octalNo.length();

  if (location < length)
    throw "Only integers are allowed";

  unsigned long long octal;
  try {
    octal = stoull(octalNo, nullptr, 10);
  } catch (const std::out_of_range &error) {
    throw "Only 19 digit numbers are allowed for octal manipulations";
  } catch (const std::invalid_argument &error) {
    return false;
  }

  bool isValid = false;
  for (int i = 0; i < length; i++) {
    isValid = (octalNo[i] >= 48 && octalNo[i] <= 55) ? true : false;
    if (!isValid)
      return false;
  }
  return true;
}

// checks if the given hexadecimal number is valid
bool NumberConverter::isHexadecimalNumberValid(std::string hexadecimalNo) {
  int length = hexadecimalNo.length();
  unsigned int location = hexadecimalNo.find(".");

  if (length > 15)
    throw "Only 15 digit numbers are allowed for hexadecimal manipulations";

  if (location < length)
    throw "Only integers are allowed";

  bool isValid = false;
  for (int i = length - 1; i >= 0; i--) {

    isValid = (hexadecimalNo[i] >= 48 && hexadecimalNo[i] <= 57)    ? true
              : (hexadecimalNo[i] >= 65 && hexadecimalNo[i] <= 70)  ? true
              : (hexadecimalNo[i] >= 97 && hexadecimalNo[i] <= 102) ? true
                                                                    : false;
    if (!isValid)
      return false;
  }
  return isValid;
}

// converts a decimal number to binary number
std::string NumberConverter::decimalToBinary(unsigned long long decimalNo) {
  unsigned long long decimal = decimalNo;
  // unsigned long long decimal = strtoull(decimalNo, nullptr, 10);
  if (decimal == 0)
    return "0";
  while (decimal != 0) {
    int rem = decimal % 2;
    stack.push(rem);
    decimal = decimal / 2;
  }
  std::string binaryNo = "";
  while (!stack.isEmpty()) {
    int binary = stack.top();
    binaryNo += std::to_string(binary);
    stack.pop();
  }
  return binaryNo;
}

// converts a decimal number to octal number
std::string NumberConverter::decimalToOctal(unsigned long long decimalNo) {
  unsigned long long decimal = decimalNo;
  // unsigned long long decimal = strtoull(decimalNo, nullptr, 10);
  if (decimal == 0)
    return "0";
  while (decimal != 0) {
    int rem = decimal % 8;
    stack.push(rem);
    decimal = decimal / 8;
  }
  std::string octalNo = "";
  while (!stack.isEmpty()) {
    int octal = stack.top();
    octalNo += std::to_string(octal);
    stack.pop();
  }
  return octalNo;
}

// converts a decimal number to hexadecimal number
std::string
NumberConverter::decimalToHexadecimal(unsigned long long decimalNo) {
  unsigned long long decimal = decimalNo;
  // unsigned long long decimal = strtoull(decimalNo, nullptr, 10);
  if (decimal == 0)
    return "0";
  while (decimal != 0) {
    int rem = decimal % 16;
    stack.push(rem);
    decimal = decimal / 16;
  }
  char charHex;
  std::string hexadecimalNo = "";
  while (!stack.isEmpty()) {
    int hex = stack.top();
    if (hex <= 9)
      charHex = hex + '0';
    else
      charHex = hex + '7';

    hexadecimalNo += charHex;
    stack.pop();
  }
  return hexadecimalNo;
}

// converts a binary number to decimal number
unsigned int NumberConverter::binaryToDecimal(unsigned long long binaryNo) {
  int power = 0;

  while (binaryNo != 0) {
    int rem = binaryNo % 10;
    unsigned int decimal = rem * pow(2, power);
    int decimalNew = stack.isEmpty() ? decimal : (stack.pop() + decimal);
    stack.push(decimalNew);
    binaryNo /= 10;
    power++;
  }

  unsigned int decimalNo = stack.isEmpty() ? 0 : stack.pop();
  return decimalNo;
}

// converts a binary number to octal number
std::string NumberConverter::binaryToOctal(unsigned long long binaryNo) {
  unsigned int decimal = binaryToDecimal(binaryNo);
  std::string octalNo = decimalToOctal(decimal);
  return octalNo;
}

// converts a binary number to hexadecimal number
std::string NumberConverter::binaryToHexadecimal(unsigned long long binaryNo) {
  unsigned int decimal = binaryToDecimal(binaryNo);
  std::string dec = std::to_string(decimal);
  std::string octalNo = decimalToHexadecimal(decimal);
  return octalNo;
}

// converts a octal number to decimal number
unsigned long long NumberConverter::octalToDecimal(unsigned long long octalNo) {
  // int length = strlen(octalNo);
  int power = 0;
  while (octalNo != 0) {
    int rem = octalNo % 10;
    unsigned long long decimal = rem * pow(8, power);
    unsigned long long decimalNew =
        stack.isEmpty() ? decimal : (stack.pop() + decimal);
    stack.push(decimalNew);
    octalNo /= 10;
    power++;
  }

  unsigned long long decimalNo = stack.isEmpty() ? 0 : stack.pop();

  return decimalNo;
}

// converts a octal number to binary number
std::string NumberConverter::octalToBinary(unsigned long long octalNo) {
  unsigned long long decimal = octalToDecimal(octalNo);
  std::string binaryNo = decimalToBinary(decimal);
  return binaryNo;
}

// converts a octal number to hexadecimal number
std::string NumberConverter::octalToHexadecimal(unsigned long long octalNo) {
  unsigned long long decimal = octalToDecimal(octalNo);
  std::string hexadecimalNo = decimalToHexadecimal(decimal);
  return hexadecimalNo;
}

// converts a hexadecimal number to decimal number
unsigned long long
NumberConverter::hexadecimalToDecimal(std::string hexadecimalNo) {
  int length = hexadecimalNo.length();
  int power = 0;
  int hexNum;

  for (int i = length - 1; i >= 0; i--) {
    // int rem = hexadecimalNo % 10;

    if (hexadecimalNo[i] >= 48 && hexadecimalNo[i] <= 57)
      hexNum = hexadecimalNo[i] - '0';
    else if (hexadecimalNo[i] >= 97 && hexadecimalNo[i] <= 102)
      hexNum = hexadecimalNo[i] - 'a' + 10;
    else
      hexNum = hexadecimalNo[i] - 'A' + 10;

    unsigned long long decimal = hexNum * pow(16, power);
    unsigned long long decimalNew =
        stack.isEmpty() ? decimal : (stack.pop() + decimal);
    stack.push(decimalNew);
    power++;
  }

  unsigned long long decimalNo = stack.pop();
  return decimalNo;
}

// converts a hexadecimal number to binary number
std::string NumberConverter::hexadecimalToBinary(std::string hexadecimalNo) {
  unsigned long long decimal = hexadecimalToDecimal(hexadecimalNo);
  std::string binaryNo = decimalToBinary(decimal);
  return binaryNo;
}

// converts a hexadecimal number to octal number
std::string NumberConverter::hexadecimalToOctal(std::string hexadecimalNo) {
  unsigned long long decimal = hexadecimalToDecimal(hexadecimalNo);
  std::string octalNo = decimalToOctal(decimal);
  return octalNo;
}
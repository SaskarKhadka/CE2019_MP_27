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

  if (location < length) // checks if the number contains a decimal point
    throw "Only positive integers are allowed";

  unsigned long long binary;
  // checks if the number is within the said range or not
  try {
    binary = stoull(binaryNo, nullptr, 10);
    if (binary > 9999999999999999999U)
      throw std::out_of_range("Out of range");

  } catch (const std::out_of_range &error) {
    throw "Only 19 digit numbers are allowed for binary manipulations";
  } catch (const std::invalid_argument &error) {
    return false;
  }

  bool isValid = false;
  // checks if all the digits of the number are valid or not
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

  if (location < length) // checks if the number contains a decimal point
    throw "Only positive integers are allowed";

  unsigned long long decimal;
  // checks if the number is within the said range not
  try {
    decimal = stoull(decimalNo, nullptr, 10);
    if (decimal > 9999999999999999999U)
      throw std::out_of_range("Out of range");

  } catch (const std::out_of_range &error) {
    throw "Only 19 digit numbers are allowed for decimal manipulations";
  } catch (const std::invalid_argument &error) {
    return false;
  }

  bool isValid = false;
  // checks if all the digits of the number are valid or not
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

  if (location < length) // checks if the number contains a decimal point
    throw "Only positive integers are allowed";

  unsigned long long octal;
  // checks if the number is within the said range not
  try {
    octal = stoull(octalNo, nullptr, 10);
    if (octal > 9999999999999999999U)
      throw std::out_of_range("Out of range");

  } catch (const std::out_of_range &error) {
    throw "Only 19 digit numbers are allowed for octal manipulations";
  } catch (const std::invalid_argument &error) {
    return false;
  }

  bool isValid = false;
  // checks if all the digits of the number are valid or not
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

  if (location < length) // checks if the number contains a decimal point
    throw "Only positive integers are allowed";

  // checks if the number is within the said range or not
  if (length > 15)
    throw "Only 15 digit numbers are allowed for hexadecimal manipulations";

  bool isValid = false;
  // checks if all the digits of the number are valid or not
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
  if (decimalNo == 0)
    return "0"; // if the input number 0, return 0

  /* Divide the  decimal number by 2 and push the remainder
  into the stack until the decimalNo is 0
  */
  while (decimalNo != 0) {
    int rem = decimalNo % 2;
    stack.push(rem);
    decimalNo = decimalNo / 2;
  }
  std::string binaryNo = "";

  /* Pop the stack continuously until it is empty and
   update the binary number in the process
   */
  while (!stack.isEmpty()) {
    int binary = stack.top();
    binaryNo += std::to_string(binary);
    stack.pop();
  }
  return binaryNo;
}

// converts a decimal number to octal number
std::string NumberConverter::decimalToOctal(unsigned long long decimalNo) {
  if (decimalNo == 0)
    return "0";

  /* Divide the  decimal number by 8 and push the remainder
   into the stack until the decimalNo is 0
  */
  while (decimalNo != 0) {
    int rem = decimalNo % 8;
    stack.push(rem);
    decimalNo = decimalNo / 8;
  }
  std::string octalNo = "";

  /* Pop the stack continuously until it is empty and
  update the octal number in the process
  */
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
  if (decimalNo == 0)
    return "0";

  /* Divide the  decimal number by 16 and push the remainder
  into the stack until the decimalNo is 0
  */
  while (decimalNo != 0) {
    int rem = decimalNo % 16;
    stack.push(rem);
    decimalNo = decimalNo / 16;
  }
  char charHex;
  std::string hexadecimalNo = "";

  /* Pop the stack continuously until it is empty and
  update the hexadecimal number in the process
  */
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

  /* Take each digit starting from the last and
  update the decimal equivalent in the stack
   */
  while (binaryNo != 0) {
    int rem = binaryNo % 10; // take out the last digit
    unsigned int decimal = rem * pow(2, power);

    int decimalNew = stack.isEmpty() ? decimal : (stack.pop() + decimal);
    stack.push(decimalNew);
    binaryNo /= 10; // throw away the last digit
    power++;
  }

  unsigned int decimalNo = stack.isEmpty() ? 0 : stack.pop();
  return decimalNo;
}

// converts a binary number to octal number
std::string NumberConverter::binaryToOctal(unsigned long long binaryNo) {
  // Firstly, we convert the binary number into decimal
  unsigned int decimal = binaryToDecimal(binaryNo);

  // Then we convert the decimal number into octal
  std::string octalNo = decimalToOctal(decimal);
  return octalNo;
}

// converts a binary number to hexadecimal number
std::string NumberConverter::binaryToHexadecimal(unsigned long long binaryNo) {
  unsigned int decimal = binaryToDecimal(binaryNo);
  std::string octalNo = decimalToHexadecimal(decimal);
  return octalNo;
}

// converts a octal number to decimal number
unsigned long long NumberConverter::octalToDecimal(unsigned long long octalNo) {

  int power = 0;

  /* Take each digit starting from the last and
  update the decimal equivalent in the stack
  */
  while (octalNo != 0) {
    int rem = octalNo % 10; // take out the last digit
    unsigned long long decimal = rem * pow(8, power);
    unsigned long long decimalNew =
        stack.isEmpty() ? decimal : (stack.pop() + decimal);
    stack.push(decimalNew);
    octalNo /= 10; // throw away the last digit
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

  /* Take each digit starting from the last and
  update the decimal equivalent in the stack
   */
  for (int i = length - 1; i >= 0; i--) {
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
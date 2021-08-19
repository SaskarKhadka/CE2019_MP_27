#pragma once

#include "Stack.h"
#include <iostream>

class NumberConverter {
  LinkedStack<unsigned long long> stack;

public:
  // Constructor
  NumberConverter() {}

  // checks if the given binary number is valid
  bool isBinaryNumberValid(std::string binaryNo);

  // checks if the given decimal number is valid
  bool isDecimalNumberValid(std::string decimalNo);

  // checks if the given octal number is valid
  bool isOctalNumberValid(std::string octalNo);

  // checks if the given hexadecimal number is valid
  bool isHexadecimalNumberValid(std::string hexadecimalNo);

  // converts a decimal number to binary number
  std::string decimalToBinary(unsigned long long decimalNo);

  // converts a decimal number to octal number
  std::string decimalToOctal(unsigned long long decimalNo);

  // converts a decimal number to hexadecimal number
  std::string decimalToHexadecimal(unsigned long long decimalNo);

  // converts a binary number to decimal number
  unsigned int binaryToDecimal(unsigned long long binaryNo);

  // converts a binary number to octal number
  std::string binaryToOctal(unsigned long long binaryNo);

  // converts a binary number to hexadecimal number
  std::string binaryToHexadecimal(unsigned long long binaryNo);

  // converts a octal number to decimal number
  unsigned long long octalToDecimal(unsigned long long octalNo);

  // converts a octal number to binary number
  std::string octalToBinary(unsigned long long octalNo);

  // converts a octal number to hexadecimal number
  std::string octalToHexadecimal(unsigned long long octalNo);

  // converts a hexadecimal number to decimal number
  unsigned long long hexadecimalToDecimal(std::string hexadecimalNo);

  // converts a hexadecimal number to binary number
  std::string hexadecimalToBinary(std::string hexadecimalNo);

  // converts a hexadecimal number to octal number
  std::string hexadecimalToOctal(std::string hexadecimalNo);
};
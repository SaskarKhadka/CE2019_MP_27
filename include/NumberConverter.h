#pragma once

#include "Stack.h"
#include <iostream>

class NumberConverter {
  LinkedStack stack;

public:
  // Constructor
  NumberConverter() {}

  // checks if the given binary number is valid
  bool isBinaryNumberValid(char *binaryNo);

  // checks if the given decimal number is valid
  bool isDecimalNumberValid(char *decimalNo);

  // checks if the given octal number is valid
  bool isOctalNumberValid(char *octalNo);

  // checks if the given hexadecimal number is valid
  bool isHexadecimalNumberValid(char *hexadecimalNo);

  // converts a decimal number to binary number
  std::string decimalToBinary(char *decimalNo, char *floatDecimal = nullptr);

  // converts a decimal number to octal number
  std::string decimalToOctal(char *decimalNo, char *floatDecimal = nullptr);

  // converts a decimal number to hexadecimal number
  std::string decimalToHexadecimal(char *decimalNo,
                                   char *floatDecimal = nullptr);

  // converts a binary number to decimal number
  unsigned int binaryToDecimal(char *binaryNo);

  // converts a binary number to octal number
  std::string binaryToOctal(char *binaryNo);

  // converts a binary number to hexadecimal number
  std::string binaryToHexadecimal(char *binaryNo);

  // converts a octal number to decimal number
  unsigned long long octalToDecimal(char *octalNo);

  // converts a octal number to binary number
  std::string octalToBinary(char *octalNo);

  // converts a octal number to hexadecimal number
  std::string octalToHexadecimal(char *octalNo);

  // converts a hexadecimal number to decimal number
  unsigned long long hexadecimalToDecimal(char *hexadecimalNo);

  // converts a hexadecimal number to binary number
  std::string hexadecimalToBinary(char *hexadecimalNo);

  // converts a hexadecimal number to octal number
  std::string hexadecimalToOctal(char *hexadecimalNo);
};
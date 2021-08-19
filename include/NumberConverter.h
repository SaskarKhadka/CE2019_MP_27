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
  std::string decimalToBinary(char *decimalNo, char *floatDecimalNo = nullptr);

  // converts a decimal number to octal number
  std::string decimalToOctal(char *decimalNo, char *floatDecimalNo = nullptr);

  // converts a decimal number to hexadecimal number
  std::string decimalToHexadecimal(char *decimalNo,
                                   char *floatDecimalNo = nullptr);

  // converts a binary number to decimal number
  std::string binaryToDecimal(char *binaryNo, char *floatBinaryNo = nullptr);

  // converts a binary number to octal number
  std::string binaryToOctal(char *binaryNo, char *floatBinaryNo = nullptr);

  // converts a binary number to hexadecimal number
  std::string binaryToHexadecimal(char *binaryNo,
                                  char *floatBinaryNo = nullptr);

  // converts a octal number to decimal number
  std::string octalToDecimal(char *octalNo, char *floatOctalNo = nullptr);

  // converts a octal number to binary number
  std::string octalToBinary(char *octalNo, char *floatOctalNo = nullptr);

  // converts a octal number to hexadecimal number
  std::string octalToHexadecimal(char *octalNo, char *floatOctalNo = nullptr);

  // converts a hexadecimal number to decimal number
  std::string hexadecimalToDecimal(char *hexadecimalNo, char *floatHexadecimalNo = nullptr);

  // converts a hexadecimal number to binary number
  std::string hexadecimalToBinary(char *hexadecimalNo, char *floatHexadecimalNo = nullptr);

  // converts a hexadecimal number to octal number
  std::string hexadecimalToOctal(char *hexadecimalNo, char *floatHexadecimalNo = nullptr);
};
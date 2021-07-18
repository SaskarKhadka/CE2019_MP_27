#pragma once

#include "Stack.h"
#include <iostream>

class NumberConverter {
  LinkedStack stack;

public:
  // Constructor
  NumberConverter() {}

  // checks if the given binary number is valid
  bool isBinaryNumberValid(char* binaryNo);

  // checks if the given decimal number is valid
  bool isDecimalNumberValid(char* decimalNo);

  // checks if the given octal number is valid
  bool isOctalNumberValid(char* octalNo);

  // checks if the given hexadecimal number is valid
  bool isHexadecimalNumberValid(char *hexadecimalNo);

  // converts a decimal number to binary number
  int decimalToBinary(char *decimalNo);

  // converts a decimal number to octal number
  int decimalToOctal(char *decimalNo);

  // converts a decimal number to hexadecimal number
  std::string decimalToHexadecimal(char *decimalNo);

  // converts a binary number to decimal number
  int binaryToDecimal(char *binaryNo);

  // converts a binary number to octal number
  int binaryToOctal(char *binaryNo);

  // converts a binary number to hexadecimal number
  std::string binaryToHexadecimal(char *binaryNo);

  // converts a octal number to decimal number
  int octalToDecimal(char *octalNo);

  // converts a octal number to binary number
  int octalToBinary(char *octalNo);

  // converts a octal number to hexadecimal number
  std::string octalToHexadecimal(char *octalNo);

  // converts a hexadecimal number to decimal number
  int hexadecimalToDecimal(char *hexadecimalNo);

  // converts a hexadecimal number to binary number
  int hexadecimalToBinary(char *hexadecimalNo);

  // converts a hexadecimal number to octal number
  int hexadecimalToOctal(char *hexadecimalNo);
};
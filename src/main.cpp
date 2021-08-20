#include "../include/LinkedList.h"
#include "../include/NumberConverter.h"
#include <iostream>
#include <math.h>
// Actual Number conversion
void convert(NumberConverter &numConverter, std::string &code,
             std::string value) {
  unsigned long long integral;
  if (code[0] != '3')
    integral = stoull(value, nullptr, 10);

  if (code == "01")
    std::cout << "The Binary number is: "
              << numConverter.decimalToBinary(integral);

  else if (code == "02")
    std::cout << "The Octal number is: "
              << numConverter.decimalToOctal(integral);

  else if (code == "03")
    std::cout << "The Hexadecimal number is: "
              << numConverter.decimalToHexadecimal(integral);

  else if (code == "10")
    std::cout << "The Decimal number is: "
              << numConverter.binaryToDecimal(integral);

  else if (code == "12")
    std::cout << "The Octal number is: "
              << numConverter.binaryToOctal(integral);

  else if (code == "13")
    std::cout << "The Hexadecimal number is: "
              << numConverter.binaryToHexadecimal(integral);

  else if (code == "20")
    std::cout << "The Decimal number is: "
              << numConverter.octalToDecimal(integral);

  else if (code == "21")
    std::cout << "The Binary number is: "
              << numConverter.octalToBinary(integral);

  else if (code == "23")
    std::cout << "The Hexadecimal number is: "
              << numConverter.octalToHexadecimal(integral);

  else if (code == "30")
    std::cout << "The Decimal number is: "
              << numConverter.hexadecimalToDecimal(value);

  else if (code == "31")
    std::cout << "The Binary number is: "
              << numConverter.hexadecimalToBinary(value);

  else if (code == "32")
    std::cout << "The Octal number is: "
              << numConverter.hexadecimalToOctal(value);

  else
    throw "Couldn't convert! Looks like you entered a wrong code";
}

int main() {
  NumberConverter numConverter;

  std::cout << "                             __   __  __      __  __           "
               "  __  __  ___  __  __"
            << std::endl;
  std::cout << "           |\\ |  |  |  |\\/| |__| |__ |__|    |   |  | |\\ | "
               "\\  / |__ |__|  |  |__ |__|"
            << std::endl;
  std::cout << "           | \\|  |__|  |  | |__| |__ |\\_     |__ |__| | \\|  "
               "\\/  |__ |\\_   |  |__ |\\_"
            << std::endl;
  // }
  std::cout << "\n\n";

  std::cout << "NOTE: (Decimal = 0, Binary = 1, Octal = 2, Hexadecimal = 3)"
            << std::endl;
  std::cout << "\n";

  while (true) {
    std::string from;
    std::string to;
    std::string number;
    bool isValid;
    try {
      // std::cout.precision(3);
      std::cout << "\nConvert From: ";
      std::cin >> from;
      std::cout << "Convert To: ";
      std::cin >> to;

      std::string code = from + to;
      if (code == "00" || code == "11" || code == "22" || code == "33")
        throw "\nInvalid Conversions";

      if (from == "0") {
        std::cout << "\nEnter your decimal number: ";
        std::cin >> number;
        isValid = numConverter.isDecimalNumberValid(number);
      } else if (from == "1") {
        std::cout << "\nEnter your binary number: ";
        std::cin >> number;
        isValid = numConverter.isBinaryNumberValid(number);
      } else if (from == "2") {
        std::cout << "\nEnter your octal number: ";
        std::cin >> number;
        isValid = numConverter.isOctalNumberValid(number);
      } else if (from == "3") {
        std::cout << "\nEnter your Hexadecimal number: ";
        std::cin >> number;
        isValid = numConverter.isHexadecimalNumberValid(number);
      } else {
        throw "\nLooks like you entered a wrong code";
        // break;
      }

      if (!isValid)
        throw "Your number is invalid";

      convert(numConverter, code, number);

      std::cout << "\n";
    } catch (const char *error) {
      std::cout << error << std::endl;
    }
    std::string again;
    std::cout << "\nDo you wish to continue?(Press Y/y to continue) ";
    std::cin >> again;

    if (again == "y" || again == "Y")
      continue;
    else
      break;
  }
}

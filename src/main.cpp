#include "../include/LinkedList.h"
#include "../include/NumberConverter.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

void convert(NumberConverter &numConverter, std::string &code, char *integral,
             char *floating = nullptr) {
  if (code == "01") {
    std::cout << "The Binary number is: "
              << numConverter.decimalToBinary(integral, floating) << std::endl;
  } else if (code == "02") {
    std::cout << "The Octal number is: "
              << numConverter.decimalToOctal(integral, floating) << std::endl;
  } else if (code == "03") {
    std::cout << "The Hexadecimal number is: "
              << numConverter.decimalToHexadecimal(integral, floating)
              << std::endl;
  } else if (code == "10") {
    std::cout << "The Decimal number is: "
              << numConverter.binaryToDecimal(integral, floating) << std::endl;
  } else if (code == "12") {
    std::cout << "The Octal number is: "
              << numConverter.binaryToOctal(integral, floating) << std::endl;
  } else if (code == "13") {
    std::cout << "The Hexadecimal number is: "
              << numConverter.binaryToHexadecimal(integral, floating)
              << std::endl;
  } else if (code == "20") {
    std::cout << "The Decimal number is: "
              << numConverter.octalToDecimal(integral, floating) << std::endl;
  } else if (code == "21") {
    std::cout << "The Binary number is: "
              << numConverter.octalToBinary(integral, floating) << std::endl;
  } else if (code == "23") {
    std::cout << "The Hexadecimal number is: "
              << numConverter.octalToHexadecimal(integral, floating)
              << std::endl;
  } else if (code == "30") {
    std::cout << "The Decimal number is: "
              << numConverter.hexadecimalToDecimal(integral, floating)
              << std::endl;
  } else if (code == "31") {
    std::cout << "The Binary number is: "
              << numConverter.hexadecimalToBinary(integral, floating)
              << std::endl;
  } else if (code == "32") {
    std::cout << "The Octal number is: "
              << numConverter.hexadecimalToOctal(integral, floating)
              << std::endl;
  } else {
    throw "\nCouldn't convert! Looks like you entered a wrong code\n";
  }
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
  std::cout << "\n\n";

  while (true) {
    std::string from;
    std::string to;
    std::string number;
    bool isValid;
    try {
      std::cout.precision(6);
      std::cout << "Convert From: ";
      std::cin >> from;
      std::cout << "Convert To: ";
      std::cin >> to;

      if (from == "0") {
        std::cout << "Enter your decimal number: ";
        std::cin >> number;
        isValid = numConverter.isDecimalNumberValid(number);
      } else if (from == "1") {
        std::cout << "Enter your binary number: ";
        std::cin >> number;
        isValid = numConverter.isBinaryNumberValid(number);
      } else if (from == "2") {
        std::cout << "Enter your octal number: ";
        std::cin >> number;
        isValid = numConverter.isOctalNumberValid(number);
      } else if (from == "3") {
        std::cout << "Enter your Hexadecimal number: ";
        std::cin >> number;
        isValid = numConverter.isHexadecimalNumberValid(number);
      } else {
        throw "\nLooks like you entered a wrong code\n";
        // break;
      }

      if (!isValid)
        throw "Your number is invalid";


      std::string code = from + to;

      if(code == "00" || code == "11"|| code == "22"|| code == "33")
        throw "\nInvalid Conversion\ns";

      int length = number.length();
      char b[length];
      strcpy(b, number.c_str());
      unsigned int location = number.find(".");
      if (location == length - 1) {
        number.replace(number.size() - 1, number.size(), "");
        char num[number.size()];
        strcpy(num, number.c_str());
        convert(numConverter, code, num);
      } else if (location == 0) {
        number.replace(0, 1, "");
        char num[number.size()];
        strcpy(num, number.c_str());
        convert(numConverter, code, nullptr, num);
      } else if (location < length) {
        std::string integral = "";
        std::string floating = "";
        for (int i = 0; i < length; i++) {
          if (i < location) {
            integral += b[i];
          }
          if (i > location) {
            floating += b[i];
          }
        }

        char intPart[integral.size()];
        char floatPart[floating.size()];

        strcpy(intPart, integral.c_str());
        strcpy(floatPart, floating.c_str());

        convert(numConverter, code, intPart, floatPart);
      } else {
        convert(numConverter, code, b);
      }

      std::string again;
      std::cout << "Do you wish to continue?(Press Y/y to continue) ";
      std::cin >> again;

      if (again == "y" || again == "Y")
        continue;
      else
        break;

    } catch (const char *error) {
      std::cout << error << std::endl;
      std::string again;
      std::cout << "Do you wish to continue?(Press Y/y to continue) ";
      std::cin >> again;

      if (again == "y" || again == "Y")
        continue;
      else
        break;
      // break;
    }
  }
}

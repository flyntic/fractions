// ConsoleFraction.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "cFraction.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    cFraction fraction1;
    cFraction fraction2;
    std::cout << fraction1 << "\n";
    std::cout << fraction2  << "\n";
    std::cout << fraction1 << " + " << fraction2 << " = " << fraction1 + fraction2 << "\n";
    std::cout << fraction1 << " - " << fraction2 << " = " << fraction1 - fraction2 << "\n";
    std::cout << fraction1 << " * " << fraction2 << " = " << fraction1 * fraction2 << "\n";

    std::cout << fraction1 << " + " << fraction2 << " + " << fraction2 << " = " << fraction1 + fraction2 + fraction2 << "\n";
    std::cout << fraction1 << " - " << fraction2 << " - " << fraction2 << " = " << fraction1 - fraction2 - fraction2 << "\n";
    std::cout << fraction1 << " * " << fraction2 << " * " << fraction2 << " = " << fraction1 * fraction2 * fraction2 << "\n";

    std::cout << fraction1 << " + " << 5<<" + " << 15 << " = " << fraction1 + 5 + 15 << "\n";
    std::cout << fraction1 << " - " << 5<<" - " << 15 << " = " << fraction1 - 5 - 15 << "\n";
    std::cout << fraction1 << " * " << 5<<" * " << 15 << " = " << fraction1 * 5 * 15 << "\n";

  // std::cout << 5 << " + " << fraction1 << " = " <<5 + fraction1   << "\n";
  // std::cout << 5 << " - " << fraction1 << " = " <<5 - fraction1   << "\n";
  // std::cout << 5 << " * " << fraction1 << " = " <<5 * fraction1   << "\n";
}

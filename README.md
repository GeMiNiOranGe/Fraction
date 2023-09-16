<p align="center">
  <a href="https://code.visualstudio.com/">
    <img alt="Editor" src="https://img.shields.io/badge/Editor-VSCode-0066bb">
  </a>
  <a href="https://www.msys2.org/">
    <img alt="Compiler" src="https://img.shields.io/badge/Compiler-Mingw64_of_MSYS2-7F00FF">
  </a>
</p>

# Fraction
This library supports the calculation of a fraction

## What can the fraction class do
The fraction class is overloaded with the following operators
- Move/Copy-assignment operator
- Bitshift operators (used for Stream I/O)
- Comparison operators (==, !=, >, <, >=, <=)
- Binary arithmetic operators (+, -, *, /, +=, -=, *=, /=)

It can perform calculations with other Fractions/Integers

## How to Install and Run the Project
Open terminal with Visual Studio Code and run the command line below
```cmd
mingw32-make run
```

## Sample code
Binary arithmetic operators
```cpp
#include "fraction.hpp"

int main() {
    Fraction result, first(12, 9), second(2, 7);
    result = first + second + 2;
    std::cout << result;
    return 0;
}
```

Comparison operators
```cpp
#include "fraction.hpp"

int main() {
    Fraction first(42, 9), second(2, 23);
    std::cout << (first == second ? "equal" : "not equal");
    return 0;
}
```

Typecast operator
```cpp
#include "fraction.hpp"

int main() {
    Fraction first(5, 2);
    double number = 3.6;
    number += first;
    std::cout << number;
    return 0;
}
```
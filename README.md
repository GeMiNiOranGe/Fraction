<p align="center">
  <a style="text-decoration: none" href="https://code.visualstudio.com/">
    <img alt="Editor" src="https://img.shields.io/badge/Editor-VSCode-007acc">
  </a>
  <a style="text-decoration: none" href="https://www.msys2.org/">
    <img alt="Compiler" src="https://img.shields.io/badge/Compiler-Mingw64_of_MSYS2-7F00FF">
  </a>
  <a style="text-decoration: none" href="https://en.cppreference.com/w/cpp/20">
    <img alt="Static Badge" src="https://img.shields.io/badge/C%2B%2B-20-00599c">
  </a>
</p>

# Fraction
This library supports the calculation of a fraction

**NOTE:** Fraction supports from `C++20` to latest

## What can the fraction class do
The fraction class is overloaded with the following operators
- Move/Copy-assignment operator
- Input/Output operators
- Comparison operators (`==`, `!=`, `>`, `<`, `>=`, `<=`)
- Binary arithmetic operators (`+`, `-`, `*`, `/`, `+=`, `-=`, `*=`, `/=`)

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
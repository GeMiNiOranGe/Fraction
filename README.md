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

> Note: Fraction supports from `C++20` to latest

## What can the fraction class do
The fraction class is overloaded with the following operators
- Move/Copy-assignment operator
- Input/Output operators
- Comparison operators (`==`, `!=`, `>`, `<`, `>=`, `<=`)
- Binary arithmetic operators (`+`, `-`, `*`, `/`, `+=`, `-=`, `*=`, `/=`)

It can be calculated with other Fractions/Integers

## How to Install
Open terminal with Visual Studio Code and run the command line below
```cmd
mingw32-make
```

### Full example code
You can read more examples [here](examples).
```cmd
mingw32-make build-examples
```
```cmd
.\bin\<example-file-name>_example.exe
```

## Sample code
### Binary arithmetic operators
```cpp
#include "fraction.hpp"

int main() {
    Fraction result, first(12, 9), second(2, 7), third(3, 4);
    result = first + second + 2;
    result *= 3;
    result -= 4 / third;
    std::cout << result;
    return 0;
}
```

### Comparison operators
```cpp
#include "fraction.hpp"

int main() {
    Fraction first(42, 9), second(2, 23);
    std::cout << (first == second ? "equal" : "not equal") << std::endl;
    std::cout << (second < 1 ? "less than" : "not less than") << std::endl;
    std::cout << (5 > first ? "greater than" : "not greater than") << std::endl;
    return 0;
}
```

### Typecast operator
```cpp
#include "fraction.hpp"

int main() {
    Fraction first(5, 2);
    double number = 3.6;
    number += static_cast<double>(first);
    // Or: number += first.to_double();
    std::cout << number;
    return 0;
}
```

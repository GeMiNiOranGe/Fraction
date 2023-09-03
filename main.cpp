#include "fraction.hpp"

int main() {
    Fraction first, second, third(1, 2), fourth(3, 4);
    std::cout << "please enter the fraction: ";
    std::cin >> first;
    std::cout << "please enter the fraction: ";
    std::cin >> second;
    std::cout << '\n';

    if (first.get_denominator() == 0 || second.get_denominator() == 0)
        std::cout << "Calculation error..." << '\n';
    else {
        std::cout << "Summation of 2 fractions is: " << first + second << '\n';
        std::cout << "Subtraction of 2 fractions is: " << first - second << '\n';
        std::cout << "Multiplication of 2 fractions is: " << first * second << '\n';
        std::cout << "Division of 2 fractions is: ";
        Fraction result = first / second;
        result.get_denominator() == 0
            ? std::cout << "Calculation error..." << '\n'
            : std::cout << first / second << '\n';
    }
    std::cout << '\n';

    std::cout << "Init third(1, 2), fourth(3, 4)" << '\n';
    third += fourth;
    std::cout << "Execute: third += fourth | the result of third is: " << third;
    std::cout << '\n';
    return 0;
}
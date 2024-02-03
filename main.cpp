#include "fraction.hpp"

int main() {
    Fraction first, second, third(1, 2), fourth(3, 4);
    std::cout << "Please enter the first fraction: ";
    std::cin >> first;
    std::cout << "Please enter the second fraction: ";
    std::cin >> second;
    std::cout << std::endl;

    if (first.get_denominator() == 0 || second.get_denominator() == 0)
        std::cout << "Error..." << std::endl;
    else {
        std::cout << "(" << first << ") + (" << second << ") = " << first + second << std::endl;
        std::cout << "(" << first << ") - (" << second << ") = " << first - second << std::endl;
        std::cout << "(" << first << ") * (" << second << ") = " << first * second << std::endl;
        std::cout << "(" << first << ") / (" << second << ") = ";
        Fraction result = first / second;
        result.get_denominator() == 0
            ? std::cout << "Error..." << std::endl
            : std::cout << first / second << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Init third(" << third << "), fourth(" << fourth << ")" << std::endl;
    third += fourth;
    std::cout << "Execute: third += fourth | the result of third is: " << third << std::endl;
    return 0;
}
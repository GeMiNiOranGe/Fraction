#include "fraction.hpp"

int main(int argc, char const *argv[]) {
    Fraction first, second, third(1, 2), fourth(3, 4);
    std::cout << "Please enter the first fraction: ";
    std::cin >> first;
    std::cout << "Please enter the second fraction: ";
    std::cin >> second;
    std::cout << std::endl;

    first.simplify();
    second.simplify();

    bool is_first_valid = is_valid_fraction(first);
    bool is_second_valid = is_valid_fraction(second);

    if (is_first_valid && is_second_valid) {
        std::cout << "(" << first << ") + (" << second << ") = " << first + second << std::endl;
        std::cout << "(" << first << ") - (" << second << ") = " << first - second << std::endl;
        std::cout << "(" << first << ") * (" << second << ") = " << first * second << std::endl;
        std::cout << "(" << first << ") / (" << second << ") = ";
        Fraction result = first / second;
        result.get_denominator() == 0
            ? std::cout << "Cannot divide by zero" << std::endl
            : std::cout << result << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Init third(" << third << "), fourth(" << fourth << ")" << std::endl;
    third += fourth;
    std::cout << "Execute: third += fourth | the result of third is: " << third << std::endl;
    return 0;
}
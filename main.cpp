#include "fraction.hpp"

int main(int argc, char const *argv[]) {
    Fraction first, second, third(1, 2), fourth(3, 4);

    try {
        std::cout << "Please enter the first fraction: ";
        std::cin >> first;
        std::cout << "Please enter the second fraction: ";
        std::cin >> second;
    } catch (const std::invalid_argument &i_arg) {
        std::cerr << i_arg.what() << '\n';
        return EXIT_FAILURE;
    }
    std::cout << std::endl;

    std::cout << "(" << first << ") + (" << second << ") = " << first + second << std::endl;
    std::cout << "(" << first << ") - (" << second << ") = " << first - second << std::endl;
    std::cout << "(" << first << ") * (" << second << ") = " << first * second << std::endl;
    std::cout << "(" << first << ") / (" << second << ") = ";
    Fraction quotient;
    try {
        quotient = first / second;
        std::cout << quotient << std::endl;
    } catch (const divide_by_zero &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    std::cout << std::endl;

    std::cout << "Init third(" << third << "), fourth(" << fourth << ")" << std::endl;
    third += fourth;
    std::cout << "Execute: third += fourth | the result of third is: " << third << std::endl;
    return EXIT_SUCCESS;
}
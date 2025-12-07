#include <iostream>

#include <matho/fraction.hpp>

int main(int argc, char const * argv[]) {
    matho::Fraction a(0, 3);
    matho::Fraction b(1, 2);
    matho::Fraction c(1);
    matho::Fraction d(1, -1);
    matho::Fraction e(1, -2);
    matho::Fraction f;

    std::cout << ">>> Demonstration of Printing Fraction <<<";
    std::cout << std::endl << std::endl;

    std::cout << "Given:" << std::endl;
    std::cout << "  A = " << a << std::endl;
    std::cout << "  B = " << b << std::endl;
    std::cout << "  C = " << c << std::endl;
    std::cout << "  D = " << d << std::endl;
    std::cout << "  E = " << e << std::endl;
    std::cout << "  F = " << f << std::endl;

    return 0;
}

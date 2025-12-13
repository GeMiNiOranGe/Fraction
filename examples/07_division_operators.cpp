#include <iostream>

#include <matho/fraction.hpp>

int main() {
    matho::Fraction a(2, 3);
    matho::Fraction b(4, -1);

    std::cout << ">>> Demonstration of Fraction Division <<<";
    std::cout << std::endl << std::endl;

    std::cout << "Given:" << std::endl;
    std::cout << "  A = " << a << std::endl;
    std::cout << "  B = " << b << std::endl;
    std::cout << std::endl;

    std::cout << "We perform several division operations:" << std::endl;
    std::cout << "  1) A  / B = " << a / b << std::endl;
    std::cout << "  2) A  / 5 = " << a / 5 << std::endl;
    std::cout << "  3) 10 / B = " << 10 / b << std::endl;
    std::cout << std::endl;

    matho::Fraction c(1, 1);
    matho::Fraction d(1, 1);

    std::cout << "Now testing division-assignment:" << std::endl;
    std::cout << "  Initial C = " << c << std::endl;
    std::cout << "  Initial D = " << d << std::endl;
    std::cout << std::endl;

    c /= a;
    d /= 2;

    std::cout << "  After C /= A -> C = " << c << std::endl;
    std::cout << "  After D /= 2 -> D = " << d << std::endl;

    return 0;
}

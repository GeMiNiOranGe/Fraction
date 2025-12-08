#include <iostream>

#include <matho/fraction.hpp>

int main(int argc, char const * argv[]) {
    matho::Fraction a(3, 4);

    std::cout << ">>> Demonstration of Copy Constructor <<<";
    std::cout << std::endl << std::endl;

    std::cout << "Given:" << std::endl;
    std::cout << "  A = " << a << std::endl;
    std::cout << "  B = <Not initialized>" << std::endl;
    std::cout << std::endl;

    std::cout << "We initialize using the copy constructor:" << std::endl;
    std::cout << "  B(A)" << std::endl;
    std::cout << std::endl;

    matho::Fraction b(a);

    std::cout << "After initialization:" << std::endl;
    std::cout << "  A = " << a << std::endl;
    std::cout << "  B = " << b << std::endl;
    std::cout << std::endl;

    ////////////////////////////////////////////////////////////////////////////

    matho::Fraction c(10, 20);
    matho::Fraction d(1, 1);

    std::cout << ">>> Demonstration of Copy Assignment <<<";
    std::cout << std::endl << std::endl;

    std::cout << "Given:" << std::endl;
    std::cout << "  C = " << c << std::endl;
    std::cout << "  D = " << d << std::endl;
    std::cout << std::endl;

    std::cout << "We perform copy assignment:" << std::endl;
    std::cout << "  D = C" << std::endl;
    std::cout << std::endl;

    d = c;

    std::cout << "After assignment:" << std::endl;
    std::cout << "  C = " << c << std::endl;
    std::cout << "  D = " << d << std::endl;

    return 0;
}

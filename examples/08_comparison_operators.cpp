#include <iostream>

#include <matho/fraction.hpp>

int main(int argc, char const *argv[]) {
    matho::Fraction a(1, 2); // 0.5
    matho::Fraction b(3, 4); // 0.75
    int num = 1;             // 1

    // Enable true/false printing mode instead of 1/0.
    std::cout << std::boolalpha;

    std::cout << ">>> Demonstration of Fraction Comparison <<<" << std::endl;
    std::cout << std::endl;

    std::cout << "Given:" << std::endl;
    std::cout << "  A   = " << a << std::endl;
    std::cout << "  B   = " << b << std::endl;
    std::cout << "  num = " << num << std::endl;
    std::cout << std::endl;

    std::cout << "We perform several equality operators:" << std::endl;
    std::cout << "  1)  a   == b   ? -> " << (a == b) << std::endl;
    std::cout << "  2)  a   == num ? -> " << (a == num) << std::endl;
    std::cout << "  3)  num == a   ? -> " << (num == a) << std::endl;
    std::cout << std::endl;

    std::cout << "  4)  a   != b   ? -> " << (a != b) << std::endl;
    std::cout << "  5)  a   != num ? -> " << (a != num) << std::endl;
    std::cout << "  6)  num != a   ? -> " << (num != a) << std::endl;
    std::cout << std::endl;

    std::cout << "We perform several relational operators:" << std::endl;
    std::cout << "  1)  a   <  b   ? -> " << (a < b) << std::endl;
    std::cout << "  2)  a   <  num ? -> " << (a < num) << std::endl;
    std::cout << "  3)  num <  a   ? -> " << (num < a) << std::endl;
    std::cout << std::endl;

    std::cout << "  4)  a   <= b   ? -> " << (a <= b) << std::endl;
    std::cout << "  5)  a   <= num ? -> " << (a <= num) << std::endl;
    std::cout << "  6)  num <= a   ? -> " << (num <= a) << std::endl;
    std::cout << std::endl;

    std::cout << "  7)  a   >  b   ? -> " << (a > b) << std::endl;
    std::cout << "  8)  a   >  num ? -> " << (a > num) << std::endl;
    std::cout << "  9)  num >  a   ? -> " << (num > a) << std::endl;
    std::cout << std::endl;

    std::cout << "  10) a   >= b   ? -> " << (a >= b) << std::endl;
    std::cout << "  11) a   >= num ? -> " << (a >= num) << std::endl;
    std::cout << "  12) num >= a   ? -> " << (num >= a) << std::endl;
    std::cout << std::endl;

    return 0;
}

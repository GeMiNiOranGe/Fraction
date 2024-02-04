#include <cassert>

#include "fraction.hpp"

int main(int argc, char const *argv[]) {
    assert(Fraction(3, 2) + 2 == Fraction(7, 2));  // 1.5 + 2 == 3.5
    assert(Fraction(3, 2) - 2 == Fraction(-1, 2)); // 1.5 - 2 == -0.5
    assert(Fraction(3, 2) * 2 == 3);               // 1.5 * 2 == 3
    assert(Fraction(3, 2) / 2 == Fraction(3, 4));  // 1.5 / 2 == 0.75

    assert(2 + Fraction(3, 2) == Fraction(7, 2)); // 2 + 1.5 == 3.5
    assert(2 - Fraction(3, 2) == Fraction(1, 2)); // 2 - 1.5 == -0.5
    assert(2 * Fraction(3, 2) == 3);              // 2 * 1.5 == 3
    assert(2 / Fraction(3, 2) == Fraction(4, 3)); // 2 / 1.5 == 0.75

    // special case
    assert(Fraction(6 / 2) + 2 == 5); // (6/2) + 2 == 5
    assert(Fraction(6 / 2) - 2 == 1); // (6/2) - 2 == 1
    std::cout << "all success";
    return 0;
}
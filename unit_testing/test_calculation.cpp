#include <cassert>

#include "fraction.hpp"

int main(int argc, char const *argv[]) {
    // same deno
    assert(Fraction(3, 2) + Fraction(3, 2) == 3);              // 1.5 + 1.5 == 3
    assert(Fraction(3, 2) - Fraction(3, 2) == 0);              // 1.5 - 1.5 == 0
    assert(Fraction(3, 2) * Fraction(3, 2) == Fraction(9, 4)); // 1.5 * 1.5 == 2.25
    assert(Fraction(3, 2) / Fraction(3, 2) == 1);              // 1.5 / 1.5 == 1

    // not same deno
    assert(Fraction(8, 5) + Fraction(3, 9) == Fraction(29, 15)); // (8/5) + (1/3) == (29/15)
    assert(Fraction(8, 5) - Fraction(3, 9) == Fraction(19, 15)); // (8/5) - (1/3) == (19/15)
    assert(Fraction(8, 5) * Fraction(3, 9) == Fraction(8, 15));  // (8/5) * (1/3) == (8/15)
    assert(Fraction(8, 5) / Fraction(3, 9) == Fraction(24, 5));  // (8/5) / (1/3) == (24/5)
    std::cout << "all success";
    return 0;
}
#include <cassert>
#include <filesystem>

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

    // other
    Fraction sum(1, 2), difference(1, 2), product(1, 2), quotient(1, 2);
    sum += Fraction(5, 7);        // (1/2) + (5/7)   == (17/14)
    difference -= Fraction(9, 2); // (1/2) - (9/2)   == (-4/1)
    product *= Fraction(13, 17);  // (1/2) * (13/17) == (13/34)
    quotient /= Fraction(3, 7);   // (1/2) / (3/7)   == (7/6)
    assert(sum == Fraction(17, 14));
    assert(difference == Fraction(-4, 1));
    assert(product == Fraction(13, 34));
    assert(quotient == Fraction(7, 6));

    std::filesystem::path current_file(__FILE__);
    std::cout << current_file.stem() << ": success" << std::endl;
    return 0;
}
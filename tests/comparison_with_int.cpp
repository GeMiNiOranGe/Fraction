#include <cassert>
#include <filesystem>

#include "fraction.hpp"

int main(int argc, char const *argv[]) {
    assert(Fraction(6, 2) == 3); //   3 == 3
    assert(Fraction(3, 2) != 3); // 1.5 != 3
    assert(Fraction(4, 2) <= 2); //   2 <= 2
    assert(Fraction(3, 2) <= 3); // 1.5 <= 3
    assert(Fraction(4, 2) >= 2); //   2 >= 2
    assert(Fraction(5, 2) >= 2); // 2.5 >= 2
    assert(Fraction(3, 2) < 3);  // 1.5 <  3
    assert(Fraction(5, 2) > 2);  // 2.5 >  2

    assert(3 == Fraction(6, 2)); // 3 == 3
    assert(3 != Fraction(3, 2)); // 3 != 1.5
    assert(2 <= Fraction(4, 2)); // 2 <=   2
    assert(2 <= Fraction(5, 2)); // 2 <= 2.5
    assert(2 >= Fraction(4, 2)); // 2 >=   2
    assert(3 >= Fraction(3, 2)); // 3 >= 1.5
    assert(2 < Fraction(5, 2));  // 2 <  2.5
    assert(3 > Fraction(3, 2));  // 3 >  1.5

    std::filesystem::path current_file(__FILE__);
    std::cout << current_file.stem() << ": success" << std::endl;
    return 0;
}
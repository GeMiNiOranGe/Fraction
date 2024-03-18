#include <cassert>
#include <filesystem>

#include "fraction.hpp"

int main(int argc, char const *argv[]) {
    assert(Fraction(3, 2) != Fraction(2, 3)); // 1.5 != 0.(6)

    // same deno
    assert(Fraction(3, 2) == Fraction(3, 2)); // 1.5 == 1.5
    assert(Fraction(3, 2) <= Fraction(3, 2)); // 1.5 <= 1.5
    assert(Fraction(3, 2) <= Fraction(5, 2)); // 1.5 <= 2.5
    assert(Fraction(3, 2) >= Fraction(3, 2)); // 1.5 >= 1.5
    assert(Fraction(5, 2) >= Fraction(3, 2)); // 2.5 >= 1.5
    assert(Fraction(3, 2) < Fraction(5, 2));  // 1.5 <  2.5
    assert(Fraction(5, 2) > Fraction(3, 2));  // 2.5 >  1.5

    // not same deno
    assert(Fraction(6, 4) == Fraction(3, 2)); //   1.5 == 1.5
    assert(Fraction(3, 2) <= Fraction(6, 4)); //   1.5 <= 1.5
    assert(Fraction(3, 2) <= Fraction(5, 3)); //   1.5 <= 1.(6)
    assert(Fraction(3, 2) >= Fraction(6, 4)); //   1.5 >= 1.5
    assert(Fraction(5, 3) >= Fraction(3, 2)); // 1.(6) >= 1.5
    assert(Fraction(3, 2) < Fraction(5, 3));  //   1.5 <  1.(6)
    assert(Fraction(5, 3) > Fraction(3, 2));  // 1.(6) >  1.5

    std::filesystem::path current_file(__FILE__);
    std::cout << current_file.stem() << ": success" << std::endl;
    return 0;
}
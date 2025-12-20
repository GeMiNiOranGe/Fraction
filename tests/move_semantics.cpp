#include <catch2/catch_test_macros.hpp>

#include <matho/fraction.hpp>

using namespace matho;

TEST_CASE(
    "Move constructor transfers numerator and denominator",
    "[constructor][move]"
) {
    Fraction original(7, -3);

    Fraction moved(std::move(original));

    REQUIRE(moved.get_numerator() == 7);
    REQUIRE(moved.get_denominator() == -3);
}

TEST_CASE(
    "Move assignment transfers numerator and denominator",
    "[move][assignment]"
) {
    Fraction a(1, 2);
    Fraction b(9, 8);

    b = std::move(a);

    REQUIRE(b.get_numerator() == 1);
    REQUIRE(b.get_denominator() == 2);
}

TEST_CASE("Move assignment returns *this", "[move][assignment]") {
    Fraction a(3, 4);
    Fraction b(2);

    Fraction & result = (b = std::move(a));

    REQUIRE(&result == &b);
}

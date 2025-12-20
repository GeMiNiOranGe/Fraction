#include <catch2/catch_test_macros.hpp>

#include <matho/fraction.hpp>

using namespace matho;

TEST_CASE(
    "Copy constructor copies both numerator and denominator",
    "[constructor][copy]"
) {
    Fraction original(3, -2);

    Fraction copy(original);

    REQUIRE(copy.get_numerator() == original.get_numerator());
    REQUIRE(copy.get_denominator() == original.get_denominator());

    // ensure that the two objects are different
    REQUIRE(&copy != &original);
}

TEST_CASE(
    "Copy assignment copies both numerator and denominator",
    "[copy][assignment]"
) {
    Fraction a(10, 20);
    Fraction b(1, 1);

    b = a;

    REQUIRE(b.get_numerator() == a.get_numerator());
    REQUIRE(b.get_denominator() == a.get_denominator());
    REQUIRE(&b != &a);
}

TEST_CASE("Copy assignment returns *this", "[copy][assignment]") {
    Fraction a(4, 5);
    Fraction b(0, 0);

    Fraction & result = (b = a);

    REQUIRE(&result == &b);
}

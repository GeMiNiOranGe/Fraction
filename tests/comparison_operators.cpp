#include <catch2/catch_test_macros.hpp>

#include <matho/fraction.hpp>

// Equality / Inequality =======================================================

TEST_CASE("Equality: large reducible fractions") {
    matho::Fraction a(100, 40);
    matho::Fraction b(5, 2);

    REQUIRE(a == b);
}

TEST_CASE("Equality: Fraction != double (precision)") {
    matho::Fraction a(1, 3);

    REQUIRE_FALSE(static_cast<double>(a) == 0.333333);
}

TEST_CASE("Equality: symmetry property") {
    matho::Fraction a(4, 6);
    matho::Fraction b(2, 3);

    REQUIRE((a == b) == (b == a));
}

TEST_CASE("Equality: fraction always equals itself") {
    matho::Fraction a(7, 9);

    REQUIRE(a == a);
    REQUIRE_FALSE(a != a);
}

// positive cases
TEST_CASE("Equality: A == B when numerator and denominator are equal") {
    matho::Fraction a(3, 2);
    matho::Fraction b(3, 2);

    REQUIRE(a == b);
    REQUIRE_FALSE(a != b);
}

TEST_CASE("Equality: A == B when fractions reduce to the same value") {
    matho::Fraction a(6, 4);
    matho::Fraction b(3, 2);

    REQUIRE(a == b);
    REQUIRE_FALSE(a != b);
}

TEST_CASE("Equality: Fraction == number when values are equal") {
    matho::Fraction a(6, 2);
    int b = 3;

    REQUIRE(a == b);
    REQUIRE_FALSE(a != b);
}

TEST_CASE("Equality: number == Fraction when values are equal") {
    int a = 3;
    matho::Fraction b(6, 2);

    REQUIRE(a == b);
    REQUIRE_FALSE(a != b);
}

TEST_CASE("Equality: identical Fraction objects are equal") {
    matho::Fraction a(10, 5);
    matho::Fraction &ref = a;

    REQUIRE(a == ref);
    REQUIRE_FALSE(a != ref);
}

TEST_CASE("Equality: A != B when values differ") {
    matho::Fraction a(3, 2);
    matho::Fraction b(2, 3);

    REQUIRE(a != b);
    REQUIRE_FALSE(a == b);
}

TEST_CASE("Equality: Fraction != number when values differ") {
    matho::Fraction a(3, 2);
    int b = 3;

    REQUIRE(a != b);
    REQUIRE_FALSE(a == b);
}

// negative cases
TEST_CASE("Equality: negative fractions are equal") {
    matho::Fraction a(-3, 2);
    matho::Fraction b(3, -2);

    REQUIRE(a == b);
    REQUIRE_FALSE(a != b);
}

TEST_CASE("Equality: both numerator and denominator negative") {
    matho::Fraction a(-3, -2);
    matho::Fraction b(3, 2);

    REQUIRE(a == b);
}

TEST_CASE("Equality: Fraction == negative number") {
    matho::Fraction a(-6, 2);
    int b = -3;

    REQUIRE(a == b);
}

TEST_CASE("Equality: negative number == Fraction") {
    int a = -3;
    matho::Fraction b(-6, 2);

    REQUIRE(a == b);
}

// comparisons with zero
TEST_CASE("Equality: zero fractions") {
    matho::Fraction a(0, 5);
    matho::Fraction b(0, 10);

    REQUIRE(a == b);
}

TEST_CASE("Equality: Fraction == 0") {
    matho::Fraction a(0, 7);

    REQUIRE(a == 0);
    REQUIRE_FALSE(a != 0);
}

TEST_CASE("Equality: non-zero fraction != 0") {
    matho::Fraction a(1, 5);

    REQUIRE(a != 0);
}

// Relational ==================================================================

TEST_CASE("Relational: Fraction compared to zero number") {
    matho::Fraction a(1, 4);
    int b = 0;

    REQUIRE(a > b);
    REQUIRE_FALSE(a < b);
}

TEST_CASE("Relational: symmetry of < and >") {
    matho::Fraction a(3, 4);
    matho::Fraction b(2, 3);

    REQUIRE((a < b) == (b > a));
}

TEST_CASE("Relational: fraction compared to itself") {
    matho::Fraction a(7, 9);

    REQUIRE_FALSE(a < a);
    REQUIRE_FALSE(a > a);
    REQUIRE(a <= a);
    REQUIRE(a >= a);
}

TEST_CASE("Relational: reducible fractions comparison") {
    matho::Fraction a(100, 40);
    matho::Fraction b(5, 2);

    REQUIRE_FALSE(a < b);
    REQUIRE_FALSE(a > b);
    REQUIRE(a <= b);
    REQUIRE(a >= b);
}

TEST_CASE("Relational: consistency with equality") {
    matho::Fraction a(6, 4);
    matho::Fraction b(3, 2);

    REQUIRE(a <= b);
    REQUIRE(a >= b);
    REQUIRE_FALSE(a < b);
    REQUIRE_FALSE(a > b);
}

TEST_CASE("Relational: large numbers comparison") {
    matho::Fraction a(1000000, 3);
    matho::Fraction b(999999, 3);

    REQUIRE(a > b);
}

TEST_CASE("Relational: negative number compared to fraction") {
    int a = -1;
    matho::Fraction b(1, 2);

    REQUIRE(a < b);
    REQUIRE_FALSE(a > b);
}

TEST_CASE("Relational: fraction less than negative number") {
    matho::Fraction a(-3, 2);
    int b = -1;

    REQUIRE(a < b);
}

// less - positive cases
TEST_CASE("Relational: A < B when same denominator and numerator is smaller") {
    matho::Fraction a(3, 2);
    matho::Fraction b(5, 2);

    REQUIRE(a < b);
    REQUIRE_FALSE(a >= b);
}

TEST_CASE("Relational: A < B when values differ and denominators differ") {
    matho::Fraction a(3, 2);
    matho::Fraction b(5, 3);

    REQUIRE(a < b);
    REQUIRE_FALSE(a >= b);
}

TEST_CASE("Relational: Fraction < number when value is smaller") {
    matho::Fraction a(3, 2);
    int b = 3;

    REQUIRE(a < b);
    REQUIRE_FALSE(a >= b);
}

TEST_CASE("Relational: number < Fraction when value is smaller") {
    matho::Fraction a(5, 2);
    int b = 2;

    REQUIRE(b < a);
    REQUIRE_FALSE(b >= a);
}

// less - negative cases
TEST_CASE("Relational: negative fraction comparison") {
    matho::Fraction a(-1, 2);
    matho::Fraction b(1, 2);

    REQUIRE(a < b);
    REQUIRE_FALSE(a > b);
}

TEST_CASE("Relational: both fractions negative") {
    matho::Fraction a(-3, 2);
    matho::Fraction b(-1, 2);

    REQUIRE(a < b);
}

TEST_CASE("Relational: negative denominator") {
    matho::Fraction a(1, -2);
    matho::Fraction b(1, 2);

    REQUIRE(a < b);
}

// less - comparisons with zero
TEST_CASE("Relational: zero compared to positive fraction") {
    matho::Fraction a(0, 5);
    matho::Fraction b(1, 3);

    REQUIRE(a < b);
}

// greater - positive cases
TEST_CASE("Relational: A > B when same denominator and numerator is larger") {
    matho::Fraction a(5, 2);
    matho::Fraction b(3, 2);

    REQUIRE(a > b);
    REQUIRE_FALSE(a <= b);
}

TEST_CASE("Relational: A > B when values differ and denominators differ") {
    matho::Fraction a(5, 3);
    matho::Fraction b(3, 2);

    REQUIRE(a > b);
    REQUIRE_FALSE(a <= b);
}

TEST_CASE("Relational: Fraction > number when value is larger") {
    matho::Fraction a(5, 2);
    int b = 2;

    REQUIRE(a > b);
    REQUIRE_FALSE(a <= b);
}

TEST_CASE("Relational: number > Fraction when value is larger") {
    matho::Fraction a(3, 2);
    int b = 3;

    REQUIRE(b > a);
    REQUIRE_FALSE(b <= a);
}

// greater - negative cases

// greater - comparisons with zero
TEST_CASE("Relational: zero compared to negative fraction") {
    matho::Fraction a(0, 5);
    matho::Fraction b(-1, 3);

    REQUIRE(a > b);
}

// less equal
TEST_CASE("Relational: A <= B when values are equal (same denominator)") {
    matho::Fraction a(3, 2);
    matho::Fraction b(3, 2);

    REQUIRE(a <= b);
    REQUIRE_FALSE(a > b);
}

TEST_CASE("Relational: A <= B when values are equal but denominators differ") {
    matho::Fraction a(3, 2);
    matho::Fraction b(6, 4);

    REQUIRE(a <= b);
    REQUIRE_FALSE(a > b);
}

// greater equal
TEST_CASE("Relational: A >= B when values are equal (same denominator)") {
    matho::Fraction a(3, 2);
    matho::Fraction b(3, 2);

    REQUIRE(a >= b);
    REQUIRE_FALSE(a < b);
}

TEST_CASE("Relational: A >= B when values are equal but denominators differ") {
    matho::Fraction a(3, 2);
    matho::Fraction b(6, 4);

    REQUIRE(a >= b);
    REQUIRE_FALSE(a < b);
}

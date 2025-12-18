#include <catch2/catch_test_macros.hpp>

#include <matho/fraction.hpp>

// with other fraction
TEST_CASE("Fraction * Fraction basic", "[operator*]") {
    matho::Fraction a{1, 2};
    matho::Fraction b{2, 3};

    matho::Fraction result = a * b;

    REQUIRE(result == matho::Fraction{1, 3});
}

TEST_CASE("Fraction * Fraction produces reducible result", "[operator*]") {
    matho::Fraction a{2, 4};
    matho::Fraction b{3, 6};

    matho::Fraction result = a * b;

    REQUIRE(result == matho::Fraction{1, 4});
}

TEST_CASE("Fraction * Fraction with negative value", "[operator*]") {
    matho::Fraction a{-1, 2};
    matho::Fraction b{2, 3};

    REQUIRE(a * b == matho::Fraction{-1, 3});
}

TEST_CASE("Fraction * Fraction both negative", "[operator*]") {
    matho::Fraction a{-1, 2};
    matho::Fraction b{-2, 3};

    REQUIRE(a * b == matho::Fraction{1, 3});
}

TEST_CASE("Fraction * zero fraction", "[operator*]") {
    matho::Fraction zero{0, 1};
    matho::Fraction a{5, 7};

    REQUIRE(a * zero == zero);
    REQUIRE(zero * a == zero);
}

TEST_CASE("Fraction operator*=", "[operator*=]") {
    matho::Fraction a{1, 2};
    matho::Fraction b{2, 3};

    a *= b;

    REQUIRE(a == matho::Fraction{1, 3});
}
TEST_CASE("Fraction operator*= with negative fraction", "[operator*=]") {
    matho::Fraction a{3, 4};
    matho::Fraction b{-2, 3};

    a *= b;

    REQUIRE(a == matho::Fraction{-1, 2});
}

TEST_CASE("operator* and operator*= consistency", "[operator*][operator*=]") {
    matho::Fraction a{2, 3};
    matho::Fraction b{3, 4};

    matho::Fraction expected = a * b;

    a *= b;

    REQUIRE(a == expected);
}

// with number
TEST_CASE("Fraction * number basic", "[operator*][number]") {
    matho::Fraction a{1, 2};

    matho::Fraction result = a * 2;

    REQUIRE(result == matho::Fraction{1, 1});
}

TEST_CASE("Fraction * negative number", "[operator*][number]") {
    matho::Fraction a{3, 4};

    matho::Fraction result = a * (-2);

    REQUIRE(result == matho::Fraction{-3, 2});
}

TEST_CASE("number * Fraction", "[operator*][number]") {
    matho::Fraction a{2, 5};

    matho::Fraction result = 3 * a;

    REQUIRE(result == matho::Fraction{6, 5});
}

TEST_CASE("Fraction * zero number", "[operator*][number]") {
    matho::Fraction a{5, 7};

    REQUIRE(a * 0 == matho::Fraction{0, 1});
}

TEST_CASE("Fraction operator*= number", "[operator*=][number]") {
    matho::Fraction a{1, 4};

    a *= 2;

    REQUIRE(a == matho::Fraction{1, 2});
}

TEST_CASE("Fraction operator*= negative number", "[operator*=][number]") {
    matho::Fraction a{3, 2};

    a *= -2;

    REQUIRE(a == matho::Fraction{-3, 1});
}

TEST_CASE(
    "operator* number and operator*= number consistency",
    "[operator*][operator*=][number]"
) {
    matho::Fraction a{2, 3};
    int b = -3;

    matho::Fraction expected = a * b;

    a *= b;

    REQUIRE(a == expected);
}

TEST_CASE("Chained fraction multiplication", "[operator*]") {
    matho::Fraction a{1, 2};
    matho::Fraction b{2, 3};
    matho::Fraction c{3, 4};

    matho::Fraction result = a * b * c;

    REQUIRE(result == matho::Fraction{1, 4});
}

TEST_CASE("Chained Fraction and number multiplication", "[operator*][number]") {
    matho::Fraction a{1, 2};

    matho::Fraction result = a * 2 * 3;

    REQUIRE(result == matho::Fraction{3, 1});
}

// ===== Missing cases: Fraction (negative) * number =====

TEST_CASE("Negative Fraction * positive number", "[operator*][number]") {
    matho::Fraction a{-1, 2};

    matho::Fraction result = a * 2;

    REQUIRE(result == matho::Fraction{-1, 1});
}

TEST_CASE("Negative Fraction * negative number", "[operator*][number]") {
    matho::Fraction a{-1, 2};

    matho::Fraction result = a * (-2);

    REQUIRE(result == matho::Fraction{1, 1});
}

TEST_CASE("Positive number * negative Fraction", "[operator*][number]") {
    matho::Fraction a{-1, 4};

    matho::Fraction result = 2 * a;

    REQUIRE(result == matho::Fraction{-1, 2});
}

TEST_CASE("Negative number * negative Fraction", "[operator*][number]") {
    matho::Fraction a{-3, 4};

    matho::Fraction result = -2 * a;

    REQUIRE(result == matho::Fraction{3, 2});
}

// ===== operator*= with negative Fraction =====

TEST_CASE(
    "Negative Fraction operator*= positive number",
    "[operator*=][number]"
) {
    matho::Fraction a{-3, 2};

    a *= 2;

    REQUIRE(a == matho::Fraction{-3, 1});
}

TEST_CASE(
    "Negative Fraction operator*= negative number",
    "[operator*=][number]"
) {
    matho::Fraction a{-3, 2};

    a *= -2;

    REQUIRE(a == matho::Fraction{3, 1});
}

// ===== Consistency: negative Fraction * number =====

TEST_CASE(
    "Negative Fraction operator* number and operator*= number consistency",
    "[operator*][operator*=][number]"
) {
    matho::Fraction a{-2, 3};
    int b = -3;

    matho::Fraction expected = a * b;

    a *= b;

    REQUIRE(a == expected);
}

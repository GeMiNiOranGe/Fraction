#include <catch2/catch_test_macros.hpp>

#include <matho/fraction.hpp>

// with other fraction
TEST_CASE("Fraction - Fraction with same denominator", "[operator-]") {
    matho::Fraction a{3, 4};
    matho::Fraction b{1, 4};

    matho::Fraction result = a - b;

    REQUIRE(result == matho::Fraction{1, 2});
}

TEST_CASE("Fraction - Fraction with different denominators", "[operator-]") {
    matho::Fraction a{1, 2};
    matho::Fraction b{1, 3};

    matho::Fraction result = a - b;

    REQUIRE(result == matho::Fraction{1, 6});
}

TEST_CASE("Fraction - Fraction produces reducible result", "[operator-]") {
    matho::Fraction a{2, 6};
    matho::Fraction b{1, 6};

    matho::Fraction result = a - b;

    REQUIRE(result == matho::Fraction{1, 6});
}

TEST_CASE("Fraction - Fraction with negative value", "[operator-]") {
    matho::Fraction a{1, 2};
    matho::Fraction b{-1, 2};

    REQUIRE(a - b == matho::Fraction{1, 1});
}

TEST_CASE("Fraction - Fraction both negative", "[operator-]") {
    matho::Fraction a{-1, 2};
    matho::Fraction b{-1, 4};

    REQUIRE(a - b == matho::Fraction{-1, 4});
}

TEST_CASE("Fraction - zero fraction", "[operator-]") {
    matho::Fraction zero{0, 1};
    matho::Fraction a{5, 7};

    REQUIRE(a - zero == a);
}

TEST_CASE("Fraction operator-=", "[operator-=]") {
    matho::Fraction a{3, 4};
    matho::Fraction b{1, 4};

    a -= b;

    REQUIRE(a == matho::Fraction{1, 2});
}

TEST_CASE("Fraction operator-= with different denominators", "[operator-=]") {
    matho::Fraction a{1, 2};
    matho::Fraction b{1, 3};

    a -= b;

    REQUIRE(a == matho::Fraction{1, 6});
}

TEST_CASE("Fraction operator-= with negative fraction", "[operator-=]") {
    matho::Fraction a{1, 2};
    matho::Fraction b{-1, 2};

    a -= b;

    REQUIRE(a == matho::Fraction{1, 1});
}

TEST_CASE("Chained fraction subtraction", "[operator-]") {
    matho::Fraction a{1, 1};
    matho::Fraction b{1, 4};
    matho::Fraction c{1, 8};

    matho::Fraction result = a - b - c;

    REQUIRE(result == matho::Fraction{5, 8});
}

TEST_CASE("operator- and operator-= consistency", "[operator-][operator-=]") {
    matho::Fraction a{2, 3};
    matho::Fraction b{1, 6};

    matho::Fraction expected = a - b;

    a -= b;

    REQUIRE(a == expected);
}

// with number
TEST_CASE("Fraction - number basic", "[operator-][number]") {
    matho::Fraction a{3, 2};

    matho::Fraction result = a - 1;

    REQUIRE(result == matho::Fraction{1, 2});
}

TEST_CASE("Fraction - negative number", "[operator-][number]") {
    matho::Fraction a{1, 2};

    matho::Fraction result = a - (-1);

    REQUIRE(result == matho::Fraction{3, 2});
}

TEST_CASE("number - Fraction", "[operator-][number]") {
    matho::Fraction a{1, 3};

    matho::Fraction result = 1 - a;

    REQUIRE(result == matho::Fraction{2, 3});
}

TEST_CASE("Fraction - zero number", "[operator-][number]") {
    matho::Fraction a{5, 7};

    REQUIRE(a - 0 == a);
}

TEST_CASE("Fraction operator-= number", "[operator-=][number]") {
    matho::Fraction a{3, 4};

    a -= 1;

    REQUIRE(a == matho::Fraction{-1, 4});
}

TEST_CASE("Fraction operator-= negative number", "[operator-=][number]") {
    matho::Fraction a{1, 2};

    a -= -1;

    REQUIRE(a == matho::Fraction{3, 2});
}

TEST_CASE(
    "operator- number and operator-= number consistency",
    "[operator-][operator-=][number]"
) {
    matho::Fraction a{2, 3};
    int b = 2;

    matho::Fraction expected = a - b;

    a -= b;

    REQUIRE(a == expected);
}

TEST_CASE("Chained Fraction and number subtraction", "[operator-][number]") {
    matho::Fraction a{5, 2};

    matho::Fraction result = a - 1 - 1;

    REQUIRE(result == matho::Fraction{1, 2});
}

TEST_CASE("Negative Fraction - positive number", "[operator-][number]") {
    matho::Fraction a{-1, 2};

    matho::Fraction result = a - 1;

    REQUIRE(result == matho::Fraction{-3, 2});
}

TEST_CASE("Negative Fraction - negative number", "[operator-][number]") {
    matho::Fraction a{-1, 2};

    matho::Fraction result = a - (-1);

    REQUIRE(result == matho::Fraction{1, 2});
}

TEST_CASE("Positive number - negative Fraction", "[operator-][number]") {
    matho::Fraction a{-1, 4};

    matho::Fraction result = 1 - a;

    REQUIRE(result == matho::Fraction{5, 4});
}

TEST_CASE("Negative number - negative Fraction", "[operator-][number]") {
    matho::Fraction a{-3, 4};

    matho::Fraction result = -1 - a;

    REQUIRE(result == matho::Fraction{-1, 4});
}

TEST_CASE(
    "Negative Fraction operator-= positive number",
    "[operator-=][number]"
) {
    matho::Fraction a{-3, 2};

    a -= 1;

    REQUIRE(a == matho::Fraction{-5, 2});
}

TEST_CASE(
    "Negative Fraction operator-= negative number",
    "[operator-=][number]"
) {
    matho::Fraction a{-3, 2};

    a -= -1;

    REQUIRE(a == matho::Fraction{-1, 2});
}

TEST_CASE(
    "Negative Fraction operator- number and operator-= number consistency",
    "[operator-][operator-=][number]"
) {
    matho::Fraction a{-2, 3};
    int b = -2;

    matho::Fraction expected = a - b;

    a -= b;

    REQUIRE(a == expected);
}

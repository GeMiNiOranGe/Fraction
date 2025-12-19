#include <catch2/catch_test_macros.hpp>

#include <matho/fraction.hpp>

TEST_CASE("Fraction / Fraction basic", "[operator/]") {
    matho::Fraction a{1, 2};
    matho::Fraction b{1, 4};

    matho::Fraction result = a / b;

    REQUIRE(result == matho::Fraction{2, 1});
}

TEST_CASE("Fraction / Fraction produces reducible result", "[operator/]") {
    matho::Fraction a{2, 4};
    matho::Fraction b{1, 2};

    matho::Fraction result = a / b;

    REQUIRE(result == matho::Fraction{1, 1});
}

TEST_CASE("Fraction / Fraction with negative value", "[operator/]") {
    matho::Fraction a{3, 4};
    matho::Fraction b{-1, 2};

    REQUIRE(a / b == matho::Fraction{-3, 2});
}

TEST_CASE("Fraction / Fraction both negative", "[operator/]") {
    matho::Fraction a{-1, 2};
    matho::Fraction b{-1, 4};

    REQUIRE(a / b == matho::Fraction{2, 1});
}

TEST_CASE("Fraction / Fraction divide by one", "[operator/]") {
    matho::Fraction a{5, 7};
    matho::Fraction one{1, 1};

    REQUIRE(a / one == a);
}

TEST_CASE("Fraction operator/=", "[operator/=]") {
    matho::Fraction a{1, 2};
    matho::Fraction b{1, 4};

    a /= b;

    REQUIRE(a == matho::Fraction{2, 1});
}

TEST_CASE("Fraction operator/= with negative fraction", "[operator/=]") {
    matho::Fraction a{3, 4};
    matho::Fraction b{-1, 2};

    a /= b;

    REQUIRE(a == matho::Fraction{-3, 2});
}

TEST_CASE("operator/ and operator/= consistency", "[operator/][operator/=]") {
    matho::Fraction a{2, 3};
    matho::Fraction b{4, 5};

    matho::Fraction expected = a / b;

    a /= b;

    REQUIRE(a == expected);
}

TEST_CASE("Fraction / number basic", "[operator/][number]") {
    matho::Fraction a{1, 2};

    matho::Fraction result = a / 2;

    REQUIRE(result == matho::Fraction{1, 4});
}

TEST_CASE("Fraction / negative number", "[operator/][number]") {
    matho::Fraction a{3, 4};

    REQUIRE(a / (-2) == matho::Fraction{-3, 8});
}

TEST_CASE("number / Fraction", "[operator/][number]") {
    matho::Fraction a{1, 4};

    matho::Fraction result = 1 / a;

    REQUIRE(result == matho::Fraction{4, 1});
}

TEST_CASE("Fraction / one number", "[operator/][number]") {
    matho::Fraction a{5, 7};

    REQUIRE(a / 1 == a);
}

TEST_CASE("Fraction operator/= number", "[operator/=][number]") {
    matho::Fraction a{1, 2};

    a /= 2;

    REQUIRE(a == matho::Fraction{1, 4});
}

TEST_CASE("Fraction operator/= negative number", "[operator/=][number]") {
    matho::Fraction a{3, 4};

    a /= -2;

    REQUIRE(a == matho::Fraction{-3, 8});
}

TEST_CASE(
    "operator/ number and operator/= number consistency",
    "[operator/][operator/=][number]"
) {
    matho::Fraction a{2, 3};
    int b = -2;

    matho::Fraction expected = a / b;

    a /= b;

    REQUIRE(a == expected);
}

TEST_CASE("Fraction / zero fraction throws", "[operator/]") {
    matho::Fraction a{1, 2};
    matho::Fraction zero{0, 1};

    REQUIRE_THROWS(a / zero);
}

TEST_CASE("Fraction / zero number throws", "[operator/][number]") {
    matho::Fraction a{1, 2};

    REQUIRE_THROWS(a / 0);
}

TEST_CASE("Fraction / Fraction with zero numerator", "[operator/]") {
    matho::Fraction a{0, 5};
    matho::Fraction b{3, 7};

    REQUIRE(a / b == matho::Fraction{0, 1});
}

TEST_CASE("Fraction / Fraction sign normalization", "[operator/]") {
    matho::Fraction a{1, -2};
    matho::Fraction b{1, 4};

    REQUIRE(a / b == matho::Fraction{-2, 1});
}

/* ============================================================
 *  Fraction / number – Negative Fraction
 * ============================================================ */

TEST_CASE("Negative Fraction / positive number", "[operator/][number]") {
    matho::Fraction a{-1, 2};

    REQUIRE(a / 2 == matho::Fraction{-1, 4});
}

TEST_CASE("Negative Fraction / negative number", "[operator/][number]") {
    matho::Fraction a{-1, 2};

    REQUIRE(a / (-2) == matho::Fraction{1, 4});
}

/* ============================================================
 *  number / Fraction – Negative Fraction
 * ============================================================ */

TEST_CASE("Positive number / negative Fraction", "[operator/][number]") {
    matho::Fraction a{-1, 4};

    REQUIRE(1 / a == matho::Fraction{-4, 1});
}

TEST_CASE("Negative number / negative Fraction", "[operator/][number]") {
    matho::Fraction a{-1, 4};

    REQUIRE(-1 / a == matho::Fraction{4, 1});
}

/* ============================================================
 *  Fraction /= number – Negative Fraction
 * ============================================================ */

TEST_CASE("Negative Fraction operator/= positive number", "[operator/=][number]") {
    matho::Fraction a{-3, 2};

    a /= 3;

    REQUIRE(a == matho::Fraction{-1, 2});
}

TEST_CASE("Negative Fraction operator/= negative number", "[operator/=][number]") {
    matho::Fraction a{-3, 2};

    a /= -3;

    REQUIRE(a == matho::Fraction{1, 2});
}

/* ============================================================
 *  Consistency – Negative Fraction vs number
 * ============================================================ */

TEST_CASE(
    "Negative Fraction operator/ number and operator/= number consistency",
    "[operator/][operator/=][number]"
) {
    matho::Fraction a{-2, 3};
    int b = 4;

    matho::Fraction expected = a / b;

    a /= b;

    REQUIRE(a == expected);
}

/* ============================================================
 *  Chained division
 * ============================================================ */

TEST_CASE("Chained Fraction division", "[operator/]") {
    matho::Fraction a{1, 2};
    matho::Fraction b{1, 4};
    matho::Fraction c{2, 1};

    matho::Fraction result = a / b / c;

    REQUIRE(result == matho::Fraction{1, 1});
}

TEST_CASE("Chained Fraction and number division", "[operator/][number]") {
    matho::Fraction a{4, 1};

    matho::Fraction result = a / 2 / 2;

    REQUIRE(result == matho::Fraction{1, 1});
}

/* ============================================================
 *  devide by zero
 * ============================================================ */

TEST_CASE("number / zero Fraction throws", "[operator/][number]") {
    matho::Fraction zero{0, 1};

    REQUIRE_THROWS(1 / zero);
}

TEST_CASE("Fraction /= zero number throws", "[operator/=][number]") {
    matho::Fraction a{1, 2};

    REQUIRE_THROWS(a /= 0);
}

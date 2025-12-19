#include <catch2/catch_test_macros.hpp>

#include <matho/fraction.hpp>

using namespace matho;

/*
| Paramater   | Domain of Values |
| ----------- | ---------------- |
| numerator   | int              |
| denominator | int              |
*/

/*
Equivalence classes
- For `numerator` (The default denominator is 1):
| Class | Description               |
| ----- | ------------------------- |
| S1    | numerator < 0             |
| S2    | numerator = 0             |
| S3    | numerator > 0             |
*/

// S1
TEST_CASE("Constructor: numerator negative", "[constructor][single]") {
    Fraction frac(-3);

    REQUIRE(frac.get_numerator() == -3);
    REQUIRE(frac.get_denominator() == 1);
}

// S2
TEST_CASE("Constructor: numerator zero", "[constructor][single]") {
    Fraction frac(0);

    REQUIRE(frac.get_numerator() == 0);
    REQUIRE(frac.get_denominator() == 1);
}

// S3
TEST_CASE("Constructor: numerator positive", "[constructor][single]") {
    Fraction frac(3);

    REQUIRE(frac.get_numerator() == 3);
    REQUIRE(frac.get_denominator() == 1);
}

/*
Equivalence classes
- For `numerator`:
| Class | Description               |
| ----- | ------------------------- |
| N1    | numerator < 0             |
| N2    | numerator = 0             |
| N3    | numerator > 0             |

- For `denominator`:
| Class | Description               |
| ----- | ------------------------- |
| D1    | denominator < 0 (valid)   |
| D2    | denominator = 0 (invalid) |
| D3    | denominator > 0 (valid)   |
*/

// N1, D1
TEST_CASE(
    "Constructor: numerator negative, denominator negative",
    "[constructor][binary][normalization]"
) {
    matho::Fraction frac(-3, -4);

    REQUIRE(frac.get_numerator() == 3);
    REQUIRE(frac.get_denominator() == 4);
}

// N1, D2
TEST_CASE(
    "Constructor: numerator negative, denominator zero",
    "[constructor][binary][invalid][exception]"
) {
    REQUIRE_THROWS_AS(matho::Fraction(-3, 0), matho::InvalidFraction);
}

// N1, D3
TEST_CASE(
    "Constructor: numerator negative, denominator positive",
    "[constructor][binary]"
) {
    matho::Fraction frac(-3, 4);

    REQUIRE(frac.get_numerator() == -3);
    REQUIRE(frac.get_denominator() == 4);
}

// N2, D1
TEST_CASE(
    "Constructor: numerator zero, denominator negative",
    "[constructor][binary][normalization]"
) {
    matho::Fraction frac(0, -4);

    REQUIRE(frac.get_numerator() == 0);
    REQUIRE(frac.get_denominator() == 1);
}

// N2, D2: Already covered by N1, D2 test case

// N2, D3: Already covered by N2, D1 test case

// N3, D1
TEST_CASE(
    "Constructor: numerator positive, denominator negative",
    "[constructor][binary][normalization]"
) {
    matho::Fraction frac(3, -4);

    REQUIRE(frac.get_numerator() == -3);
    REQUIRE(frac.get_denominator() == 4);
}

// N3, D2: Already covered by N1, D2 test case

// N3, D3
TEST_CASE(
    "Constructor: numerator positive, denominator positive",
    "[constructor][binary]"
) {
    matho::Fraction frac(3, 4);

    REQUIRE(frac.get_numerator() == 3);
    REQUIRE(frac.get_denominator() == 4);
}

/*
Reduction classes:
| Class | Description   |
| ----- | ------------- |
| R1    | gcd(n, d) > 1 |
*/

// R1
TEST_CASE(
    "Constructor: reducible fraction",
    "[constructor][binary][reduction]"
) {
    Fraction frac(2, 4);

    REQUIRE(frac.get_numerator() == 1);
    REQUIRE(frac.get_denominator() == 2);
}

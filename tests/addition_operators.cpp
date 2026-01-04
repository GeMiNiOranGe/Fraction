#include <catch2/catch_test_macros.hpp>

#include <matho/fraction.hpp>

using namespace matho;

/*
================================================================================
fraction - fraction addition testcases
================================================================================
*/

/* 
Equivalence classes
- For `fraction`:
| Class | Description                  |
| ----- | ---------------------------- |
| F1    | positive fractions           |
| F2    | negative fractions           |
| F3    | fraction equals zero (`0/1`) |

- For `denominator`:
| Class | Description                               |
| ----- | ----------------------------------------- |
| D1    | Two fractions with the same denominator   |
| D2    | Two fractions with different denominators |
*/

// Addition

// F1 + F1, D1
TEST_CASE(
    "Addition: both are positive, same denominator",
    "[operator+]"
) {
    Fraction a(1, 3);
    Fraction b(1, 3);

    Fraction result = a + b;

    REQUIRE(result == Fraction(2, 3));
}

// F1 + F2, D1
TEST_CASE(
    "Addition: positive and negative, same denominator",
    "[operator+]"
) {
    Fraction a(1, 2);
    Fraction b(-1, 2);

    Fraction result = a + b;

    REQUIRE(result == Fraction(0, 1));
}

// F1 + F3, D1: Already covered by F1 + F3, D2 test case

// F1 + F1, D2
TEST_CASE(
    "Addition: both are positive, different denominators",
    "[operator+]"
) {
    Fraction a(1, 2);
    Fraction b(1, 3);

    Fraction result = a + b;

    REQUIRE(result == Fraction(5, 6));
}

// F1 + F2, D2: Already covered by F1 + F2, D1 test case

// F1 + F3, D2
TEST_CASE(
    "Addition: positive and fraction zero, different denominators",
    "[operator+]"
) {
    Fraction a(1, 2);
    Fraction zero(0, 1);

    Fraction result = a + zero;

    REQUIRE(result == Fraction(1, 2));
}

// F2 + F1, D1: Already covered by F1 + F2, D1 test case

// F2 + F2, D1
TEST_CASE(
    "Addition: both are negative, same denominator",
    "[operator+]"
) {
    Fraction a(-1, 3);
    Fraction b(-1, 3);

    Fraction result = a + b;

    REQUIRE(result == Fraction(-2, 3));
}

// F2 + F3, D1: Already covered by F1 + F3, D2 test case

// F2 + F1, D2: Already covered by F1 + F2, D1 test case

// F2 + F2, D2: Already covered by 'F2 + F2, D1' and 'F1 + F1, D2' test cases

// F2 + F3, D2: Already covered by F1 + F3, D2 test case

// F3 + F1, D1: Already covered by F1 + F3, D2 test case

// F3 + F2, D1: Already covered by F1 + F3, D2 test case

// F3 + F3, D1: Already covered by 'F3 + F1, D1' and 'F3 + F2, D1' test cases

// F3 + F1, D2: Already covered by F1 + F3, D2 test case

// F3 + F2, D2: Already covered by F1 + F3, D2 test case

// F3 + F3, D2: Already covered by F3 + F3, D1 test case

// Addition assignment
TEST_CASE(
    "Addition assignment: both are positive, same denominator",
    "[operator+=]"
) {
    Fraction a(1, 3);
    Fraction b(1, 3);

    a += b;

    REQUIRE(a == Fraction(2, 3));
}

TEST_CASE(
    "Addition assignment: positive and negative, same denominator",
    "[operator+=]"
) {
    Fraction a(1, 2);
    Fraction b(-1, 2);

    a += b;

    REQUIRE(a == Fraction(0, 1));
}

TEST_CASE(
    "Addition assignment: both are positive, different denominators",
    "[operator+=]"
) {
    Fraction a{1, 2};
    Fraction b{1, 3};

    a += b;

    REQUIRE(a == Fraction{5, 6});
}

TEST_CASE(
    "Addition assignment: positive and fraction zero, different denominators",
    "[operator+=]"
) {
    Fraction a(1, 2);
    Fraction zero(0, 1);

    a += zero;

    REQUIRE(a == Fraction(1, 2));
}

TEST_CASE(
    "Addition assignment: both are negative, same denominator",
    "[operator+=]"
) {
    Fraction a(-1, 3);
    Fraction b(-1, 3);

    a += b;

    REQUIRE(a == Fraction(-2, 3));
}

// other testcases
TEST_CASE("Addition: chained fraction addition", "[operator+]") {
    Fraction a(1, 2);
    Fraction b(1, 4);
    Fraction c(1, 8);

    Fraction result = a + b + c;

    REQUIRE(result == Fraction(7, 8));
}

TEST_CASE(
    "Consistency of addition and cumulative addition",
    "[operator+][operator+=]"
) {
    Fraction a(2, 3);
    Fraction b(1, 6);

    Fraction expected = a + b;

    a += b;

    REQUIRE(a == expected);
}

/*
================================================================================
fraction - number / numbner - fraction addition testcases
================================================================================
*/

/*
Equivalence classes
- For `fraction`:
| Class | Description                  |
| ----- | ---------------------------- |
| F1    | positive fractions           |
| F2    | negative fractions           |
| F3    | fraction equals zero (`0/1`) |

- For `number`:
| Class | Description |
| ----- | ----------- |
| N1    | number > 0  |
| N2    | number = 0  |
| N3    | number < 0  |
*/

// Addition

// F1 + N1
TEST_CASE("Addition: positive and positive number", "[operator+][number]") {
    Fraction a(1, 2);
    int number = 1;

    Fraction expected(3, 2);

    REQUIRE(a + number == expected);
    REQUIRE(number + a == expected);
}

// F1 + N2
TEST_CASE("Addition: positive and zero number", "[operator+][number]") {
    Fraction a(1, 2);
    int number = 0;

    Fraction expected(1, 2);

    REQUIRE(a + number == expected);
    REQUIRE(number + a == expected);
}

// F1 + N3 
TEST_CASE("Addition: positive and negative number", "[operator+][number]") {
    Fraction a(1, 2);
    int number = -1;

    Fraction expected(-1, 2);

    REQUIRE(a + number == expected);
    REQUIRE(number + a == expected);
}

// F2 + N1
TEST_CASE("Addition: negative and positive number", "[operator+][number]") {
    Fraction a(-1, 2);
    int number = 1;

    Fraction expected(1, 2);

    REQUIRE(a + number == expected);
    REQUIRE(number + a == expected);
}

// F2 + N2: Already covered by F1 + N2 test case

// F2 + N3: Already covered by F1 + N2 test case

// F3 + N1: Already covered by F1 + N2 test case

// F3 + N2: Already covered by F1 + N2 test case

// F3 + N3: Already covered by F1 + N2 test case

// Addition assignment
TEST_CASE(
    "Addition assignment: positive and positive number",
    "[operator+=][number]"
) {
    Fraction a(1, 4);
    int number = 1;

    a += number;

    REQUIRE(a == Fraction(5, 4));
}

TEST_CASE(
    "Addition assignment: positive and zero number",
    "[operator+][number]"
) {
    Fraction a(1, 2);
    int number = 0;

    a += number;

    REQUIRE(a == Fraction(1, 2));
}

TEST_CASE(
    "Addition assignment: positive and negative number",
    "[operator+=][number]"
) {
    Fraction a(3, 2);
    int number = -1;

    a += number;

    REQUIRE(a == Fraction(1, 2));
}

TEST_CASE(
    "Addition assignment: negative and positive number",
    "[operator+][number]"
) {
    Fraction a(-1, 2);
    int number = 1;

    a += number;

    REQUIRE(a == Fraction(1, 2));
}

// other testcases
TEST_CASE(
    "Addition: chained Fraction and number addition",
    "[operator+][number]"
) {
    Fraction a(1, 2);

    Fraction result = a + 1 + 2;

    REQUIRE(result == Fraction(7, 2));
}

TEST_CASE(
    "Consistency of addition and cumulative addition with numbers",
    "[operator+][operator+=][number]"
) {
    Fraction a(2, 3);
    int b = 2;

    Fraction expected = a + b;

    a += b;

    REQUIRE(a == expected);
}

/*
================================================================================
actual test cases
================================================================================
*/

// Addition
TEST_CASE("Addition: result is always normalized", "[operator+]") {
    Fraction a(1, 6);
    Fraction b(1, 6);

    Fraction result = a + b;

    REQUIRE(result == Fraction(1, 3));
}

TEST_CASE("Addition: operator+ does not mutate operands", "[operator+]") {
    Fraction a(1, 2);
    Fraction b(1, 3);

    Fraction _ = a + b;

    REQUIRE(a == Fraction(1, 2));
    REQUIRE(b == Fraction(1, 3));
}

// Addition assignment
TEST_CASE("Addition assignment: self addition", "[operator+=]") {
    Fraction a(1, 2);
    a += a;

    REQUIRE(a == Fraction(1, 1));
}

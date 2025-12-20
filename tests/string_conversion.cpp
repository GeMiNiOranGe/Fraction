#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <matho/fraction.hpp>

using namespace matho;

/*
Equivalence classes
| Class | Condition        | Output                  |
| ----- | ---------------- | ----------------------- |
| T1    | denominator == 1 | "numerator"             |
| T2    | denominator != 1 | "numerator/denominator" |
| T3    | numerator == 0   | "0"                     |
| T4    | numerator < 0    | string with sign        |
*/

TEST_CASE("to_string() produces correct format", "[string][to_string]") {
    auto [numerator, denominator, expected] = GENERATE(
        std::tuple<int, int, std::string>{1, 1, "1"},    // T1
        std::tuple<int, int, std::string>{1, 2, "1/2"},  // T2
        std::tuple<int, int, std::string>{0, 5, "0"},    // T3
        std::tuple<int, int, std::string>{-1, 2, "-1/2"} // T4
    );

    Fraction c(numerator, denominator);

    REQUIRE(c.to_string() == expected);
}

TEST_CASE("operator<< outputs same as to_string()", "[string][ostream]") {
    Fraction c(1.0, 2.0);

    std::ostringstream oss;
    oss << c;

    REQUIRE(oss.str() == c.to_string());
}

TEST_CASE(
    "operator>> parses two numbers into ComplexNumber",
    "[string][istream]"
) {
    std::istringstream iss("10.5 -7.25");
    Fraction c;

    iss >> c;

    REQUIRE(c.get_numerator() == Catch::Approx(10.5));
    REQUIRE(c.get_denominator() == Catch::Approx(-7.25));
}

TEST_CASE(
    "operator>> handles leading/trailing whitespace",
    "[string][istream]"
) {
    std::istringstream iss("   4.0   9.0   ");
    Fraction c;

    iss >> c;

    REQUIRE(c.get_numerator() == Catch::Approx(4.0));
    REQUIRE(c.get_denominator() == Catch::Approx(9.0));
}

TEST_CASE("Round trip: to_string -> parse", "[string][roundtrip]") {
    Fraction original(3.14159, -6.28);

    // to string
    std::string s = original.to_string();

    // parse
    std::istringstream iss(s);
    Fraction parsed;
    iss >> parsed;

    REQUIRE(parsed.get_numerator() == Catch::Approx(original.get_numerator()));
    REQUIRE(parsed.get_denominator() == Catch::Approx(original.get_denominator()));
}

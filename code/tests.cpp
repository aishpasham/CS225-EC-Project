#include <catch2/catch_test_macros.hpp>

#include "kmp.h"

#include <sstream>


TEST_CASE("Password Strength Prediction Complex Alphanumeric", "[weight=5]")
{
    std::string dataset = "../../data/data.csv";
    std::string password = "AVYq1lDE4MgAZfNt";
    int out = predictStrength(dataset, password);
    int expected = 5;
    REQUIRE(expected == out);
}

TEST_CASE("Password Strength Prediction Simple Numeric", "[weight=5]")
{
    std::string dataset = "../../data/passwords.csv";
    std::string password = "111111";
    int out = predictStrength(dataset, password);
    int expected = 1;
    REQUIRE(expected == out);
}

TEST_CASE("Common Pattern Name", "[weight=5]")
{
    std::string dataset = "../../data/500-worst-passwords.txt";
    std::string password = "joseph";
    std::string out = commonPattern(dataset, password);
    std::string expected = "Name";
    REQUIRE(expected == out);
}
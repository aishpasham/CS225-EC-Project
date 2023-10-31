#include <catch2/catch_test_macros.hpp>

#include "kmp.h"

#include <sstream>


TEST_CASE("Find Repeats Numeric", "[weight=5]")
{
    std::string dataset = "../../data/500-worst-passwords.txt";
    
    std::vector<int> out = findRepeats(dataset, "123");

    std::vector<int> expected = {0, 3};

    REQUIRE(out.size() == expected.size())
    
    //95 is index of password where password "123123" occurs in dataset
    REQUIRE(out.at(95) == expected);
}

TEST_CASE("Find Repeats Alphabetic", "[weight=5]")
{
    std::string dataset = "../../data/passwords.csv";
    
    std::vector<int> out = findRepeats(dataset, "aa");

    std::vector<int> expected = {0, 2, 4};

    REQUIRE(out.size() == expected.size())
    
    //105 is index of password where password "aaaaaa" occurs in dataset
    REQUIRE(out.at(105) == expected);
}

TEST_CASE("Password Strength Prediction", "[weight=5]")
{
    std::string dataset = "../../data/passwords.csv";
    
    int out = predictStrength(dataset, "aaaaaa", "aa");

    std::vector<int> expected = 1;
    
    REQUIRE(out == expected);
}
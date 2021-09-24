#include <stdexcept>
#include "catch.hpp"
#include "stacks_and_queues.h"

TEST_CASE("test the stacks and queues functions")
{
    SECTION("test postfix_evaluation") {
        REQUIRE(postfix_evaluation("42") == 42);
        REQUIRE(postfix_evaluation("20 6 +") == 26);
        REQUIRE(postfix_evaluation("20 6 -") == 14);
        REQUIRE(postfix_evaluation("20 6 *") == 120);
        REQUIRE(postfix_evaluation("20 6 /") == 3);
        REQUIRE(postfix_evaluation("1 5 2 * 20 6 / - +") == 8);
        REQUIRE(postfix_evaluation("4 8 15 16 23 42 + + + + +")
            == 108);
        REQUIRE(postfix_evaluation("1 2+3 4+5 6+7 8+9 10+++++")
            == 55);
        REQUIRE(postfix_evaluation("1 2*3 4*5 6*7 8*9 10*++++")
            == 190);
        REQUIRE(postfix_evaluation("30 2/3/5/2*5 2*+12-0 11-6*+")
            == -66);
        REQUIRE_THROWS_AS(postfix_evaluation("1 2 3 *"),
            std::invalid_argument);
        REQUIRE_THROWS_AS(postfix_evaluation("1 2 3 * * *"),
            std::invalid_argument);
        REQUIRE_THROWS_AS(postfix_evaluation("+"),
            std::invalid_argument);
        REQUIRE_THROWS_AS(postfix_evaluation("-"),
            std::invalid_argument);
        REQUIRE_THROWS_AS(postfix_evaluation("/"),
            std::invalid_argument);
        REQUIRE_THROWS_AS(postfix_evaluation(""),
            std::invalid_argument);
        REQUIRE_THROWS_AS(postfix_evaluation("1 2 @"),
            std::invalid_argument);
        REQUIRE_THROWS_AS(postfix_evaluation("10 11 + 5 % 13 *"),
            std::invalid_argument);
    }

    SECTION("test balanced_brackets") {
        REQUIRE(balanced_brackets(""));
        REQUIRE(balanced_brackets("(7)"));
        REQUIRE(balanced_brackets("[]{}()([]{})"));
        REQUIRE(balanced_brackets("[({(([[{}][{}][{}]]))})]"));
        REQUIRE_FALSE(balanced_brackets("{"));
        REQUIRE_FALSE(balanced_brackets("}"));
        REQUIRE_FALSE(balanced_brackets("]({})"));
        REQUIRE_FALSE(balanced_brackets("(((("));
        REQUIRE_FALSE(balanced_brackets("))))"));
        REQUIRE_FALSE(balanced_brackets("(]{)[}"));
        REQUIRE_FALSE(balanced_brackets("[]{}()[]{})([])"));
        REQUIRE_FALSE(balanced_brackets("[[({(([[{}][{}][{}]]))})]"));
    }
}

#include <stdexcept>
#include <vector>
#include "catch.hpp"
#include "hashtable.h"

TEST_CASE("test the HashTable class")
{
    HashTable<double, bool> a(25);

    HashTable<std::string, int> b(7);
    b.put("one", 1);
    b.put("two", 2);
    b.put("three", 3);
    b.put("four", 4);
    b.put("five", 5);
    b.put("six", 6);
    b.put("seven", 7);

    HashTable<int, std::string> c(99);
    c.put(1, "I");
    c.put(2, "II");
    c.put(3, "III");
    c.put(4, "IV");
    c.put(5, "V");
    c.put(6, "VI");
    c.put(7, "VII");
    c.put(8, "VIII");
    c.put(9, "IX");
    c.put(10, "X");
    c.put(11, "XI");
    c.put(12, "XII");
    c.put(13, "XIII");
    c.put(14, "XIV");
    c.put(15, "XV");
    c.put(16, "XVI");
    c.put(17, "XVII");
    c.put(18, "XVIII");
    c.put(19, "XIX");
    c.put(20, "XX");
    c.put(50, "L");
    c.put(100, "C");
    c.put(500, "D");
    c.put(1'000, "M");

    HashTable<int, int> d(1'000);
    for (int i = 0; i < 100'000; ++i) {
        d.put(i, i * 2 - 1);
    }

    SECTION("test put") {
        REQUIRE(a.put(0.0, false));
        REQUIRE_FALSE(a.put(0.0, true));
        REQUIRE_FALSE(b.put("one", 1));
        REQUIRE(b.put("eight", 8));
        REQUIRE_FALSE(c.put(10, "X"));
        REQUIRE(c.put(2'000, "MM"));
        REQUIRE_FALSE(d.put(99'999, 199'997));
        REQUIRE(d.put(-1, -3));
    }

    // SECTION("test size") {
    //     REQUIRE(a.size() == 0);
    //     REQUIRE(b.size() == 7);
    //     REQUIRE(c.size() == 24);
    //     REQUIRE(d.size() == 100'000);
    // }

    // SECTION("test is_empty") {
    //     REQUIRE(a.is_empty());
    //     REQUIRE_FALSE(b.is_empty());
    //     REQUIRE_FALSE(c.is_empty());
    //     REQUIRE_FALSE(d.is_empty());
    // }

    SECTION("test contains_key") {
        REQUIRE_FALSE(a.contains_key(0.0));
        REQUIRE_FALSE(a.contains_key(3.1416));
        REQUIRE(b.contains_key("one"));
        REQUIRE_FALSE(b.contains_key("ten"));
        REQUIRE(c.contains_key(15));
        REQUIRE_FALSE(c.contains_key(2'000));
        REQUIRE(d.contains_key(99'999));
        REQUIRE_FALSE(d.contains_key(-1));
    }

    // SECTION("test get") {
    //     REQUIRE_THROWS_AS(a.get(0.0), std::invalid_argument);
    //     REQUIRE_THROWS_AS(a.get(3.1416), std::invalid_argument);
    //     REQUIRE(a.put(0.0, true));
    //     REQUIRE(a.put(3.1416, false));
    //     REQUIRE(a.get(0.0) == true);
    //     REQUIRE(a.get(3.1416) == false);
    //     REQUIRE_FALSE(a.put(3.1416, true));
    //     REQUIRE(a.get(3.1416) == true);
    //     REQUIRE(b.get("five") == 5);
    //     REQUIRE_THROWS_AS(b.get("ten"), std::invalid_argument);
    //     REQUIRE(b.put("ten", 10));
    //     REQUIRE(b.get("ten") == 10);
    //     REQUIRE_FALSE(b.put("five", 50));
    //     REQUIRE(b.get("five") == 50);
    //     REQUIRE(c.get(19) == "XIX");
    //     REQUIRE_THROWS_AS(c.get(2'000), std::invalid_argument);
    //     REQUIRE(c.put(2'000, "MM"));
    //     REQUIRE(c.get(2'000) == "MM");
    //     REQUIRE_FALSE(c.put(19, "other"));
    //     REQUIRE(c.get(19) == "other");
    //     REQUIRE(d.get(99'999) == 199'997);
    //     REQUIRE_THROWS_AS(c.get(-1), std::invalid_argument);
    //     REQUIRE(d.put(-1, -3));
    //     REQUIRE(d.get(-1) == -3);
    //     REQUIRE_FALSE(d.put(99'999, 0));
    //     REQUIRE(d.get(99'999) == 0);
    // }

    // SECTION("test get_or_default") {
    //     REQUIRE(a.get_or_default(0.0, true) == true);
    //     REQUIRE(a.get_or_default(3.1416, false) == false);
    //     REQUIRE(b.get_or_default("five", 0) == 5);
    //     REQUIRE(b.get_or_default("other", 666) == 666);
    //     REQUIRE(c.get_or_default(19, "unknown") == "XIX");
    //     REQUIRE(c.get_or_default(2'000, "unknown") == "unknown");
    //     REQUIRE(d.get_or_default(99'999, 42) == 199'997);
    //     REQUIRE(d.get_or_default(-1, 42) == 42);
    // }

    // SECTION("test remove") {
    //     REQUIRE_FALSE(a.remove(0.0));
    //     REQUIRE_FALSE(a.remove(3.1416));
    //     REQUIRE(a.is_empty());
    //     REQUIRE(b.remove("five"));
    //     REQUIRE_FALSE(b.remove("other"));
    //     REQUIRE(b.size() == 6);
    //     REQUIRE(c.remove(19));
    //     REQUIRE_FALSE(c.remove(2'000));
    //     REQUIRE(c.size() == 23);
    //     REQUIRE_FALSE(d.remove(-1));
    //     for (int i = 0; i < 100'000; ++i) {
    //         REQUIRE(d.remove(i));
    //     }
    //     REQUIRE(d.is_empty());
    // }

    // SECTION("test clear") {
    //     a.clear();
    //     REQUIRE(a.is_empty());
    //     b.clear();
    //     REQUIRE(b.is_empty());
    //     c.clear();
    //     REQUIRE(c.is_empty());
    //     d.clear();
    //     REQUIRE(d.is_empty());
    // }

    // SECTION("test operator==") {
    //     REQUIRE(a == a);
    //     REQUIRE(b == b);
    //     REQUIRE(c == c);
    //     REQUIRE(d == d);
    //     HashTable<std::string, int> e(20);
    //     REQUIRE_FALSE(b == e);
    //     REQUIRE(e.put("seven", 7));
    //     REQUIRE_FALSE(b == e);
    //     REQUIRE(e.put("six", 6));
    //     REQUIRE_FALSE(b == e);
    //     REQUIRE(e.put("five", 5));
    //     REQUIRE_FALSE(b == e);
    //     REQUIRE(e.put("four", 4));
    //     REQUIRE_FALSE(b == e);
    //     REQUIRE(e.put("three", 3));
    //     REQUIRE_FALSE(b == e);;
    //     REQUIRE(e.put("two", 2));
    //     REQUIRE_FALSE(b == e);
    //     REQUIRE(e.put("one", -1));
    //     REQUIRE_FALSE(b == e);
    //     REQUIRE_FALSE(e.put("one", 1));
    //     REQUIRE(b == e);
    //     REQUIRE(e == b);
    // }

    // SECTION("test keys") {
    //     REQUIRE(a.keys() == std::vector<double> {});
    //     REQUIRE(b.keys() ==
    //         std::vector<std::string> {"five", "four", "one", "seven",
    //             "six", "three", "two"});
    //     REQUIRE(c.keys() ==
    //         std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    //             13, 14, 15, 16, 17, 18, 19, 20, 50, 100, 500, 1'000});
    //     std::vector<int> k;
    //     k.reserve(100'000);
    //     for (int i = 0; i < 100'000; ++i) {
    //         k.push_back(i);
    //     }
    //     REQUIRE(d.keys() == k);
    // }

    // SECTION("test put_all") {
    //     HashTable<double, bool> e(10);
    //     REQUIRE(e.put(3.1416, true));
    //     REQUIRE(e.put(1.618, false));
    //     REQUIRE(e.put(2.7182, true));
    //     a.put_all(e);
    //     REQUIRE(a == e);
    //     REQUIRE_FALSE(a.put(1.618, true));
    //     REQUIRE_FALSE(a == e);
    //     HashTable<std::string, int> f(99);
    //     HashTable<std::string, int> g(9);
    //     REQUIRE(f == g);
    //     f.put_all(g);
    //     REQUIRE(f == g);
    //     REQUIRE(f.put("one", -1));
    //     REQUIRE(f.put("five", -5));
    //     REQUIRE(f.put("eight", 8));
    //     REQUIRE(f.put("nine", 9));
    //     REQUIRE(f.put("ten", 10));
    //     REQUIRE_FALSE(f == g);
    //     g.put_all(f);
    //     REQUIRE(f == g);
    //     g.put_all(b);
    //     REQUIRE_FALSE(g == b);
    //     b.put_all(f);
    //     REQUIRE_FALSE(b == g);
    //     REQUIRE_FALSE(g.put("five", -5));
    //     REQUIRE_FALSE(g.put("one", -1));
    //     REQUIRE(b == g);
    //     b.put_all(g);
    //     REQUIRE(b == g);
    //     g.put_all(b);
    //     REQUIRE(g == b);
    // }
}

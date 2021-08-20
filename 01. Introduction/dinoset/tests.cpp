#include "catch.hpp"
#include "dinoset.h"

TEST_CASE("test the DinoSet class")
{
    DinoSet a;

    DinoSet b;
    b.add(DinoId::velocirraptor);
    b.add(DinoId::tiranosaurio);

    DinoSet c;
    c.add(DinoId::tiranosaurio);
    c.add(DinoId::procompsagnatus);
    c.add(DinoId::pteranodon);

    // SECTION("test to_string") {
    //     REQUIRE(a.to_string() == "{}");
    //     REQUIRE(b.to_string() == "{velocirraptor, tiranosaurio}");
    //     REQUIRE(c.to_string()
    //         == "{tiranosaurio, procompsagnatus, pteranodon}");
    // }

    SECTION("test contains") {
        REQUIRE_FALSE(a.contains(DinoId::velocirraptor));
        REQUIRE_FALSE(a.contains(DinoId::estegosaurio));
        REQUIRE_FALSE(a.contains(DinoId::tiranosaurio));
        REQUIRE_FALSE(a.contains(DinoId::procompsagnatus));
        REQUIRE_FALSE(a.contains(DinoId::triceratops));
        REQUIRE_FALSE(a.contains(DinoId::paquicefalosaurio));
        REQUIRE_FALSE(a.contains(DinoId::parasaurolofus));
        REQUIRE_FALSE(a.contains(DinoId::pteranodon));

        REQUIRE(b.contains(DinoId::velocirraptor));
        REQUIRE_FALSE(b.contains(DinoId::estegosaurio));
        REQUIRE(b.contains(DinoId::tiranosaurio));
        REQUIRE_FALSE(b.contains(DinoId::procompsagnatus));
        REQUIRE_FALSE(b.contains(DinoId::triceratops));
        REQUIRE_FALSE(b.contains(DinoId::paquicefalosaurio));
        REQUIRE_FALSE(b.contains(DinoId::parasaurolofus));
        REQUIRE_FALSE(b.contains(DinoId::pteranodon));

        REQUIRE_FALSE(c.contains(DinoId::velocirraptor));
        REQUIRE_FALSE(c.contains(DinoId::estegosaurio));
        REQUIRE(c.contains(DinoId::tiranosaurio));
        REQUIRE(c.contains(DinoId::procompsagnatus));
        REQUIRE_FALSE(c.contains(DinoId::triceratops));
        REQUIRE_FALSE(c.contains(DinoId::paquicefalosaurio));
        REQUIRE_FALSE(c.contains(DinoId::parasaurolofus));
        REQUIRE(c.contains(DinoId::pteranodon));
    }

    SECTION("test size") {
        REQUIRE(a.size() == 0);
        REQUIRE(b.size() == 2);
        REQUIRE(c.size() == 3);
    }

    // SECTION("test is_empty") {
    //     REQUIRE(a.is_empty());
    //     REQUIRE_FALSE(b.is_empty());
    //     REQUIRE_FALSE(c.is_empty());
    // }

    // SECTION("test remove") {
    //     REQUIRE(c.size() == 3);
    //     REQUIRE(c.contains(DinoId::procompsagnatus));
    //     c.remove(DinoId::procompsagnatus);
    //     REQUIRE(c.size() == 2);
    //     REQUIRE_FALSE(c.contains(DinoId::procompsagnatus));
    //     REQUIRE(c.to_string() == "{tiranosaurio, pteranodon}");
    //     REQUIRE(c.contains(DinoId::tiranosaurio));
    //     c.remove(DinoId::tiranosaurio);
    //     REQUIRE(c.size() == 1);
    //     REQUIRE_FALSE(c.contains(DinoId::tiranosaurio));
    //     REQUIRE(c.to_string() == "{pteranodon}");
    //     REQUIRE(c.contains(DinoId::pteranodon));
    //     c.remove(DinoId::pteranodon);
    //     REQUIRE(c.is_empty());
    //     REQUIRE_FALSE(c.contains(DinoId::pteranodon));
    //     REQUIRE(c.to_string() == "{}");

    //     REQUIRE(b.size() == 2);
    //     REQUIRE(b.contains(DinoId::tiranosaurio));
    //     b.remove(DinoId::tiranosaurio);
    //     REQUIRE(b.size() == 1);
    //     REQUIRE_FALSE(b.contains(DinoId::tiranosaurio));
    //     REQUIRE(b.to_string() == "{velocirraptor}");
    //     REQUIRE(b.contains(DinoId::velocirraptor));
    //     b.remove(DinoId::velocirraptor);
    //     REQUIRE(b.is_empty());
    //     REQUIRE_FALSE(b.contains(DinoId::velocirraptor));
    //     REQUIRE(b.to_string() == "{}");

    //     REQUIRE(a.is_empty());
    //     REQUIRE_FALSE(a.contains(DinoId::tiranosaurio));
    //     a.remove(DinoId::tiranosaurio);
    //     REQUIRE(a.is_empty());
    //     REQUIRE_FALSE(a.contains(DinoId::tiranosaurio));
    //     REQUIRE(a.to_string() == "{}");
    //     REQUIRE_FALSE(a.contains(DinoId::pteranodon));
    //     a.remove(DinoId::pteranodon);
    //     REQUIRE(a.is_empty());
    //     REQUIRE_FALSE(a.contains(DinoId::pteranodon));
    //     REQUIRE(a.to_string() == "{}");
    // }

    // SECTION("test +") {
    //     REQUIRE((a + b).to_string()
    //         == "{velocirraptor, tiranosaurio}");
    //     REQUIRE((a + c).to_string()
    //         == "{tiranosaurio, procompsagnatus, pteranodon}");
    //     REQUIRE((b + c).to_string()
    //         == "{velocirraptor, tiranosaurio, procompsagnatus, "
    //           "pteranodon}");
    //     REQUIRE((c + b).to_string()
    //         == "{velocirraptor, tiranosaurio, procompsagnatus, "
    //           "pteranodon}");
    // }

    // SECTION("test *") {
    //     REQUIRE((a * b).to_string() == "{}");
    //     REQUIRE((a * c).to_string() == "{}");
    //     REQUIRE((b * c).to_string() == "{tiranosaurio}");
    //     REQUIRE((c * b).to_string() == "{tiranosaurio}");
    // }

    // SECTION("test -") {
    //     REQUIRE((a - b).to_string() == "{}");
    //     REQUIRE((b - a).to_string()
    //         == "{velocirraptor, tiranosaurio}");
    //     REQUIRE((a - c).to_string() == "{}");
    //     REQUIRE((c - a).to_string()
    //         == "{tiranosaurio, procompsagnatus, pteranodon}");
    //     REQUIRE((b - c).to_string() == "{velocirraptor}");
    //     REQUIRE((c - b).to_string()
    //         == "{procompsagnatus, pteranodon}");
    // }

    // SECTION("test !")
    // {
    //     REQUIRE((!a).to_string()
    //         == "{velocirraptor, estegosaurio, tiranosaurio, "
    //           "procompsagnatus, triceratops, paquicefalosaurio, "
    //           "parasaurolofus, pteranodon}");
    //     REQUIRE((!b).to_string()
    //         == "{estegosaurio, procompsagnatus, triceratops, "
    //           "paquicefalosaurio, parasaurolofus, pteranodon}");
    //     REQUIRE((!c).to_string()
    //         == "{velocirraptor, estegosaurio, triceratops, "
    //           "paquicefalosaurio, parasaurolofus}");
    // }

    // SECTION("test ==") {
    //     DinoSet x;

    //     DinoSet y;
    //     y.add(DinoId::tiranosaurio);
    //     y.add(DinoId::velocirraptor);

    //     DinoSet z;
    //     z.add(DinoId::procompsagnatus);
    //     z.add(DinoId::pteranodon);
    //     z.add(DinoId::tiranosaurio);

    //     REQUIRE(a == a);
    //     REQUIRE(a == x);
    //     REQUIRE_FALSE(a == y);
    //     REQUIRE_FALSE(a == z);

    //     REQUIRE(b == b);
    //     REQUIRE_FALSE(b == x);
    //     REQUIRE(b == y);
    //     REQUIRE_FALSE(b == z);

    //     REQUIRE(c == c);
    //     REQUIRE_FALSE(c == x);
    //     REQUIRE_FALSE(c == y);
    //     REQUIRE(c == z);
    // }
}

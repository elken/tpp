#include <include.hpp>
#include "../src/expression/include.hpp"

TEST_CASE("Expression", "[exp]") {
    SECTION("Add single node") {
        tpp::expression::Expression e;
        std::size_t size = e.size();
        e.append(ZERO);
        REQUIRE(e.size() == size+1);
    } SECTION("Add multiple nodes") {
        tpp::expression::Expression e({ZERO, ZERO, ONE, ZERO});
        tpp::expression::Expression e2;
        e2.append(ZERO);
        e2.append(ZERO);
        e2.append(ONE);
        e2.append(ZERO);
        REQUIRE(e == e2);
    } SECTION("Add multiple nodes (initializer list)") {
        tpp::expression::Expression e({ZERO, ZERO, ZERO, ZERO});
        REQUIRE(e.size() == 4);
    } SECTION("Fill empty expression") {
        tpp::expression::Expression e;
        tpp::expression::Expression e2({ZERO, ZERO, ZERO, ZERO, ZERO});
        std::size_t size = e.size();
        e.fill(ZERO, 5);
        REQUIRE(e.size() == 5);
        REQUIRE(e == e2);
    } SECTION("Fill pre-existing expression") {
        tpp::expression::Expression e({ZERO, ONE});
        tpp::expression::Expression e2({ZERO, ONE, ONE, ONE, ONE});
        std::size_t size = e.size();
        e.fill(ONE, 3);
        REQUIRE(e.size() == 5);
        REQUIRE(e == e2);
    }
}
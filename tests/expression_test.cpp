#include <gtest/gtest.h>
#include <expression/include.hpp>

TEST(Expression, ExpressionTestAppendNode) {
    tpp::expression::Expression expression;
    std::size_t size = expression.size();
    expression.append(ZERO);
    EXPECT_EQ(expression.size(), size+1);
}
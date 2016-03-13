#include <iostream>
#include <globals.hpp>
#include <expression/include.hpp>

using namespace std;

int main()
{
    tpp::expression::Expression e({ZERO, ONE, ZERO, ONE});

    for (auto elem : e) {
        std::cout << elem << std::endl;
    }
}
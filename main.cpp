#include <iostream>
#include <globals.hpp>
#include <expression/include.hpp>

using namespace std;

int main()
{
    tpp::expression::Expression e;
    e.append(ZERO);
    e.append(ONE);
    e.append(ZERO);
    e.append(ONE);
    for (auto elem : e) {
        std::cout << elem << std::endl;
    }
}
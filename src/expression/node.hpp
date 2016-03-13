#ifndef TPP_EXPRESSION_NODE_HPP
#define TPP_EXPRESSION_NODE_HPP
#include <globals.hpp>

namespace tpp {
namespace expression {
struct Node {
    Node* prev;
    Node* next;
    byte value;
    Node(byte value) : value(value), prev(nullptr), next(nullptr) { }
    Node() : value(BLANK), prev(nullptr), next(nullptr) { }
};
}
} // tpp
#endif //TPP_EXPRESSION_NODE_HPP

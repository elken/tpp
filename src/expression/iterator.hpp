#ifndef TPP_EXPRESSION_ITERATOR_HPP
#define TPP_EXPRESSION_ITERATOR_HPP

#include <globals.hpp>
#include "node.hpp"
#include <iostream>

namespace tpp {
namespace expression {

class Iterator {
    Node* node;
public:
    Iterator(Node* ptr) : node(ptr) {}
    Iterator(const Iterator& rhs) : node(rhs.node) {}
    Iterator& operator++() { node = node->next; return *this; }
    Iterator& operator--() { node = node->prev; return *this; }
    bool operator!=(const Iterator& rhs) { return node != rhs.node; }
    bool operator==(const Iterator& rhs) { return node == rhs.node; }
    byte& operator*() { return node->value; }
};

class ConstIterator {
    const Node* node;
public:
    ConstIterator(const Node* ptr) : node(ptr) {}
    ConstIterator(const ConstIterator& rhs) : node(rhs.node) {}
    ConstIterator& operator++() { node = node->next; return *this; }
    ConstIterator& operator--() { node = node->prev; return *this; }
    bool operator!=(const ConstIterator& rhs) { return node != rhs.node; }
    bool operator==(const ConstIterator& rhs) { return node == rhs.node; }
    const byte& operator*() const { return node->value; }
};
} // expression
} // tpp
#endif //TPP_EXPRESSION_ITERATOR_HPP

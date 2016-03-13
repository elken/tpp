#ifndef TPP_EXPRESSION_HPP
#define TPP_EXPRESSION_HPP

#include <cstddef>
#include <globals.hpp>
#include "node.hpp"
#include "iterator.hpp"
#include <iostream>

namespace tpp {
namespace expression {
class Expression {
    std::size_t _size;
    Node* left;
    Node* right;

public:
    void append(byte val) {
        Node* node = new Node(val);
        if (right != nullptr) {
            Node* tmp = right;
            tmp->next = node;
            right = node;
            right->prev = tmp;
        } else {
            left = right = node;
        }
        _size++;
    }

    Iterator begin() {
        return Iterator(left);
    }

    const ConstIterator cbegin() const {
        return ConstIterator(left);
    }

    Iterator end() {
        return Iterator(right->next);
    }

    const ConstIterator cend() const {
        return ConstIterator(right->next);
    }

    std::size_t size() {
        return _size;
    }

    bool is_empty() {
        return _size == 0;
    }

    Expression() : _size(0), left(nullptr), right(nullptr) {
    }

    Expression(std::initializer_list<byte> list) : _size(list.size()), left(nullptr), right(nullptr) {
        for (auto item : list) {
            append(item);
        }
    }

    ~Expression() {
        Node* node = right;
        while (node != nullptr) {
            Node* old_back = node;
            node = node->prev;
            delete old_back;
        }
        left = nullptr;
        right = nullptr;
    }
};
} // expression
} // tpp
#endif //TPP_EXPRESSION_HPP

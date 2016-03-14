#ifndef TPP_EXPRESSION_HPP
#define TPP_EXPRESSION_HPP

#include <cstddef>
#include <globals.hpp>
#include "node.hpp"
#include "iterator.hpp"
#include <iostream>
#include <chrono>

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

    void fill(byte val, int count) {
        for (int i = 0; i < count; ++i) {
            append(val);
        }
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

    bool operator==(Expression& e) {
        if (e.size() == _size) {
            Iterator lhs_begin = begin();
            Iterator lhs_end = end();
            Iterator rhs_begin = e.begin();
            Iterator rhs_end = e.end();
            for (; lhs_begin != lhs_end, rhs_begin != rhs_end; ++lhs_begin, ++rhs_begin) {
                if (*lhs_begin != *rhs_begin) {
                    return false;
                }
            }
        }
        return true;
    }

    std::size_t size() {
        return _size;
    }

    bool is_empty() {
        return _size == 0;
    }

    Expression() : _size(0), left(nullptr), right(nullptr) {
    }

    Expression(std::initializer_list<byte> list) : _size(0), left(nullptr), right(nullptr) {
        for (auto item : list) {
            append(item);
        }
    }

    ~Expression() {
        auto start = std::chrono::high_resolution_clock::now();
        Node* node = right;
        while (node != nullptr) {
            Node* old_back = node;
            node = node->prev;
            delete old_back;
        }
        left = nullptr;
        right = nullptr;
        std::cout << "Deconstruction took " << std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count() << std::endl;
    }
};
} // expression
} // tpp
#endif //TPP_EXPRESSION_HPP

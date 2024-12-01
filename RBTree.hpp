//=========================================================
// RBTree.hpp
// Authors : Kien, Trinity, James
// 11/24/2024
//
// This is the header file with definitions of functions for the RBTree class
//=========================================================
#include <iostream>
using namespace std;

#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "HashMapTree.hpp"
#include "RBTreeNode.hpp"
#include <utility>
#include "customexceptions.hpp"

template <class T>
class RBTree
{
private:
    RBTreeNode<T> *root;
    RBTreeNode<T> *NIL = new RBTreeNode<T>();
    long rbt_size;

    bool is_balanced_helper(RBTreeNode<T> *node, int currentBlackHeight, int &expectedBlackHeight) const;

    void transplant(RBTreeNode<T> *oldNode, RBTreeNode<T> *newNode);
    void insert_fixup(RBTreeNode<T> *z);
    void delete_fixup(RBTreeNode<T> *node);
    void left_rotate(RBTreeNode<T> *node);
    void right_rotate(RBTreeNode<T> *node);
    void NIL_fixup();

    RBTreeNode<T> *copy(const RBTreeNode<T> *node, const RBTree<T> &tree);
    void deallocate(RBTreeNode<T> *node);

public:
    RBTree();
    RBTree(const RBTree<T> &tree);
    ~RBTree();
    RBTree<T> &operator=(const RBTree<T> &tree);

    bool isEmpty() const;
    long size() const;
    RBTreeNode<T> *search(const T &value);
    RBTreeNode<T> *treeMin() const;
    RBTreeNode<T> *treeMax() const;

    bool is_balanced() const;

    void printPreOrderTraversal() const;
    void printInOrderTraversal() const;
    void printPostOrderTraversal() const;

    RBTreeNode<T> *insert(T value);
    void remove(T value);   
};

template <class T>
bool operator==(const std::pair<T, T>& lhs, const std::pair<T, T>& rhs) {
    // Compare both elements in the pair
    return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <class T>
bool operator<(const std::pair<T, T>& lhs, const std::pair<T, T>& rhs) {
    // First compare the first element of the pair
    if (lhs.first != rhs.first)
        return lhs.first < rhs.first;
    // If they are equal, compare the second element
    return lhs.second < rhs.second;
}
#endif
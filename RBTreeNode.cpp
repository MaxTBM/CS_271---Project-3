/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
RBTreeNode.cpp
This file contains the implementations of the red-black tree node functions
===========================================================================*/
#include <iostream>
#include "RBTreeNode.hpp"

using namespace std;

// ============================================================
// Default constructor for RBTreeNode class. Initializes the node 
// with a null value, red color, and null pointers for left, right, 
// and parent pointers.
// Parameter: templated RBTreeNode data class
// ============================================================
template <class T>
RBTreeNode<T>::RBTreeNode()
{
    val = T();
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    color = BLACK;
}

// ============================================================
// Constructor for RBTreeNode class. Initializes the node with 
// the specified value, color, and null pointers for left, right, 
// and parent pointers.
// Parameter: T value - The data value to store in the node.
// ============================================================
template <class T>
RBTreeNode<T>::RBTreeNode(T value)
{
    val = value;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    color = RED;
}

// ============================================================
// Constructor for RBTreeNode class. Initializes the node with 
// the specified value, color, and null pointers for left, right, 
// and parent pointers.
// Parameter: T node - value of the node
// ============================================================
template <class T>
RBTreeNode<T>::RBTreeNode(const RBTreeNode<T> &node)
{
    val = node.val;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color = node.color;
}

// ============================================================
// Destructor for RBTreeNode class. Does not delete any children 
// as they are deleted by the parent node.
// Parameter: None.
// ============================================================
template <class T>
RBTreeNode<T>::~RBTreeNode(void){};

// ============================================================
// Assignment operator for RBTreeNode class. Copies the data, color,
// and recursively copies the left and right children from another node.
// Parameter: const RBTreeNode<T> &node - The node to copy from.
// Return: A reference to the current node.
// ============================================================
template <class T>
RBTreeNode<T> &RBTreeNode<T>::operator=(const RBTreeNode<T> &node)
{
    if (this == &node)
    {
        return *this;
    }
    val = node.val;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color = node.color;
    return *this;
};

// ============================================================
// Finds the node with the minimum value in the subtree rooted at 
// the current node by recursively traversing the left child.
// Parameter: None.
// Return: A pointer to the node with the minimum value in the 
//         subtree rooted at the current node.
// ============================================================
template <class T>
RBTreeNode<T> *RBTreeNode<T>::treeMin()
{
    if (left->left == nullptr)
    {
        return this;
    }
    else
    {
        return left->treeMin();
    };
};

// ============================================================
// Finds the node with the maximum value in the subtree rooted at 
// the current node by recursively traversing the right child.
// Parameter: None.
// Return: A pointer to the node with the maximum value in the 
//         subtree rooted at the current node.
// ============================================================
template <class T>
RBTreeNode<T> *RBTreeNode<T>::treeMax()
{
    if (right->right == nullptr)
    {
        return this;
    }
    else
    {
        return right->treeMax();
    };
};

// ============================================================
// Prints the values of the nodes in the subtree rooted at the 
// current node in pre-order traversal (root, left, right).
// Parameter: None.
// Return: None.
// ============================================================
template <class T>
void RBTreeNode<T>::printPreOrderTraversal() const
{
    cout << val << " ";

    if (left->left != nullptr)
    {
        left->printPreOrderTraversal();
    };

    if (right->right != nullptr)
    {
        right->printPreOrderTraversal();
    };
};

// ============================================================
// Prints the values of the nodes in the subtree rooted at the 
// current node in in-order traversal (left, root, right).
// Parameter: visit - A function that processes each node's data.
// Return: None.
// ============================================================
template <class T>
void RBTreeNode<T>::printInOrderTraversal(std::function<void(const T&)> visit) const {
        if (left) {
            left->printInOrderTraversal(visit);
        }
        visit(val); // Process the current node's data
         if (right) {
            right->printInOrderTraversal(visit);
        }
    }

// ============================================================
// Prints the values of the nodes in the subtree rooted at the 
// current node in in-order traversal (left, root, right).
// Parameter: None.
// Return: None.
// ============================================================
template <class T>
void RBTreeNode<T>::printPostOrderTraversal() const
{
    if (left->left != nullptr)
    {
        left->printPostOrderTraversal();
    };

    if (right->right != nullptr)
    {
        right->printPostOrderTraversal();
    };

    cout << val << " ";
};

// ============================================================
// Returns a reference to the value stored in the current node.
// Parameter: None.
// Return: A reference to the value stored in the node.
// ============================================================
template <class T>
T& RBTreeNode<T>::value()  
{
    return val;
};

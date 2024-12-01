/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
RBTree.cpp
This file contains the implementations of the red-black tree functions
===========================================================================*/

#include "HashMapTree.hpp"
#include "RBTree.hpp"
#include "customexceptions.hpp"
#include "RBTreeNode.hpp"

using namespace std;

// ============================================================
// Constructor for initializing an empty Red-Black Tree.
// Sets root to NIL and rbt_size to 0.
// ============================================================
template <class T>
RBTree<T>::RBTree(void)
{
    root = NIL;
    rbt_size = 0;
};

// ============================================================
// Copy constructor that creates a deep copy of another 
// Red-Black Tree. Calls deepcopy() to clone the tree nodes.
// Parameter: const RBTree<T> &tree - The tree to be copied.
// Return: None.
// ============================================================
template <class T>
RBTree<T>::RBTree(const RBTree<T> &tree)
{
    root = copy(tree.root, tree);
    rbt_size = tree.rbt_size;
};

// ============================================================
// Destructor that deletes all nodes in the tree by calling 
// deleteTree().
// Parameter: None.
// Return: None.
// ============================================================
template <class T>
RBTree<T>::~RBTree(void)
{
    deallocate(root);
    delete NIL;
};

// ============================================================
// Assignment operator to deep copy one tree into another.
// If the two trees are the same, it does nothing to avoid self-assignment.
// Parameter: const RBTree<T> &tree - The tree to assign.
// Return: RBTree<T> - The current tree after assignment.
// ============================================================
template <class T>
RBTree<T> &RBTree<T>::operator=(const RBTree<T> &tree)
{
    if (this == &tree)
    {
        return *this;
    }
    deallocate(root);
    root = copy(tree.root, tree);
    rbt_size = tree.rbt_size;
    return *this;
};

// ============================================================
// Checks whether the tree is empty (i.e., root is nullptr).
// Parameter: None.
// Return: bool - Returns true if the tree is empty, otherwise 
// false.
// ============================================================
template <class T>
bool RBTree<T>::isEmpty() const
{
    return rbt_size == 0;
}

// ============================================================
// Returns the number of nodes in the tree.
// Parameter: None.
// Return: long - The number of nodes in the tree.
// ============================================================
template <class T>
long RBTree<T>::size() const
{
    return rbt_size;
}

// ============================================================
// Searches for a node with the given value in the tree.
// Parameter: T value - The value to search for.
// Return: RBTreeNode<T>* - Pointer to the node if found,
// otherwise nullptr.
// ============================================================
template <class T> 
RBTreeNode<T> *RBTree<T>::search(const T &value)
{
    RBTreeNode<T> *current = root;
    while (current != nullptr)
    {
        if (current->val == value)
        {
            return current;
        }
        if (current->val < value)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    return nullptr;
}

// ============================================================
// Returns the node with the minimum value in the tree.
// Throws an EmptyTreeException if the tree is empty.
// Parameter: None.
// Return: RBTreeNode<T>* - Pointer to the node with the 
// minimum value.
// ============================================================
template <class T>
RBTreeNode<T> *RBTree<T>::treeMin() const
{
    if (isEmpty())
    {
        throw empty_tree_exception();
    }
    else
    {
        return root->treeMin();
    }
}

// ============================================================
// Returns the node with the maximum value in the tree.
// Throws an EmptyTreeException if the tree is empty.
// Parameter: None.
// Return: RBTreeNode<T>* - Pointer to the node with the 
// maximum value.
// ============================================================
template <class T>
RBTreeNode<T> *RBTree<T>::treeMax() const
{
    if (isEmpty())
    {
        throw empty_tree_exception();
    }
    else
    {
        return root->treeMax();
    }
}

// ============================================================
// Prints the tree nodes in pre-order (root, left, right) traversal.
// Parameter: None.
// Return: None.
// ============================================================
template <class T>
void RBTree<T>::printPreOrderTraversal() const
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        root->printPreOrderTraversal();
    }
}
// ============================================================
// Prints the tree nodes in in-order (root, left, right) traversal.
// Parameter: visit - A function that processes each node's data.
// Return: None.
// ============================================================
template <class T>
void RBTree<T>::printInOrderTraversal(std::function<void(const T&)> visit) const 
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        root->printInOrderTraversal(visit);
    }
}

// ============================================================
// Prints the tree nodes in post-order (left, right, root) 
// traversal.
// Parameter: None.
// Return: None.
// ============================================================
template <class T>
void RBTree<T>::printPostOrderTraversal() const
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        root->printPostOrderTraversal();
    }
}

// ============================================================
// Inserts a new node with the given value into the tree.
// Parameter: T value - The value to be inserted into the tree.
// Return: RBTreeNode<T>* - Pointer to the inserted node.
// ============================================================
template <class T>
RBTreeNode<T> *RBTree<T>::insert(T value)
{
    RBTreeNode<T> *inserted = new RBTreeNode<T>(value);
    RBTreeNode<T> *current = root;
    RBTreeNode<T> *parent = NIL;

    while (current != NIL)
    {
        parent = current;
        if (inserted->val <= current->val)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    inserted->parent = parent;
    if (parent == NIL)
    {
        root = inserted;
    }
    else if (inserted->val <= parent->val)
    {
        parent->left = inserted;
    }
    else
    {
        parent->right = inserted;
    }
    inserted->left = NIL;
    inserted->right = NIL;
    inserted->color = RED;
    insert_fixup(inserted);
    NIL_fixup();
    rbt_size++;
    return inserted;
}

// ============================================================
// Fixes the Red-Black Tree properties after inserting a node.
// Handles color violations and rebalances the tree through
// rotations and color flips.
// Parameter: RBTreeNode<T>* z - The newly inserted node 
//            that may violate Red-Black Tree properties.
// Return: None.
// ============================================================  
template <class T>
void RBTree<T>::insert_fixup(RBTreeNode<T> *z)
{
    while (z->parent && z->parent->color == RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            RBTreeNode<T> *uncle = z->parent->parent->right;
            if (uncle && uncle->color == RED)
            {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    left_rotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(z->parent->parent);
            }
        }
        else
        {
            RBTreeNode<T> *uncle = z->parent->parent->left;
            if (uncle && uncle->color == RED)
            {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    right_rotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

// ============================================================
// Removes a node with the given value from the tree.
// Parameter: T value - The value of the node to be removed.
// Return: None.
// ============================================================
template <class T>
void RBTree<T>::remove(T value)
{
    if (isEmpty())
    {
        throw empty_tree_exception();
    }

    RBTreeNode<T> *deleted = search(value);
    if (deleted == NIL)
    {
        throw value_not_in_tree_exception();
    }

    RBTreeNode<T> *y = deleted;
    RBTreeNode<T> *x;
    Color original_color = y->color;
    if (deleted->left == NIL)
    {
        x = deleted->right;
        transplant(deleted, deleted->right);
    }
    else if (deleted->right == NIL)
    {
        x = deleted->left;
        transplant(deleted, deleted->left);
    }
    else
    {
        y = deleted->right->treeMin();
        original_color = y->color;
        x = y->right;
        if (y != deleted->right)
        {
            transplant(y, y->right);
            y->right = deleted->right;
            y->right->parent = y;
        }
        else
        {
            x->parent = y;
        };
        transplant(deleted, y);
        y->left = deleted->left;
        y->left->parent = y;
        y->color = deleted->color;
    }
    if (original_color == BLACK)
    {
        delete_fixup(x);
    }
    delete deleted;
    NIL_fixup();
    rbt_size--;
}

// ============================================================
// Fixes the Red-Black Tree properties after deleting a node.
// Addresses color violations and rebalances the tree through
// rotations and color flips.
// Parameter: RBTreeNode<T>* x - The node that was deleted and
//            causes Red-Black Tree violations.
// Return: None.
// ============================================================
template <class T>
void RBTree<T>::delete_fixup(RBTreeNode<T> *x)
{
    RBTreeNode<T> *w;
    while (x != root && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            w = x->parent->right;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(x->parent);
                w = x->parent->right;
            };
            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(w);
                    w = x->parent->right;
                };
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                left_rotate(x->parent);
                x = root;
            };
        }
        else
        {
            w = x->parent->left;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(x->parent);
                w = x->parent->left;
            };
            if (w->right->color == BLACK && w->left->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(w);
                    w = x->parent->left;
                };
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                right_rotate(x->parent);
                x = root;
            };
        };
    }
    x->color = BLACK;
};

// ============================================================
// Performs a left rotation on the given node.
// Parameter: RBTreeNode<T>* node - The node to rotate left.
// Return: None.
// ============================================================
template <class T>
void RBTree<T>::left_rotate(RBTreeNode<T> *node)
{
    RBTreeNode<T> *y = node->right;
    node->right = y->left;
    if (y->left != NIL)
    {
        y->left->parent = node;
    };
    y->parent = node->parent;
    if (node->parent == NIL)
    {
        root = y;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = y;
    }
    else
    {
        node->parent->right = y;
    }
    y->left = node;
    node->parent = y;
};

// ============================================================
// Performs a right rotation on the given node.
// Parameter: RBTreeNode<T>* node - The node to rotate right.
// Return: None.
// ============================================================
template <class T>
void RBTree<T>::right_rotate(RBTreeNode<T> *node)
{
    RBTreeNode<T> *y = node->left;
    node->left = y->right;
    if (y->right != NIL)
    {
        y->right->parent = node;
    };
    y->parent = node->parent;
    if (node->parent == NIL)
    {
        root = y;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = y;
    }
    else
    {
        node->parent->right = y;
    }
    y->right = node;
    node->parent = y;
};

// ============================================================
// Replaces one subtree with another, updating parent-child 
// relationships.
// Parameter: RBTreeNode<T>* oldNode - The node to be replaced.
//            RBTreeNode<T>* newNode - The node to insert in 
//                                      place of oldNode.
// Return: None.
// ============================================================
template <class T>
void RBTree<T>::transplant(RBTreeNode<T> *oldNode, RBTreeNode<T> *newNode)
{
    if (oldNode->parent == NIL)
    {
        root = newNode;
    }
    else if (oldNode == oldNode->parent->left)
    {
        oldNode->parent->left = newNode;
    }
    else
    {
        oldNode->parent->right = newNode;
    };
    newNode->parent = oldNode->parent;
};

// ============================================================
// Recursively deallocates memory for the nodes in the subtree 
// rooted at the current node (left, right, root).
// Parameter: node - A pointer to the node to be deallocated.
// Return: None.
// ============================================================
template <class T>
void RBTree<T>::deallocate(RBTreeNode<T> *node)
{
    if (node == NIL)
    {
        return;
    };
    if (node->left != NIL)
    {
        deallocate(node->left);
    };
    if (node->right != NIL)
    {
        deallocate(node->right);
    };
    delete node;
};

// ============================================================
// Recursively creates a copy of the subtree rooted at the given 
// node and returns a pointer to the newly created node.
// Parameter: 
//    - node: A pointer to the node to be copied.
//    - tree: The tree from which the node is being copied.
// Return: A pointer to the newly created node.
// ============================================================
template <class T>
RBTreeNode<T> *RBTree<T>::copy(const RBTreeNode<T> *node, const RBTree<T> &tree)
{
    RBTreeNode<T> *z = new RBTreeNode<T>(node->val);
    z->color = node->color;

    if (node->right != tree.NIL)
    {
        z->right = copy(node->right, tree);
        z->right->parent = z;
    }
    else
    {
        z->right = NIL;
    };
    if (node->left != tree.NIL)
    {
        z->left = copy(node->left, tree);
        z->left->parent = z;
    }
    else
    {
        z->left = NIL;
    };
    return z;
};

// ============================================================
// Fix up the NIL node
// Parameter: None
// ============================================================
template <class T>
void RBTree<T>::NIL_fixup()
{
    NIL->left = nullptr;
    NIL->right = nullptr;
    NIL->parent = nullptr;
    NIL->color = BLACK;
};

// ============================================================
// Check if the tree is balanced
// Parameter: None
// Return: bool - Returns true if the tree is balanced, 
// otherwise false.
// ============================================================
template <class T>
bool RBTree<T>::is_balanced() const
{
    if (root == nullptr)
        return true;

    if (root->color != BLACK)
    {
        std::cerr << "Root is not black." << std::endl;
        return false;
    }

    int blackHeight = -1;
    return is_balanced_helper(root, 0, blackHeight);
}

// ============================================================
// Recursively checks whether the subtree rooted at the given 
// node satisfies the red-black tree properties, 
// Parameter:
//    - node: A pointer to the node being checked.
//    - currentBlackHeight: The current number of black nodes encountered
//      from the root to the current node.
//    - expectedBlackHeight: The expected number of black nodes that
//      should be present from the root to any leaf node.
// Return: bool - True if the subtree is balanced,  
// false otherwise.
// ============================================================
template <class T>
bool RBTree<T>::is_balanced_helper(RBTreeNode<T> *node, int currentBlackHeight, int &expectedBlackHeight) const
{
    if (node == nullptr)
    {
        if (expectedBlackHeight == -1)
        {
            expectedBlackHeight = currentBlackHeight;
        }
        return currentBlackHeight == expectedBlackHeight;
    }

    if (node->color == RED)
    {
        if ((node->left && node->left->color == RED) || (node->right && node->right->color == RED))
        {
            std::cerr << "Consecutive red nodes found at node with data " << node->val << std::endl;
            return false;
        }
    }

    if (node->color == BLACK)
        currentBlackHeight++;

    return is_balanced_helper(node->left, currentBlackHeight, expectedBlackHeight) &&
           is_balanced_helper(node->right, currentBlackHeight, expectedBlackHeight);
}


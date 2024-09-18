#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    while (root != nullptr) {
        removeNode(root, root->value);
    }
}

void BinarySearchTree::insert(int value) {
    insertNode(root, value);
}

void BinarySearchTree::insertNode(Node*& node, int value) {
    if (node == nullptr) {
        node = new Node();
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
    } else if (value < node->value) {
        insertNode(node->left, value);
    } else if (value > node->value) {
        insertNode(node->right, value);
    }
}

bool BinarySearchTree::search(int value) const
{
    return searchNode(root, value);
}

bool BinarySearchTree::searchNode(Node* node, int value) {
    if (node == nullptr) {
        return false;
    } else if (value == node->value) {
        return true;
    } else if (value < node->value) {
        return searchNode(node->left, value);
    } else {
        return searchNode(node->right, value);
    }
}

void BinarySearchTree::remove(int value) {
    removeNode(root, value);
}

void BinarySearchTree::removeNode(Node*& node, int value) {
    if (node == nullptr) {
        return;
    } else if (value < node->value) {
        removeNode(node->left, value);
    } else if (value > node->value) {
        removeNode(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            node->value = temp->value;
            removeNode(node->right, temp->value);
        }
    }
}

void BinarySearchTree::inorderTraversal() {
    inorderTraversalNode(root);
}

void BinarySearchTree::inorderTraversalNode(Node* node) {
    if (node != nullptr) {
        inorderTraversalNode(node->left);
        std::cout << node->value << " ";
        inorderTraversalNode(node->right);
    }
}

void BinarySearchTree::preorderTraversal() {
    preorderTraversalNode(root);
}

void BinarySearchTree::preorderTraversalNode(Node* node) {
    if (node != nullptr) {
        std::cout << node->value << " ";
        preorderTraversalNode(node->left);
        preorderTraversalNode(node->right);
    }
}

void BinarySearchTree::postorderTraversal() {
    postorderTraversalNode(root);
}

void BinarySearchTree::postorderTraversalNode(Node* node) {
    if (node != nullptr) {
        postorderTraversalNode(node->left);
        postorderTraversalNode(node->right);
        std::cout << node->value << " ";
    }
}
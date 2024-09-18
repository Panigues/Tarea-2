#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int value);
    bool search(int value) const;
    void remove(int value);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();

private:
    struct Node {
        int value;
        Node* left;
        Node* right;
    };

    Node* root;

    static void insertNode(Node*& node, int value);
    static bool searchNode(Node* node, int value);
    static void removeNode(Node*& node, int value);
    void inorderTraversalNode(Node* node);
    void preorderTraversalNode(Node* node);
    void postorderTraversalNode(Node* node);
};

#endif  // BINARYSEARCHTREE_H
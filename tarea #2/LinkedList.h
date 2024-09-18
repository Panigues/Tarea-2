#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void insert(int value);
    bool search(int value) const;
    void remove(int value);
    void printList();

private:
    struct Node {
        int value;
        Node* next;
    };

    Node* head;

    static void insertNode(Node*& node, int value);
    static bool searchNode(Node* node, int value);
    static void removeNode(Node*& node, int value);
};

#endif  // LINKEDLIST_H
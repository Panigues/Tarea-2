#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        removeNode(head, head->value);
    }
}

void LinkedList::insert(int value) {
    insertNode(head, value);
}

void LinkedList::insertNode(Node*& node, int value) {
    if (node == nullptr) {
        node = new Node();
        node->value = value;
        node->next = nullptr;
    } else {
        insertNode(node->next, value);
    }
}

bool LinkedList::search(int value) const
{
    return searchNode(head, value);
}

bool LinkedList::searchNode(Node* node, int value) {
    if (node == nullptr) {
        return false;
    } else if (value == node->value) {
        return true;
    } else {
        return searchNode(node->next, value);
    }
}

void LinkedList::remove(int value) {
    removeNode(head, value);
}

void LinkedList::removeNode(Node*& node, int value) {
    if (node == nullptr) {
        return;
    } else if (value == node->value) {
        Node* temp = node;
        node = node->next;
        delete temp;
    } else {
        removeNode(node->next, value);
    }
}

void LinkedList::printList() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
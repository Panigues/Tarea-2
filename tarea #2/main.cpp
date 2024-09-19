#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>


// Estructuras de datos y algoritmos de ordenamiento
class BubbleSort {
public:
    void sort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

class SelectionSort {
public:
    void sort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            std::swap(arr[i], arr[min_idx]);
        }
    }
};

class MergeSort {
public:
    void sort(std::vector<int>& arr) {
        mergesort(arr, 0, arr.size() - 1);
    }

    void mergesort(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergesort(arr, left, mid);
            mergesort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    void merge(std::vector<int>& arr, int left, int mid, int right) {
        std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
        std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
        int i = 0, j = 0, k = left;
        while (i < leftArr.size() && j < rightArr.size()) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
        while (i < leftArr.size()) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        while (j < rightArr.size()) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
};

class Node {
public:
    int data;
    Node* next;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        next = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    bool search(int value) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    void remove(int value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            if (temp->next->data == value) {
                Node* nodeToRemove = temp->next;
                temp->next = temp->next->next;
                delete nodeToRemove;
                size--;
                return;
            }
            temp = temp->next;
        }
    }

    void printList() {
        Node* temp = head;

        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }

        std::cout << std::endl;
    }

    int getSize() {
        return size;
    }
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    bool search(int value) {
        return searchNode(root, value);
    }

    void inorderTraversal() {
        inorderTraversalNode(root);
    }

    void preorderTraversal() {
        preorderTraversalNode(root);
    }

    void postorderTraversal() {
        postorderTraversalNode(root);
    }

private:
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    bool searchNode(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        }

        if (value < node->data) {
            return searchNode(node->left, value);
        } else {
            return searchNode(node->right, value);
        }
    }

    void inorderTraversalNode(Node* node) {
        if (node != nullptr) {
            inorderTraversalNode(node->left);
            std::cout << node->data << " ";
            inorderTraversalNode(node->right);
        }
    }

    void preorderTraversalNode(Node* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preorderTraversalNode(node->left);
            preorderTraversalNode(node->right);
        }
    }

    void postorderTraversalNode(Node* node) {
        if (node != nullptr) {
            postorderTraversalNode(node->left);
            postorderTraversalNode(node->right);
            std::cout << node->data << " ";
        }
    }

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
};

// Medición del tiempo de ejecución
void measureTime(std::vector<int>& arr, BubbleSort& bubbleSort) {
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort.sort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Tempo ejection de BubbleSort: " << duration.count() << " microseconds" << std::endl;
}

void measureTime(std::vector<int>& arr, SelectionSort& selectionSort) {
    auto start = std::chrono::high_resolution_clock::now();
    selectionSort.sort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Tempo ejection SelectionSort: " << duration.count() << " microseconds" << std::endl;
}

void measureTime(std::vector<int>& arr, MergeSort& mergeSort) {
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort.sort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Tempo ejection MergeSort: " << duration.count() << " microseconds" << std::endl;
}

void measureTime1(int input ,LinkedList& LinkedList) {
    auto start = std::chrono::high_resolution_clock::now();
    LinkedList.search(input);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Tempo ejection LinkedList: " << duration.count() << " microseconds" << std::endl;
}

void measureTime2(int input,BinarySearchTree& binarySearchTree) {
    auto start = std::chrono::high_resolution_clock::now();
    binarySearchTree.search(input);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Tempo ejection BinarySearchTree: " << duration.count() << " microseconds" << std::endl;
}

// Generación de gráficas
void generateGraph(std::vector<int>& arr, BubbleSort& bubbleSort) {
    // Implementación de la generación de la gráfica para BubbleSort
}

void generateGraph(std::vector<int>& arr, SelectionSort& selectionSort) {
    // Implementación de la generación de la gráfica para SelectionSort
}

void generateGraph(std::vector<int>& arr, MergeSort& mergeSort) {
    // Implementación de la generación de la gráfica para MergeSort
}

int main() {
    // Creación de las estructuras de datos y algoritmos de ordenamiento
    BubbleSort bubbleSort;
    SelectionSort selectionSort;
    MergeSort mergeSort;
    LinkedList linkedList;
    BinarySearchTree binarySearchTree;




    // Creación de un vector de enteros para realizar las pruebas
    std::vector<int> arr(10000);
    std::vector<int> arr1(1000);
    std::vector<int> arr2(100);
    for (int i = 0; i < 10000; i++) {
        binarySearchTree.insert(i);
        linkedList.insert(i);
    }


    // Medición del tiempo de ejecución para cada algoritmo de ordenamiento
    std::cout << "per case:" << std::endl;
    measureTime(arr, bubbleSort);
    measureTime(arr, selectionSort);
    measureTime(arr, mergeSort);
    measureTime1(9999,linkedList);
    measureTime2(9999,binarySearchTree);

    std::cout << "case Prompted" << std::endl;
    measureTime(arr1, bubbleSort);
    measureTime(arr1, selectionSort);
    measureTime(arr1, mergeSort);
    measureTime1(5000,linkedList);
    measureTime2(5000,binarySearchTree);

    std::cout << "major case:" << std::endl;
    measureTime(arr2, bubbleSort);
    measureTime(arr2, selectionSort);
    measureTime(arr2, mergeSort);
    measureTime1(100,linkedList);
    measureTime2(100,binarySearchTree);

    // Generación de gráficas para cada algoritmo de ordenamiento
    generateGraph(arr, bubbleSort);
    generateGraph(arr, selectionSort);
    generateGraph(arr, mergeSort);

    return 0;
}
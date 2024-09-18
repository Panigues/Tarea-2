#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <gtkmm.h>

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


// Medición del tiempo de ejecución
void measureTime(std::vector<int>& arr, BubbleSort& bubbleSort) {
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort.sort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Tiempo de ejecución de BubbleSort: " << duration.count() << " microsegundos" << std::endl;
}

void measureTime(std::vector<int>& arr, SelectionSort& selectionSort) {
    auto start = std::chrono::high_resolution_clock::now();
    selectionSort.sort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Tiempo de ejecución de SelectionSort: " << duration.count() << " microsegundos" << std::endl;
}

void measureTime(std::vector<int>& arr, MergeSort& mergeSort) {
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort.sort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Tiempo de ejecución de MergeSort: " << duration.count() << " microsegundos" << std::endl;
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
    std::vector<int> arr(1000);

    // Medición del tiempo de ejecución para cada algoritmo de ordenamiento
    measureTime(arr, bubbleSort);
    measureTime(arr, selectionSort);
    measureTime(arr, mergeSort);

    // Generación de gráficas para cada algoritmo de ordenamiento
    generateGraph(arr, bubbleSort);
    generateGraph(arr, selectionSort);
    generateGraph(arr, mergeSort);

    return 0;
}
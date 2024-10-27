#pragma once
#include "Sorting.hpp"


#define ITERATION_NUM 5000
#define EPOCH 1


void test_end(int epoch, std::chrono::milliseconds time) {
    cout << "Epoch " << epoch + 1 << " finished." << endl;
    cout << "The time cost is: " << time.count() << endl;
}

int anyWrong = 0;
void TestSelectionSort(int epoch) {
    cout << "Selection Sort epoch " << epoch + 1 << ": " << endl;
    vector<int> arr;
    
    arr.resize(ITERATION_NUM);
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
    auto start = std::chrono::steady_clock::now();
    SelectionSort(arr);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) anyWrong++;
    }
    test_end(epoch, time);
}



void TestInsertionSort(int epoch) {
    cout << "Insertion Sort epoch " << epoch + 1 << ": " << endl;
    vector<int> arr;
    arr.resize(ITERATION_NUM + 1);
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        arr[i] = rand() % n;
    }
    auto start = std::chrono::steady_clock::now();
    InsertionSort(arr);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    for (int i = 2; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            cout << "i: " << i << " arr[i]: " << arr[i] << endl;
            cout << "i-1: " << i - 1 << " arr[i - 1]: " << arr[i - 1] << endl;
            anyWrong++;
        }
    }
    test_end(epoch, time);
}
void TestInsertionSort2(int epoch) {
    cout << "Insertion Sort2 epoch " << epoch + 1 << ": " << endl;
    vector<int> arr;
    arr.resize(ITERATION_NUM);
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
    auto start = std::chrono::steady_clock::now();
    InsertionSort2(arr);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            cout << "i: " << i << " arr[i]: " << arr[i] << endl;
            cout << "i-1: " << i - 1 << " arr[i - 1]: " << arr[i - 1] << endl;
            anyWrong++;
        }
    }
    test_end(epoch, time);
}

void TestBubbleSort(int epoch) {
    cout << "Bubble Sort epoch " << epoch + 1 << ": " << endl;
    vector<int> arr;
    arr.resize(ITERATION_NUM);
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % n) * 2 + rand() % n - (rand() % n) * 3;
    }
    auto start = std::chrono::steady_clock::now();
    BubbleSort(arr);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            cout << "i: " << i << " arr[i]: " << arr[i] << endl;
            cout << "i-1: " << i - 1 << " arr[i - 1]: " << arr[i - 1] << endl;
            anyWrong++;
        }
    }
    test_end(epoch, time);
}

void TestShellSort(int epoch) {
    cout << "Shell Sort epoch " << epoch + 1 << ": " << endl;
    vector<int> arr;
    arr.resize(ITERATION_NUM);
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
    auto start = std::chrono::steady_clock::now();
    ShellSort(arr);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            cout << "i: " << i << " arr[i]: " << arr[i] << endl;
            cout << "i-1: " << i - 1 << " arr[i - 1]: " << arr[i - 1] << endl;
            anyWrong++;
        }
    }
    test_end(epoch, time);
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
}

void TestHoareQuickSort(int epoch) {
    cout << "Hoare Quick Sort epoch " << epoch + 1 << ": " << endl;
    vector<int> arr;
    arr.resize(ITERATION_NUM);
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] = 10 * (rand() % n) - 5 * n;
    }
    auto start = std::chrono::steady_clock::now();
    HoareQuickSort(arr, 0, n - 1);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            cout << "i: " << i << " arr[i]: " << arr[i] << endl;
            cout << "i-1: " << i - 1 << " arr[i - 1]: " << arr[i - 1] << endl;
            anyWrong++;
        }
    }
    test_end(epoch, time);
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
}
void TestMergeSort(int epoch) {
    cout << "Merge Sort epoch " << epoch + 1 << ": " << endl;
    vector<int> arr;
    arr.resize(ITERATION_NUM);
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
    auto start = std::chrono::steady_clock::now();
    MergeSort(arr, 0, n - 1);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            cout << "i: " << i << " arr[i]: " << arr[i] << endl;
            cout << "i-1: " << i - 1 << " arr[i - 1]: " << arr[i - 1] << endl;
            anyWrong++;
        }
    }
    test_end(epoch, time);
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
}
#define TEST_H_SIZE 10
void TestMinHeap() {
    vector<int> arr(TEST_H_SIZE);
    for (int i = 0; i < TEST_H_SIZE; i++) {
        arr[i] = rand() % TEST_H_SIZE;
        cout << arr[i] << " ";
    }
    cout << endl;
    
    MinHeap(arr);
    
    for (int i = 0; i < TEST_H_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < (TEST_H_SIZE - 1) / 2; i++) {
        int left = 2 * i + 1;
        int right = left + 1;
        if (arr[i] > arr[left]) {
            anyWrong++;
        }
        if (right < TEST_H_SIZE && arr[i] > arr[right]) {
            anyWrong++;
        }
    }
}
void TestMaxHeap() {
    vector<int> arr(TEST_H_SIZE);
    for (int i = 0; i < TEST_H_SIZE; i++) {
        arr[i] = rand() % TEST_H_SIZE;
        cout << arr[i] << " ";
    }
    cout << endl;
    
    MaxHeap(arr, arr.size());
    
    for (int i = 0; i < TEST_H_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < (TEST_H_SIZE - 1) / 2; i++) {
        int left = 2 * i + 1;
        int right = left + 1;
        if (arr[i] < arr[left]) {
            anyWrong++;
        }
        if (right < TEST_H_SIZE && arr[i] < arr[right]) {
            anyWrong++;
        }
    }
}

void TestHeapSort(int epoch) {
    cout << "Heap Sort epoch " << epoch + 1 << ": " << endl;
    vector<int> arr;
    arr.resize(ITERATION_NUM);
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
    auto start = std::chrono::steady_clock::now();
    HeapSort(arr, arr.size());
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            cout << "i: " << i << " arr[i]: " << arr[i] << endl;
            cout << "i-1: " << i - 1 << " arr[i - 1]: " << arr[i - 1] << endl;
            anyWrong++;
        }
    }
    test_end(epoch, time);
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
}

void TestDescendingHeapSort(int epoch) {
    cout << "Descending Heap Sort epoch " << epoch + 1 << ": " << endl;
    vector<int> arr;
    arr.resize(ITERATION_NUM);
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
    auto start = std::chrono::steady_clock::now();
    HeapSort2(arr);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < arr[i]) {
            cout << "i: " << i << " arr[i]: " << arr[i] << endl;
            cout << "i-1: " << i - 1 << " arr[i - 1]: " << arr[i - 1] << endl;
            anyWrong++;
        }
    }
    test_end(epoch, time);
}

void TestBucketSort(int epoch) {
    cout << "Bucket Heap epoch " << epoch + 1 << ": " << endl;
    vector<int> arr;
    arr.resize(ITERATION_NUM);
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
    auto start = std::chrono::steady_clock::now();
    BucketSort(arr);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            cout << "i: " << i << " arr[i]: " << arr[i] << endl;
            cout << "i-1: " << i - 1 << " arr[i - 1]: " << arr[i - 1] << endl;
            anyWrong++;
        }
    }
    test_end(epoch, time);
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
}

void TestCountingSort(int epoch) {
    cout << "Counting Sort epoch " << epoch + 1 << ": " << endl;
    vector<int> arr;
    arr.resize(ITERATION_NUM);
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % int(n * 0.1);
    }
    
    
    auto start = std::chrono::steady_clock::now();
    MaskCountingSort(arr, n, [](int x) -> int {return x;});
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            cout << "i: " << i << " arr[i]: " << arr[i] << endl;
            cout << "i-1: " << i - 1 << " arr[i - 1]: " << arr[i - 1] << endl;
            anyWrong++;
        }
    }
    test_end(epoch, time);
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
}
void TestBucketSort2(int epoch) {
    cout << "Bucket Counting Sort epoch " << epoch + 1 << ": " << endl;
    vector<int> arr;
    arr.resize(ITERATION_NUM);
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] = 2 * (rand() % n) - n;
    }
    auto start = std::chrono::steady_clock::now();
    BucketSort2(arr, n);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            cout << "i: " << i << " arr[i]: " << arr[i] << endl;
            cout << "i-1: " << i - 1 << " arr[i - 1]: " << arr[i - 1] << endl;
            anyWrong++;
        }
    }
    test_end(epoch, time);
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
}

void TestRadixSort(int epoch) {
    cout << "Radix Sort epoch " << epoch + 1 << ": " << endl;
    vector<int> arr;
    arr.resize(ITERATION_NUM);
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] = 16 * (rand() % n) - 8 * n;
    }
    auto start = std::chrono::steady_clock::now();
    RadixSort(arr);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            cout << "i: " << i << " arr[i]: " << arr[i] << endl;
            cout << "i-1: " << i - 1 << " arr[i - 1]: " << arr[i - 1] << endl;
            anyWrong++;
        }
    }
    test_end(epoch, time);
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
}

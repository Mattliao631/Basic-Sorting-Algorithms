//
//  main.cpp
//  Sorts
//
//  Created by MattLiao on 2024/10/25.
//
#include "Testing.hpp"


int main(int argc, const char * argv[]) {
    cout << "Elementary sorting algorithms: " << endl;
    for (int i = 0; i < EPOCH; i++) {
        TestSelectionSort(i);
        TestInsertionSort(i);
        TestInsertionSort2(i);
        TestBubbleSort(i);
        TestShellSort(i);
    }
//    TestMinHeap();
//    TestMaxHeap();
    cout << "High level sorting algorithms: " << endl;
    for (int i = 0; i < EPOCH; i++) {
        TestHoareQuickSort(i);
        TestMergeSort(i);
        TestHeapSort(i);
        TestDescendingHeapSort(i);
    }
    cout << "Linear sorting algorithms: " << endl;
    for (int i = 0; i < EPOCH; i++) {
        TestBucketSort(i);
        TestCountingSort(i);
        TestBucketSort2(i);
        TestRadixSort(i);
    }
    
    if (anyWrong) {
        cout << "There are " << anyWrong << " cases wrong." << endl;
    } else {
        cout << "All case passed." << endl;
    }
    
    
    return 0;
}

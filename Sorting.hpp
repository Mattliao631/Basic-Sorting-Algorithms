#pragma once

#include <iostream>
#include <functional>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>


using namespace std;


void MaskCountingSort(vector<int>&, int, std::function<int(int)>);

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Selection
void SelectionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(&arr[minIndex], &arr[i]);
    }
}
// Insertion
// Assue arr start at arr[1]
void Insertion(vector<int>& arr, int x, int i) {
    int j = i - 1;
    arr[0] = x;
    while (x < arr[j]) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j] = x;
}
void InsertionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 2; i < n; i++) {
        Insertion(arr, arr[i], i);
    }
}

void Insertion2(vector<int>& arr, int i) {
    int x = arr[i];
    int j;
    for (j = i; j > 0; j--) {
        if (x < arr[j - 1]) arr[j] = arr[j - 1];
        else break;
    }
    arr[j] = x;
}
void InsertionSort2(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        Insertion2(arr, i);
    }
}
// Bubble
void BubbleSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = n - 1; i > 0; i--) {
        int flag = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
    
}
// Shell
void ShellSort(vector<int>& arr) {
    int n = arr.size();
    
    unsigned int step = n >> 1;
    while (step > 0) {
        int flag = 0;
        
        int m = n - step;
        for (unsigned int i = 0; i < m; i++) {
            if (arr[i] > arr[i + step]) {
                swap(&arr[i], &arr[i + step]);
                flag = 1;
            }
        }
        
        
        if (flag) continue;
        step = step >> 1;
    }
}
// Quick
int HoarePartition(vector<int>& arr, int p, int q) {
    int x = arr[p];
    int i = p + 1;
    int j = q;
    
    while(i <= j) {
        while (arr[i] < x && i <= j) {
            i++;
        }
        while (arr[j] > x) {
            j--;
        }
        
        if (i <= j)
            swap(&arr[i++], &arr[j--]);
    }
    swap(&arr[p], &arr[j]);
    return j;
}
void HoareQuickSort(vector<int>& arr, int p, int q) {
    if (p < q) {
        int r = HoarePartition(arr, p, q);
        
        HoareQuickSort(arr, p, r - 1);
        HoareQuickSort(arr, r + 1, q);
    }
}

// Merge
void Merge(vector<int>& arr, int m, int l, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> leftArr(n1), rightArr(n2);
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[m + j + 1];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        k++;
        i++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        k++;
        j++;
    }
}

void MergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        Merge(arr, m, l, r);
    }
}

// Heap
void min_heapify(vector<int>& min_heap, int i, int n) {
    int x = min_heap[i];
    int left = i * 2 + 1;
    int right = left + 1;
    int mId = left;
    while (left < n) {
        if (right >= n) right = left;
        if (min_heap[left] > min_heap[right]) mId = right;
        if (x <= min_heap[mId]) break;
        min_heap[i] = min_heap[mId];
        i = mId;
        left = i * 2 + 1;
        right = left + 1;
        mId = left;
    }
    min_heap[i] = x;
}
void MinHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = (n - 1) / 2; i >= 0; i--) {
        min_heapify(arr, i, n);
    }
}

void max_heapify(vector<int>& max_heap, int i, int n) {
    int x = max_heap[i];
    int left = i * 2 + 1;
    int right = left + 1;
    int mId = left;
    while (left < n) {
        if (right >= n) right = left;
        if (max_heap[left] < max_heap[right]) mId = right;
        if (x >= max_heap[mId]) break;
        max_heap[i] = max_heap[mId];
        i = mId;
        left = i * 2 + 1;
        right = left + 1;
        mId = left;
    }
    max_heap[i] = x;
}

void MaxHeap(vector<int>& arr, int n) {
    for (int i = (n - 1) / 2; i >= 0; i--) {
        max_heapify(arr, i, n);
    }
}

void HeapSort(vector<int>& arr, int n) {
    if (n == 0) return;
    
    MaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[i], &arr[0]);
        max_heapify(arr, 0, i);
    }
}

void HeapSort2(vector<int>& arr) {
    int n = arr.size();
    
    MinHeap(arr);
    for(int i = n - 1; i > 0; i--) {
        swap(&arr[i], &arr[0]);
        min_heapify(arr, 0, i);
    }
}

// LSD Radix
void RadixSort(vector<int>& arr) {
    int t = 0;
    for (int i = 0x00000001; i != 0x80000000; i <<= 1) {
        MaskCountingSort(arr, 2, [&i, &t](int x) -> int {return (x & i) >> t;});
        t++;
    }
    MaskCountingSort(arr, 2, [](int x) -> int {return 1 - ((x & 0x80000000) >> 31);});
}

void RadixSort10(vector<int>& arr) {
    
}

// MSD Radix
void BucketSort(vector<int>& arr) {
    vector<int> negative;
    vector<int> positive;
    unsigned int mask = 0x80000000;
    for (int element : arr) {
        if (mask & element) negative.push_back(element);
        else positive.push_back(element);
    }
    HeapSort(negative, negative.size());
    HeapSort(positive, positive.size());
    int i = 0;
    for (int element : negative) {
        arr[i++] = element;
    }
    for (int element : positive) {
        arr[i++] = element;
    }
}

void BucketSort2(vector<int>& arr, int max) {
    vector<int> negative;
    vector<int> positive;
    unsigned int mask = 0x80000000;
    for (int element : arr) {
        if (mask & element) negative.push_back(element);
        else positive.push_back(element);
    }
    
    MaskCountingSort(negative, max + 1, [](int x) -> int {return -x;});
    MaskCountingSort(positive, max, [](int x) -> int {return x;});
    int i = 0;
    for (int j = negative.size() - 1; j >= 0; j--) {
        arr[i++] = negative[j];
    }
    for (int element : positive) {
        arr[i++] = element;
    }
}

// Counting
void MaskCountingSort(vector<int>& arr, int bucketNum, std::function<int(int)> maskFunc) {
    int buckets[bucketNum];
    
    for (int i = 0; i < bucketNum; i++) {
        buckets[i] = 0;
    }
    vector<int> temp;
    for (int element : arr) {
        buckets[maskFunc(element)]++;
        temp.push_back(element);
    }
    int starting = 0;
    int startIndex[bucketNum];
    
    for (int i = 0; i < bucketNum; i++) {
        startIndex[i] = starting;
        starting += buckets[i];
    }
    
    for (int element : temp) {
        int t = maskFunc(element);
        arr[startIndex[t]] = element;
        startIndex[t]++;
    }
}

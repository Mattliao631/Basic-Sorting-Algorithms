### Basic sorting algorithm implementations

Change the epoch and iterations in Testing.hpp to test different size of input array.

The test cases are all generated randomly, only average cases are tested, there is very low chance for some algorithm like quick sort to face its worst case.

The following algorithms are implemented:

Elementary:
- Selection sort
- Insertion sort (with sentinal)
- Insertion sort (Induction variable based)
- Bubble sort
- Shell sort (n / 2^k)
High level:
- Quick sort (Leftest pivot, Hoare partition)
- Merge sort
- Heap sort (Aescending)
- Heap sort (Descending)
Linear time:
- LSD Radix sort (r = 2 with masked counting sort)
- Bucket sort (With heap sort)
- Bucket sort (With counting sort)
- Counting sort (Maskable)

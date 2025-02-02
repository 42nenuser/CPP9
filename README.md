# C++ Module 09 - PmergeMe

## Introduction
i'll focus on the **PmergeMe** exercise, which implements the **Ford-Johnson algorithm**, also known as **merge-insertion sort**. This algorithm aims to minimize the number of comparisons while sorting a collection. Although not always the most practical sorting method, it remains an important reference in computer science, providing insights into efficient comparison-based sorting.

## Understanding the Ford-Johnson Algorithm
The Ford-Johnson merge-insertion sort follows a three-step approach:

1. **Pairing and Initial Sorting**:
   - The input list is split into pairs, and each pair is sorted.
   - If the number of elements is odd, the last element remains unpaired.

2. **Sorting Pairs by Maximum Value**:
   - The highest value from each pair is recursively sorted to form the **main chain**.
   - The remaining elements (smaller values in pairs) become **pend elements**.
   - The main chain is labeled as `{a1, a2, a3, ..., an/2}`, while the pend elements are `{b1, b2, b3, ..., bn/2}`.
   - Each pend element satisfies `bk ≤ ak`.

3. **Insertion of Pend Elements**:
   - The first pend element (`b1`) is inserted before `a1`, forming `{b1, a1, a2, ..., an/2}`.
   - The next pend elements are inserted following a **power of 2 minus 1** pattern.
   - The insertion order follows **Jacobsthal numbers**: `{b1, b3, b2, b5, b4, b11, b10, b9, b8, b7, b6, ...}`.

This structured insertion pattern reduces the number of comparisons required compared to traditional sorting algorithms like quicksort or mergesort.

## Features of PmergeMe Implementation
- **Efficient Sorting**:
  - Utilizes **two STL containers** for sorting.
  - Supports sorting large sequences efficiently (3000+ elements).
- **Time Complexity Optimization**:
  - Reduces the number of comparisons compared to standard merge sort.
- **Performance Analysis**:
  - Displays execution time for sorting using two different STL containers.

## Compilation & Execution
Each exercise includes a **Makefile** with at least the following rules:
```sh
make      # Compile the program
make clean   # Remove object files
make fclean  # Remove all compiled files
make re      # Recompile everything
```
Run PmergeMe as follows:
```sh
./PmergeMe 3 5 9 7 4
```
Example Output:
```
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector: 0.00031 us
Time to process a range of 5 elements with std::deque: 0.00014 us
```

## Learning Outcomes
By completing this exercise, you will:
- Understand **Ford-Johnson sorting** and its theoretical significance.
- Implement efficient sorting using **STL containers**.
- Optimize sorting algorithms for **reduced comparisons**.

## Ressources & References :
Decidedlyso. “Merge-Insertion-Sort”. Github. https://github.com/decidedlyso/merge-insertion-sort

Ford, Lester R., and Selmer M. Johnson. “A Tournament Problem.” The American Mathematical Monthly, vol. 66, no. 5, 1959, pp. 387–389. JSTOR, www.jstor.org/stable/2308750. Accessed 13 June 2020.

Knuth, Donald E. The Art of Computer Programming: Volume 3: Sorting and Searching. Addison-Wesley Professional; 2 edition (May 4, 1998).

Mahmoud, Hosam M. Sorting: A Distribution Theory. John Wiley & Sons. (October 14, 2011).
 Manacher, Glenn K. 1979. “The Ford-Johnson Sorting Algorithm Is Not Optimal”. J. ACM 26, 3 (july 1979), 441–456. DOI:https://doi.org/10.1145/322139.322145

Morwenn. “Ford-Johnson Merge-Insertion Sort”. Code Review Stack Exchange. 10 Jan. 2016, https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort

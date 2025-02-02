# C++ Module 09 - STL

## Introduction
C++ Module 09 focuses on the **Standard Template Library (STL)**, an essential component of modern C++ programming. This module aims to strengthen your understanding of STL containers, algorithms, and their practical applications. Through a series of exercises, you will learn to leverage STL to solve problems efficiently.

## Features
This module includes three main exercises:

### **Exercise 00: Bitcoin Exchange**
- **Goal**: Implement a program to calculate Bitcoin exchange values based on historical data.
- **Input**: A CSV file containing exchange rates and a separate file with queries.
- **Processing**:
  - Parse input files.
  - Retrieve and apply historical exchange rates.
  - Handle errors like invalid dates and out-of-range values.
- **Output**: Converted Bitcoin values based on the given exchange rate.
- **Constraints**: Must use at least one STL container.

### **Exercise 01: Reverse Polish Notation (RPN)**
- **Goal**: Implement a calculator using Reverse Polish Notation (postfix notation).
- **Input**: A mathematical expression in RPN format.
- **Processing**:
  - Use a stack to evaluate expressions.
  - Support basic operations (`+`, `-`, `*`, `/`).
  - Handle errors gracefully.
- **Output**: The evaluated result of the expression.
- **Constraints**: Must use at least one STL container.

### **Exercise 02: PmergeMe**
- **Goal**: Implement a sorting algorithm based on the **Ford-Johnson (Merge-Insertion) algorithm**.
- **Input**: A sequence of positive integers.
- **Processing**:
  - Use two STL containers for sorting.
  - Measure execution time for both containers.
  - Handle large inputs efficiently (at least 3000 elements).
- **Output**:
  - Sorted sequence.
  - Time taken for sorting using each container.
- **Constraints**: Must use at least two different STL containers.

## General Rules
- **Compilation**:
  - Use `c++ -Wall -Wextra -Werror`.
  - Code must compile with `-std=c++98`.
- **STL Usage**:
  - STL is **allowed only in Module 08 and 09**.
  - Each exercise must use different containers.
- **Forbidden Features**:
  - `printf()`, `malloc()`, `free()`.
  - `using namespace std;` and `friend` keyword.
  - Any external libraries (including Boost and C++11+ features).
- **Memory Management**:
  - Prevent memory leaks.
  - Follow **Orthodox Canonical Form** for class design.

## Compilation & Execution
Each exercise must include a **Makefile** with at least the following rules:
```sh
make      # Compile the program
make clean   # Remove object files
make fclean  # Remove all compiled files
make re      # Recompile everything
```
Run each program as follows:
```sh
./btc input.txt        # Exercise 00: Bitcoin Exchange
./RPN "8 9 * 9 - 9 -"  # Exercise 01: Reverse Polish Notation
./PmergeMe 3 5 9 7 4  # Exercise 02: Sorting Algorithm
```

## Learning Outcomes
By completing this module, you will:
- Gain proficiency in **STL containers** (vectors, lists, stacks, maps, etc.).
- Learn efficient data structures and algorithms.
- Implement practical applications of STL in **finance**, **mathematics**, and **sorting**.
- Strengthen your **C++ memory management and class design skills**.

## License
This project is intended for educational purposes and follows the requirements outlined in the C++ Module 09 curriculum.

---


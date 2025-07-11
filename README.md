# Algorithms & Data Structures in C

This repository contains various implementations of common algorithms and data structures written in the C programming language. This serves as a personal learning journey and a collection of solutions to classic computer science problems.

## Table of Contents

- [About](#about)
- [Algorithms Included](#algorithms-included)
- [How to Compile and Run](#how-to-compile-and-run)
- [Contributing](#contributing)
- [License](#license)

## About

This project is a compilation of my efforts to understand and implement fundamental algorithms and data structures from scratch. Each file focuses on a specific concept, providing a clear and concise example.

## Algorithms Included

* BellmenFord (Bellman-Ford Algorithm for shortest paths)
* BinarySearch (Binary Search algorithm)
* FloydWarshall (Floyd-Warshall Algorithm for all-pairs shortest paths)
* GraphColoring (Graph Coloring algorithm, likely using backtracking)
* gcd (Greatest Common Divisor calculation)
* helloworld (A basic "hello world" C program example)
* Hcycles (Further clarification needed, possibly related to Hamiltonian Cycles or a specific graph algorithm)
* KnapSack (Knapsack problem, likely 0/1 Knapsack)
* KnapSackTable (Table-based approach for Knapsack, e.g., dynamic programming)
* MinMaxArray (Finding minimum and maximum elements in an array)
* NQueens (N-Queens problem, likely using backtracking)
* QuickSort (Quick Sort algorithm)
* Subsets (Generating subsets of a set)
* Tapes (Further clarification needed, possibly a dynamic programming problem or related to tape optimization)

## How to Compile and Run

To compile and run any of the C programs:

1.  *Clone the repository:*
    bash
    git clone [https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git](https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git)
    
2.  *Navigate to the repository directory:*
    bash
    cd YOUR_REPOSITORY_NAME
    
3.  *Compile a specific C file using GCC (GNU Compiler Collection):*
    bash
    gcc -o program_name filename.c
    
    *Replace program_name with your desired executable name (e.g., binary_search) and filename.c with the actual C file (e.g., BinarySearch.c).*

4.  *Run the compiled executable:*
    bash
    ./program_name
    

*Example:*
To compile and run BinarySearch.c:
```bash
gcc -o binary_search BinarySearch.c
./binary_search


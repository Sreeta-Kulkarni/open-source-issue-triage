# Algorithm Mapping

## Purpose

Project 50 requires implementations from multiple DAA paradigms.

Algorithms that naturally solve a problem in the Issue Triage and Developer
Assignment Tool will be integrated into the product.

Mandatory algorithms that do not naturally fit the product will be implemented
and demonstrated through the DAA Algorithm Workbench within the same project.

This keeps the product meaningful while ensuring complete syllabus coverage.


## Classification

Each algorithm is classified as:

- **Product** - directly used by the Issue Triage application.
- **Supporting** - has a reasonable project-related demonstration but is not
  essential to the main workflow.
- **Workbench** - implemented primarily to demonstrate the mandatory DAA concept.


# 1. Sorting and Searching

| Algorithm | Classification | Planned Use |
|---|---|---|
| Merge Sort | Product | Sort/prioritize issue records |
| Quick Sort | Product | Alternative issue-sorting strategy |
| Iterative Binary Search | Product | Search ordered issue records by ID |
| Recursive Binary Search | Product | Alternative binary-search implementation |

Merge Sort and Quick Sort will operate using the same ordering rules so their
correctness and performance can be compared.

The two Binary Search implementations will operate on appropriately sorted
records.


# 2. Divide and Conquer

| Algorithm | Classification | Planned Use |
|---|---|---|
| Maximum Subarray | Workbench | Demonstrate divide-and-conquer optimization |
| Fast Powering | Workbench | Demonstrate divide-and-conquer exponentiation |
| Celebrity Problem | Workbench | Demonstrate recursive candidate elimination |
| Classical Matrix Multiplication | Workbench | Baseline matrix multiplication |
| Strassen Matrix Multiplication | Workbench | Compare with classical multiplication |

Classical and Strassen matrix multiplication will use compatible inputs so
their results and performance can be compared.


# 3. Greedy Methods

| Algorithm | Classification | Planned Use |
|---|---|---|
| Activity Selection | Product | Select compatible work activities/tasks |
| Interval Partitioning | Supporting | Allocate overlapping work intervals/resources |
| Huffman Coding | Supporting | Demonstrate compression of repository-related text/data |
| Dijkstra | Supporting | Shortest-path analysis on a weighted project/module graph |
| Prim | Supporting | Minimum spanning tree demonstration |
| Kruskal | Supporting | Alternative minimum spanning tree strategy |

Prim and Kruskal will operate on the same graph where appropriate so their
results and implementation strategies can be compared.


# 4. Dynamic Programming

| Algorithm | Classification | Planned Use |
|---|---|---|
| 0/1 Knapsack | Product | Select valuable issues under limited developer capacity |
| Matrix Chain Multiplication | Workbench | Demonstrate optimal parenthesization using DP |
| Longest Common Subsequence | Supporting | Compare relevant text/event sequences |
| Optimal BST | Supporting | Demonstrate optimized lookup structure for known access frequencies |
| Bellman-Ford | Supporting | Shortest-path analysis with support for negative edge weights |
| Floyd-Warshall | Supporting | All-pairs shortest-path analysis |
| Bounded TSP | Workbench | Demonstrate exact optimization on small instances |

The input size for exact TSP demonstrations will remain bounded so the program
can run safely during evaluation.


# 5. Backtracking

| Algorithm | Classification | Planned Use |
|---|---|---|
| N-Queens | Workbench | Demonstrate constraint solving using backtracking |
| Subset Problem | Workbench | Demonstrate include/exclude backtracking decisions |

These algorithms will not be artificially presented as core issue-triage
features.


# 6. Branch and Bound

| Algorithm | Classification | Planned Use |
|---|---|---|
| FIFO Branch and Bound | Workbench | Solve an exact bounded decision/optimization instance |
| LIFO Branch and Bound | Workbench | Solve the same instance using LIFO node selection |
| Least-Cost Branch and Bound | Workbench | Solve the same instance using least-cost node selection |

All three strategies will solve the same problem instance so their search
behaviour can be compared meaningfully.


# 7. Flow and Matching

| Algorithm | Classification | Planned Use |
|---|---|---|
| Ford-Fulkerson | Product | Model constrained capacity allocation |
| Maximum Bipartite Matching | Product | Match software issues to suitable developers |

Maximum Bipartite Matching is the primary core algorithm of the project.

One side of the bipartite graph represents issues and the other represents
developers. An edge indicates that a developer is eligible to handle an issue
under the chosen compatibility rules.


# 8. Number Theory

| Algorithm | Classification | Planned Use |
|---|---|---|
| Chinese Remainder Theorem | Workbench | Demonstrate the mandatory number-theory algorithm |

CRT will be implemented as a small independent utility within the Algorithm
Workbench.


# 9. String Matching

| Algorithm | Classification | Planned Use |
|---|---|---|
| Naive Pattern Matching | Product | Search issue titles/descriptions |
| Rabin-Karp | Product | Alternative issue-text search |
| Finite Automaton Matching | Product | Alternative issue-text search |
| KMP | Product | Alternative issue-text search |

All four algorithms will be tested using the same text and patterns where
appropriate so their correctness and performance can be compared.


# 10. Algorithm Foundations and Analysis

The project will also include:

- Recurrence analysis where applicable
- Asymptotic time-complexity analysis
- Space-complexity analysis
- Correctness evidence
- Empirical performance measurements
- Complexity-class discussion
- Reduction mapping
- Comparison of alternative strategies
- Recommendations about which algorithms are appropriate under different
  conditions


# Product Algorithm Summary

The algorithms most directly connected to the actual Issue Triage product are:

- Merge Sort
- Quick Sort
- Iterative Binary Search
- Recursive Binary Search
- Activity Selection
- 0/1 Knapsack
- Ford-Fulkerson
- Maximum Bipartite Matching
- Naive Pattern Matching
- Rabin-Karp
- Finite Automaton Matching
- KMP

Other algorithms may support project-related scenarios where the mapping is
reasonable.


# Workbench Principle

An algorithm will not be given an artificial issue-triage use solely to make it
appear integrated.

If an algorithm does not naturally solve part of the repository-triage problem,
it will remain a clearly labelled syllabus demonstration in the Algorithm
Workbench.

Every mandatory algorithm will still be:

1. Implemented by the student
2. Accessible from the project
3. Tested
4. Analysed for correctness and complexity
5. Benchmarked or compared where meaningful
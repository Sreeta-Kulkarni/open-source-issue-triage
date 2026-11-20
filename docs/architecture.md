# Project Architecture

## 1. Architecture Goal

The project uses a modular C architecture so that data handling, algorithms, developer assignment, and dependency analysis remain separate and independently testable.

The overall flow is:

```text
CSV Data
   |
   v
Loading & Validation
   |
   v
Issue / Developer Arrays
   |
   v
Menu-Driven CLI
   |
   +-------------------+-------------------+
   |                   |                   |
   v                   v                   v
Prioritization       Search            Assignment
Merge Sort        Binary Search       Matching
                                       |
                                       v
                              Capacity-Aware
                              Multi-Round MBM

                    +
                    |
                    v
             Dependency Analysis
```

## 2. Main Modules

### Models

Files:

```text
include/models.h
src/models.c
```

Defines the `Issue` and `Developer` structures and provides validation and display functions.

### Input / Output

Files:

```text
include/io.h
src/io.c
```

Loads issue and developer records from CSV files and converts them into C structures.

### Sorting

Files:

```text
include/sorting.h
src/sorting.c
```

Contains the Merge Sort implementation used to prioritize issues.

Issues are ordered by:

1. priority descending,
2. Issue ID ascending when priorities are equal.

### Searching

Files:

```text
include/search.h
src/search.c
```

Contains Iterative Binary Search for retrieving an issue using its ID.

### Developer Assignment

Files:

```text
include/assignment.h
src/assignment.c
include/matching.h
src/matching.c
```

`assignment.c` contains the simple first-suitable baseline assignment strategy.

`matching.c` contains Maximum Bipartite Matching using augmenting paths.

The final product uses a capacity-aware multi-round extension:

```text
Priority-Sorted Issues
        |
        v
Maximum Bipartite Matching
        |
        v
Record Assignments
        |
        v
Reduce Developer Capacity
        |
        v
Remove Assigned Issues
        |
        v
Repeat Until No More Matches
```

This allows developers to receive multiple compatible issues without exceeding their available hours.

### Dependency Analysis

Files:

```text
include/dependency.h
src/dependency.c
```

Handles direct dependency lookup, dependency-chain traversal, invalid references, and protection against possible circular dependencies.

### Main Application

File:

```text
src/main.c
```

Loads the datasets and provides the menu-driven interface.

The final menu is:

```text
1. View Issues
2. View Developers
3. Prioritize Issues
4. Search Issues
5. Developer Assignment
6. Dependency Analysis
0. Exit
```

## 3. Data Flow

A typical operation follows:

```text
CSV File
   |
   v
io.c
   |
   v
Validation
   |
   v
Issue / Developer Structures
   |
   v
Selected Product Operation
   |
   v
Algorithm / Processing Module
   |
   v
CLI Output
```

The original loaded issue array is kept in Issue-ID order.

When an operation needs to reorder issues, such as prioritization or assignment, a copy is created first. This prevents Merge Sort from destroying the ordering required by Binary Search.

## 4. Testing

Algorithm and feature tests are kept separately in:

```text
tests/
```

The test suite covers:

- Merge Sort
- Binary Search
- baseline developer assignment
- Maximum Bipartite Matching
- capacity-aware matching
- dependency analysis
- normal, capacity-shock, and stress scenarios

The Makefile provides build, clean, and test targets.

## 5. Data

The assessed version uses local CSV files.

```text
data/
|-- issues_small.csv
|-- developers_small.csv
|-- scenario_shock_developers.csv
|-- stress_issues.csv
`-- stress_developers.csv
```

No database or internet connection is required.

## 6. Design Principles

The project follows a few simple principles:

- Keep each module responsible for one main task.
- Keep algorithm logic separate from menu logic.
- Implement core algorithms manually.
- Preserve original data when an operation needs a modified copy.
- Keep components independently testable.
- Use algorithms only where they solve a genuine product requirement.
- Prefer a small implementation that can be understood and modified during evaluation.
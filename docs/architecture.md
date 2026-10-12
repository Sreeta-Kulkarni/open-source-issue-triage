# Project Architecture

## 1. Architecture Goal

The project will use a simple modular C architecture so that individual
algorithms can be implemented, tested, demonstrated, and modified
independently.

The application will consist of three main functional areas:

1. Issue Triage and Developer Assignment features
2. DAA Algorithm Workbench
3. Algorithm Benchmarking and Analysis

All three will be accessible through the same menu-driven C application.

## 2. High-Level Architecture

User
 |
 v
Menu-Driven CLI
 |
 +---------------------------+
 |                           |
 v                           v
Issue Triage             DAA Algorithm
Features                 Workbench
 |                           |
 +-------------+-------------+
               |
               v
        Algorithm Library
               |
               v
        Data / Test Inputs
               |
               v
      Results and Benchmarks


## 3. Issue Triage Features

This section contains the actual product functionality.

The planned features include:

- Viewing issues
- Viewing developers
- Prioritizing issues
- Searching issues
- Planning work or releases
- Assigning issues to developers
- Representing issue dependencies

Algorithms will be integrated into these features only when they provide a
meaningful solution to the problem.

For example:

- Merge Sort and Quick Sort can prioritize issues.
- Binary Search can retrieve issues from ordered records.
- Activity Selection can support scheduling decisions.
- 0/1 Knapsack can select work under limited capacity.
- Maximum Bipartite Matching can match issues with suitable developers.
- String-matching algorithms can search issue text.

## 4. DAA Algorithm Workbench

Some mandatory syllabus algorithms do not naturally represent an
issue-triage operation.

These algorithms will still be implemented within the same project and made
available through an Algorithm Workbench.

The workbench will group algorithms according to their DAA paradigm, such as:

- Divide and Conquer
- Greedy Methods
- Dynamic Programming
- Graph Algorithms
- Backtracking
- Branch and Bound
- Flow and Matching
- String Matching
- Number Theory

This avoids forcing algorithms into inappropriate product features while
still allowing every mandatory implementation to be demonstrated and tested.

## 5. Benchmarking and Analysis

The project will contain a benchmarking section for comparing appropriate
algorithmic alternatives.

Depending on the algorithm, comparisons may consider:

- Execution time
- Input size
- Operation count
- Memory requirements
- Solution quality
- Scalability

Correctness will be checked before performance results are compared.

Datasets will include small, medium, large, and relevant adversarial cases.

## 6. Data Flow

A typical product operation will follow this flow:

Input Data
   |
   v
Validation
   |
   v
Issue / Developer Records
   |
   v
Selected Algorithm
   |
   v
Result
   |
   v
CLI Display / Benchmark Output

The assessed version will use simple local data files rather than a database
or live GitHub integration.

## 7. Planned Repository Structure

open-source-issue-triage/
|
|-- include/
|   |-- models.h
|   |-- io.h
|   `-- algorithm header files
|
|-- src/
|   |-- main.c
|   |-- models.c
|   |-- io.c
|   |-- assignment.c
|   |-- dependency.c
|   `-- algorithms/
|
|-- data/
|-- tests/
|-- benchmarks/
|-- results/
|-- docs/
|
|-- Makefile
|-- README.md
`-- .gitignore

Folders and files will be created only when they are required during
development.

## 8. Interface

The assessed application will use a menu-driven command-line interface.

A possible high-level menu is:

1. Issue Triage
2. Search Issues
3. Release Planning
4. Developer Assignment
5. Dependency Analysis
6. DAA Algorithm Workbench
7. Benchmarks and Comparisons
0. Exit

The exact menu may change as the implementation develops.

A graphical interface may be explored after Phase I, but it is not required
for the core C implementation.

## 9. Design Principles

The project will follow these principles:

- Keep the implementation simple and modular.
- Implement assessed algorithms manually.
- Separate algorithm logic from menu/input logic.
- Avoid unnecessary features before internal evaluation.
- Keep algorithms independently testable.
- Use meaningful domain mappings instead of forcing every algorithm into the product.
- Maintain one coherent C project and executable.
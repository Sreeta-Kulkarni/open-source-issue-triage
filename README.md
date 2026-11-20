# Project 50 - Open Source Issue Triage and Developer Assignment Tool

## Overview

This project is developed as part of the Design and Analysis of Algorithms (DAA) Project-Based Learning assessment.

It is a C-based, menu-driven tool for managing software issues. The system loads issue and developer data from CSV files, prioritizes issues, searches issue records, assigns issues to compatible developers, and analyses issue dependencies.

The project follows a need-based approach: algorithms are implemented where they solve a genuine product requirement rather than adding unrelated algorithms only for demonstration.

## Implementation

- Language: C
- Standard: C11
- Compiler: GCC
- Interface: Menu-driven CLI
- Build System: Makefile
- Operation: Fully offline

## Core Features

### 1. Issue and Developer Management

The system loads issue and developer records from CSV files and validates the input before using it.

Each issue contains:

- Issue ID
- Title
- Priority
- Estimated effort
- Required skill
- Dependency ID

Each developer contains:

- Developer ID
- Name
- Skill
- Available hours

### 2. Issue Prioritization

Issues are prioritized using a student-written Merge Sort implementation.

Ordering rule:

1. Higher priority first
2. If priorities are equal, lower Issue ID first

The original issue array is preserved so that prioritization does not interfere with other operations.

### 3. Issue Search

Issue records are retrieved using Iterative Binary Search.

Binary Search operates on the original issue array, which is maintained in ascending Issue-ID order.

### 4. Developer Assignment

The primary developer-assignment strategy uses a capacity-aware multi-round approach built around Maximum Bipartite Matching.

An Issue-Developer compatibility edge exists when:

- the developer's skill matches the issue's required skill, and
- the developer has sufficient remaining available hours for that issue.

Within each round, Maximum Bipartite Matching uses augmenting paths to maximize compatible one-to-one matches.

After each round:

1. successful assignments are recorded,
2. assigned issues are removed from further consideration,
3. the estimated effort of each assigned issue is subtracted from the matched developer's remaining capacity, and
4. Maximum Bipartite Matching is repeated on the remaining issues and updated developer capacities.

This allows a developer to receive multiple issues across matching rounds while ensuring that assigned effort does not exceed the developer's available hours.

A simple first-suitable capacity-aware assignment strategy is retained as a baseline for comparison and analysis.

### 5. Dependency Analysis

The system represents direct issue dependencies using dependency IDs.

It can:

- validate dependency references,
- follow dependency chains,
- detect invalid dependency IDs, and
- safely identify possible circular dependencies.

## Algorithms Used

| Product Requirement | Algorithm / Technique |
|---|---|
| Issue prioritization | Merge Sort |
| Issue retrieval | Iterative Binary Search |
| Baseline developer assignment | First-suitable capacity-aware assignment |
| Primary developer assignment | Maximum Bipartite Matching using augmenting paths |
| Dependency lookup and traversal | Linear lookup and dependency-chain traversal |

All central assessed algorithms are implemented manually in C rather than replaced with library implementations.

## Project Structure

```text
open-source-issue-triage/
|
|-- data/
|   |-- issues_small.csv
|   |-- developers_small.csv
|   |-- scenario_shock_developers.csv
|   |-- stress_issues.csv
|   `-- stress_developers.csv
|
|-- docs/
|   |-- architecture.md
|   |-- algorithm_mapping.md
|   `-- problem_statement.md
|
|-- include/
|   |-- models.h
|   |-- io.h
|   |-- sorting.h
|   |-- search.h
|   |-- assignment.h
|   |-- matching.h
|   `-- dependency.h
|
|-- src/
|   |-- main.c
|   |-- models.c
|   |-- io.c
|   |-- sorting.c
|   |-- search.c
|   |-- assignment.c
|   |-- matching.c
|   `-- dependency.c
|
|-- tests/
|   |-- test_sorting.c
|   |-- test_search.c
|   |-- test_assignment.c
|   |-- test_matching.c
|   |-- test_dependency.c
|   `-- test_scenarios.c
|
|-- Makefile
`-- README.md
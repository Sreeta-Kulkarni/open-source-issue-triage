# Problem Statement

## Problem

Software projects often contain many open issues with different priorities, required skills, estimated effort, and dependencies.

At the same time, developers have different skills and limited working capacity. Manually deciding which issues should be handled first and which developer should handle them can become inefficient as the number of issues increases.

## Objective

Develop an offline C-based **Open Source Issue Triage and Developer Assignment Tool** that can:

- load issue and developer data,
- prioritize issues,
- search for issues,
- assign issues to suitable developers without exceeding their available capacity, and
- analyse issue dependencies.

The project uses DAA algorithms only where they directly support these requirements.

## Inputs

### Issues

Each issue contains:

- Issue ID
- Title
- Priority
- Estimated hours
- Required skill
- Dependency ID

### Developers

Each developer contains:

- Developer ID
- Name
- Primary skill
- Available hours

## Outputs

The system provides:

- prioritized issue lists,
- issue search results,
- issue-to-developer assignments,
- dependency chains and validation results.

## Main Algorithms

- **Merge Sort** for issue prioritization
- **Iterative Binary Search** for searching issues by ID
- **Maximum Bipartite Matching** for Issue-Developer matching
- **Repeated matching rounds** for handling developer capacity across multiple issues
- **Dependency-chain traversal** for dependency analysis

## Constraints

The assessed version:

- is implemented in C11,
- works fully offline,
- uses local CSV datasets,
- uses student-written core algorithms,
- validates important input data,
- respects developer skill and available-hour constraints, and
- remains small enough to understand, test, debug, and modify during evaluation.

## Demonstration Scenarios

### Normal Operation

Run the system using 15 issues and 6 developers under normal capacities.

### Capacity Shock

Reduce developer available hours and observe how the reduced capacity changes Issue-Developer compatibility and assignment possibilities.

### Stress Case

Run the same processing pipeline using a larger dataset containing 75 issues and 25 developers.

## Success Criteria

The project is considered successful when:

1. The application builds reliably using the Makefile.
2. Issue and developer data is loaded and validated correctly.
3. Issues are prioritized and searched correctly.
4. Developer assignments respect skill and capacity constraints.
5. Multiple issues can be assigned to a developer without exceeding available hours.
6. Dependency chains and invalid dependencies are handled safely.
7. Core algorithms are supported by correctness and edge-case tests.
8. The implementation can be explained, debugged, and modified during evaluation.
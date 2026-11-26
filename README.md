# Open Source Issue Triage & Developer Assignment Tool

A C-based issue triage system developed for the Design and Analysis of Algorithms (DAA) PBL.

The tool loads software issues and developer data from CSV files, prioritizes issues, searches issue records, assigns work to suitable developers, and analyses issue dependencies.

## Features

- Load and view issues and developers
- Prioritize issues based on priority
- Search issues by ID
- Assign issues based on skill and available developer hours
- Analyse issue dependency chains
- Handle multiple assignments without exceeding developer capacity
- Test normal, capacity-shock, and larger stress scenarios

## Algorithms Used

| Feature | Algorithm |
|---|---|
| Issue Prioritization | Merge Sort |
| Issue Search | Iterative Binary Search |
| Developer Assignment | Maximum Bipartite Matching |
| Capacity Handling | Repeated matching rounds |
| Dependency Analysis | Dependency-chain traversal |

Developer assignment is the main algorithmic component. Issues and developers form a bipartite graph, where an edge exists when the developer has the required skill and sufficient remaining hours.

Maximum Bipartite Matching uses augmenting paths to improve assignments. Matching is repeated after updating developer capacities so that one developer can handle multiple issues without exceeding their available hours.

## Project Structure

```text
data/       CSV datasets and scenarios
include/    Header files
src/        C implementations
tests/      Algorithm and scenario tests
docs/       Project documentation
Makefile    Build and test configuration
```

## Build and Run

Compile:

```bash
make
```

Run in PowerShell:

```powershell
.\triage.exe
```

Run tests:

```bash
make test
```

Clean generated files:

```bash
make clean
```

## Demonstration Scenarios

The project includes three evaluation scenarios:

- **Normal:** 15 issues and 6 developers
- **Capacity Shock:** reduced developer availability
- **Stress:** 75 issues and 25 developers

## Current Limitations

The assessment version uses one primary skill per developer, one required skill per issue, and one direct dependency per issue.

The capacity-aware assignment method respects developer hours but is still a heuristic built around repeated Maximum Bipartite Matching rounds; it does not guarantee a globally optimal allocation for every possible workload.

## Future Scope

Possible extensions include multiple developer skills, weighted/capacitated assignment, richer dependency graphs, deadlines and scheduling, database persistence, GitHub/GitLab integration, and a graphical or web interface.

## Tech Stack

- C11
- GCC
- GNU Make
- CSV-based offline data
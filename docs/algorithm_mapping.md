# Algorithm Mapping

## Purpose

This document explains why each algorithm used in the final Issue Triage and Developer Assignment Tool was selected.

The project follows a need-based approach: an algorithm is included only when it solves a genuine product requirement.

---

## 1. Merge Sort

**Product Use:** Issue Prioritization

Issues need to be ordered so that high-priority work is considered first.

Merge Sort orders issues using:

1. Priority in descending order
2. Issue ID in ascending order when priorities are equal

### Why Merge Sort?

Merge Sort provides predictable `O(n log n)` time complexity and works well for sorting structured issue records.

The sorting operation is performed on a copy of the issue array so that the original Issue-ID ordering remains available for Binary Search.

---

## 2. Iterative Binary Search

**Product Use:** Search Issue by ID

Issues are stored in ascending Issue-ID order in the original dataset.

Binary Search repeatedly eliminates half of the remaining search space, giving:

```text
Time Complexity: O(log n)
Space Complexity: O(1)
```

### Why Iterative Binary Search?

Searching by Issue ID is a direct product requirement, and the iterative version provides efficient lookup without recursion overhead.

---

## 3. First-Suitable Assignment

**Product Use:** Baseline Developer Assignment

The baseline assignment processes issues one at a time.

An issue is assigned to the first developer who:

- has the required skill, and
- has enough remaining hours.

After assignment, the issue's estimated hours are deducted from that developer's available capacity.

### Why Keep a Baseline?

This provides a simple assignment strategy that is easy to understand and compare with the matching-based approach.

Its limitation is that it makes local decisions and may miss a better overall assignment.

---

## 4. Maximum Bipartite Matching

**Product Use:** Primary Issue-to-Developer Matching

Issues form one side of a bipartite graph and developers form the other.

An edge exists when:

```text
Required skill matches
        AND
Developer has enough remaining capacity
```

Maximum Bipartite Matching uses augmenting paths to rearrange existing matches when doing so allows more compatible assignments.

Example:

```text
Initial:

Issue A -> Developer 1
Issue B -> Unassigned

If Issue A can also use Developer 2:

Issue A -> Developer 2
Issue B -> Developer 1
```

This increases the number of matched issues.

### Capacity-Aware Extension

Standard Maximum Bipartite Matching allows each developer vertex to receive only one issue in one matching round.

The product therefore uses repeated matching rounds:

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
Reduce Remaining Developer Hours
        |
        v
Remove Assigned Issues
        |
        v
Repeat
```

This allows a developer to receive multiple issues while ensuring that their total assigned effort does not exceed their available hours.

The multi-round approach is a practical heuristic and does not guarantee a globally optimal allocation for every possible combination of differently sized issues.

---

## 5. Dependency-Chain Traversal

**Product Use:** Issue Dependency Analysis

Each issue may contain one direct dependency ID.

The dependency module follows these references to display dependency chains.

Example:

```text
Issue 109
    |
    v
Issue 104
    |
    v
Issue 103
```

Linear lookup is used to locate dependency IDs.

The implementation also handles:

- missing dependency IDs,
- issues with no dependency, and
- possible circular dependencies.

---

# Final Product Mapping

| Product Requirement | Algorithm / Technique |
|---|---|
| Prioritize issues | Merge Sort |
| Search issue by ID | Iterative Binary Search |
| Simple assignment baseline | First-suitable assignment |
| Primary developer assignment | Maximum Bipartite Matching |
| Multiple assignments within capacity | Repeated matching rounds |
| Dependency analysis | Dependency-chain traversal |

---

## Scope Decision

Earlier project planning considered several additional DAA algorithms.

After clarification of the project requirements, only algorithms that directly support the final product were retained in the implementation.

Other DAA algorithms and paradigms remain relevant for theoretical understanding and viva preparation, but they are not artificially added to the software when they do not solve a genuine issue-triage or developer-assignment requirement.
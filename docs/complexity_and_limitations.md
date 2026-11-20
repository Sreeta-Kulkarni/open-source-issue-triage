# Complexity and Limitations

## Complexity Summary

| Component | Time Complexity | Extra Space |
|---|---:|---:|
| Merge Sort | O(n log n) | O(n) |
| Iterative Binary Search | O(log n) | O(1) |
| Baseline Assignment | O(I x D) | O(1) excluding output |
| Maximum Bipartite Matching | O(VE) for the standard augmenting-path approach | O(V + E) conceptually |
| Dependency lookup | O(n) per lookup | O(1) |
| Dependency-chain traversal | O(n^2) worst case with repeated linear lookup | O(1) |

Where:

- `n` = number of issues
- `I` = number of issues
- `D` = number of developers
- `V` = total vertices in the bipartite graph
- `E` = compatibility edges

---

## Merge Sort

Merge Sort divides the issue array into smaller halves, recursively sorts them, and merges the sorted halves.

```text
T(n) = 2T(n/2) + O(n)
```

Therefore:

```text
Time: O(n log n)
Extra Space: O(n)
```

The project uses Merge Sort to order issues by descending priority, with Issue ID used as the tie-breaker.

---

## Iterative Binary Search

Binary Search repeatedly reduces the search space by half.

```text
Time: O(log n)
Space: O(1)
```

The algorithm requires the issue array to be sorted by Issue ID.

For this reason, priority sorting is performed on a copy rather than modifying the original issue array.

---

## Baseline Developer Assignment

For every issue, the baseline may inspect every developer.

```text
Time: O(I x D)
```

It is simple but greedy: selecting the first suitable developer may prevent a better assignment later.

---

## Maximum Bipartite Matching

Issues and developers form the two vertex sets of a bipartite graph.

An edge exists when the developer:

- has the required skill, and
- has enough remaining hours for the issue.

The implementation searches for augmenting paths so that existing matches can be rearranged when this increases the number of matches.

The standard augmenting-path implementation has approximately:

```text
O(VE)
```

time complexity.

The final product repeats matching rounds after updating developer capacities. Therefore, the complete capacity-aware assignment procedure can perform several matching rounds and is more expensive than one standard matching operation.

---

## Dependency Analysis

Finding an issue by dependency ID currently uses linear search:

```text
O(n)
```

A dependency chain may contain up to `n` issues, and each step can perform another linear lookup.

Therefore the current worst case is:

```text
O(n^2)
```

This is acceptable for the small assessment dataset but could later be improved using an indexed lookup or graph representation.

---

# Current Limitations

## 1. Developer Skills

Each developer currently has one primary skill.

A future version could support multiple skills and proficiency levels.

## 2. Issue Skills

Each issue currently requires one skill.

Real software tasks may require several skills or collaboration between multiple developers.

## 3. Capacity-Aware Matching

The product repeats Maximum Bipartite Matching after reducing developer capacities.

This ensures that assigned work does not exceed available hours, but the approach is still a heuristic.

It does not guarantee the globally optimal allocation for every combination of issue sizes, priorities, and developer capacities.

## 4. Dependencies

Each issue stores at most one direct dependency.

A larger system should represent dependencies as a full graph so that one issue can depend on several other issues.

## 5. Priority

Priority is represented using a numeric value.

The current system does not consider deadlines, business value, severity, or changing priorities.

## 6. Scheduling

Estimated hours represent required effort, but the assessment version does not implement calendars, deadlines, flexible time windows, or fixed-time work sessions.

## 7. Persistence

Data is stored in CSV files.

There is no database or live GitHub/GitLab connection in the assessed version.

---

# Scalability Improvements

Possible future improvements include:

- multiple developer skills and proficiency levels,
- weighted or globally optimized capacitated matching,
- richer issue-priority scoring,
- multiple dependencies using adjacency lists,
- faster indexed dependency lookup,
- deadlines and time-window scheduling,
- developer calendars,
- database persistence,
- GitHub/GitLab API integration,
- graphical or web interfaces.

The current implementation intentionally prioritizes correctness, explainability, testing, and offline operation over production-scale complexity.
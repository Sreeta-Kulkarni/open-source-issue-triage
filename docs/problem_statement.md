# Problem Statement

## Problem

Software projects may contain many open issues such as bugs, feature requests,
documentation tasks, and performance problems.

These issues can have different priorities, estimated effort, required skills,
and dependencies. Developers also have different skills and limited working
capacity.

The problem is to organize these issues efficiently, determine suitable work
priorities, plan work under available constraints, and assign issues to
appropriate developers.

## Objective

Develop a C-based Open Source Issue Triage and Developer Assignment Tool that
uses Design and Analysis of Algorithms concepts to organize, search, prioritize,
plan, and assign software issues.

Algorithms that naturally fit the problem will be integrated into the product.
Other mandatory DAA algorithms will be implemented and demonstrated through an
Algorithm Workbench within the same project.

## Inputs

### Issue Records

Each issue may contain:

- Issue ID
- Title
- Priority
- Estimated effort
- Required skill
- Dependency information

### Developer Records

Each developer may contain:

- Developer ID
- Name
- Skill
- Available capacity

Only fields required by the assessed functionality will be added.

## Outputs

The system will produce outputs such as:

- Prioritized issue lists
- Issue search results
- Work/release plans
- Issue-to-developer assignments
- Dependency information
- Algorithm results
- Algorithm comparison and benchmark results

## Constraints

The assessed version of the project will:

- Be implemented in C
- Use student-written implementations of the assessed algorithms
- Run offline
- Use simple local datasets
- Validate important inputs
- Remain understandable and modifiable during the offline hackathons
- Avoid unnecessary features that do not contribute to the PBL requirements

## Algorithm Strategy

Algorithms that meaningfully solve parts of the issue-triage problem will be
integrated directly into the product.

Mandatory algorithms that do not naturally correspond to an issue-triage
feature will be implemented within the DAA Algorithm Workbench in the same
application.

## Demonstration Scenarios

### 1. Normal Operation

Run the system with a normal set of issues and available developers and
demonstrate prioritization, searching, planning, and assignment.

### 2. Capacity or Constraint Shock

Reduce available developer capacity or introduce another relevant constraint
and demonstrate how the resulting plan or assignment changes.

### 3. Large-Data Stress Case

Run suitable algorithms on a significantly larger dataset and measure their
behavior as the input size increases.

## Success Criteria

The project will be considered successful when:

1. The C application builds and runs reliably offline.
2. Core issue-triage operations work correctly.
3. Every mandatory DAA algorithm required by Project 50 is implemented.
4. Relevant algorithms are meaningfully integrated into the product.
5. Other mandatory algorithms can be demonstrated through the Algorithm Workbench.
6. Algorithms are tested for correctness and important edge cases.
7. Relevant alternative algorithms can be compared theoretically and empirically.
8. The required demonstration scenarios can be reproduced.
9. The implementation and analysis can be explained and modified during the offline evaluation.
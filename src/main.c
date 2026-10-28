#include <stdio.h>
#include "models.h"
#include "../include/io.h"
#include "../include/sorting.h"
#include "../include/search.h"
#include "../include/assignment.h"
#include "../include/dependency.h"

int main(void) {
    Issue issues[MAX_ISSUES];
    Developer developers[MAX_DEVELOPERS];

    int issue_count = load_issues(
        "data/issues_small.csv",
        issues,
        MAX_ISSUES
    );

    int developer_count = load_developers(
        "data/developers_small.csv",
        developers,
        MAX_DEVELOPERS
    );

    if (issue_count < 0) {
        printf("Error: Could not load issue data.\n");
        return 1;
    }

    if (developer_count < 0) {
        printf("Error: Could not load developer data.\n");
        return 1;
    }

    int choice;

    do {
        printf("\n============================================\n");
        printf(" OPEN SOURCE ISSUE TRIAGE & ASSIGNMENT TOOL\n");
        printf("============================================\n");

        printf("Loaded %d issues.\n", issue_count);
        printf("Loaded %d developers.\n\n", developer_count);

        printf("1. View Issues\n");
        printf("2. View Developers\n");
        printf("3. Prioritize Issues\n");
        printf("4. Search Issues\n");
        printf("5. Release Planning\n");
        printf("6. Developer Assignment\n");
        printf("7. Dependency Analysis\n");
        printf("8. DAA Algorithm Workbench\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        if (choice == 1) {
            printf("\nIssues:\n");

            for (int i = 0; i < issue_count; i++) {
                printf("\n");
                print_issue(&issues[i]);
            }
        }

        else if (choice == 2) {
            printf("\nDevelopers:\n");

            for (int i = 0; i < developer_count; i++) {
                printf("\n");
                print_developer(&developers[i]);
            }
        }

        else if (choice == 3) {
            Issue prioritized_issues[MAX_ISSUES];

            for (int i = 0; i < issue_count; i++) {
                prioritized_issues[i] = issues[i];
            }

            merge_sort_issues(
                prioritized_issues,
                issue_count
            );

            printf("\nIssues prioritized by priority:\n");

            for (int i = 0; i < issue_count; i++) {
                printf(
                    "ID: %d | Priority: %d | %s\n",
                    prioritized_issues[i].id,
                    prioritized_issues[i].priority,
                    prioritized_issues[i].title
                );
            }
        }

        else if (choice == 4) {
            int target_id;

            printf("\nEnter Issue ID to search: ");

            if (scanf("%d", &target_id) != 1) {
                printf("Invalid input.\n");
                return 1;
            }

            int index = binary_search_iterative(
                issues,
                issue_count,
                target_id
            );

            if (index == -1) {
                printf("\nIssue not found.\n");
            }

            else {
                printf("\nIssue Found:\n");
                print_issue(&issues[index]);
            }
        }

        else if (choice == 5) {
            printf(
                "\nRelease Planning is not implemented yet.\n"
            );
        }

        else if (choice == 6) {
            Issue prioritized_issues[MAX_ISSUES];
            Developer available_developers[MAX_DEVELOPERS];
            Assignment assignments[MAX_ISSUES];

            for (int i = 0; i < issue_count; i++) {
                prioritized_issues[i] = issues[i];
            }

            for (int i = 0; i < developer_count; i++) {
                available_developers[i] = developers[i];
            }

            merge_sort_issues(
                prioritized_issues,
                issue_count
            );

            int assignment_count = assign_issues(
                prioritized_issues,
                issue_count,
                available_developers,
                developer_count,
                assignments
            );

            printf("\nDeveloper Assignments:\n");

            for (int i = 0; i < assignment_count; i++) {
                printf(
                    "Issue %d -> Developer %d\n",
                    assignments[i].issue_id,
                    assignments[i].developer_id
                );
            }

            printf(
                "\nTotal assigned: %d/%d\n",
                assignment_count,
                issue_count
            );
        }

        else if (choice == 7) {
            int issue_id;

            if (!validate_dependencies(
                    issues,
                    issue_count
                )) {
                printf(
                    "\nWarning: Invalid dependency data detected.\n"
                );
            }

            printf("\nEnter Issue ID to analyse: ");

            if (scanf("%d", &issue_id) != 1) {
                printf("Invalid input.\n");
                return 1;
            }

            print_dependency_chain(
                issues,
                issue_count,
                issue_id
            );
        }

        else if (choice == 8) {
            printf(
                "\nDAA Algorithm Workbench will be added only "
                "for concepts required for demonstration.\n"
            );
        }

        else if (choice == 0) {
            printf("\nExiting program.\n");
        }

        else {
            printf("\nInvalid menu choice.\n");
        }

    } while (choice != 0);

    return 0;
}
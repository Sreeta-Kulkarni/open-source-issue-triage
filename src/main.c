#include <stdio.h>
#include "models.h"
#include "../include/io.h"

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

    printf("============================================\n");
    printf(" OPEN SOURCE ISSUE TRIAGE & ASSIGNMENT TOOL\n");
    printf("============================================\n");

    printf("Loaded %d issues successfully.\n", issue_count);
    printf("Loaded %d developers successfully.\n\n", developer_count);

    printf("1. View Issues\n");
    printf("2. View Developers\n");
    printf("3. Prioritize Issues\n");
    printf("4. Search Issues\n");
    printf("5. Release Planning\n");
    printf("6. Developer Assignment\n");
    printf("7. Dependency Analysis\n");
    printf("8. DAA Algorithm Workbench\n");
    printf("9. Benchmarks & Comparisons\n");
    printf("0. Exit\n");

    return 0;
}
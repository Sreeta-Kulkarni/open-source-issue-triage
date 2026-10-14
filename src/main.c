#include <stdio.h>
#include "models.h"

int main(void) {
    Issue sample_issue = {
        101,
        "Login page crashes",
        10,
        4,
        "Backend",
        -1
    };

    Developer sample_developer = {
        1,
        "Aman",
        "Backend",
        8
    };

    if (!is_valid_issue(&sample_issue)) {
        printf("Invalid issue data.\n");
        return 1;
    }

    if (!is_valid_developer(&sample_developer)) {
        printf("Invalid developer data.\n");
        return 1;
    }

    printf("=== Sample Issue ===\n");
    print_issue(&sample_issue);

    printf("\n=== Sample Developer ===\n");
    print_developer(&sample_developer);

    printf("\n============================================\n");
    printf(" OPEN SOURCE ISSUE TRIAGE & ASSIGNMENT TOOL\n");
    printf("============================================\n");

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
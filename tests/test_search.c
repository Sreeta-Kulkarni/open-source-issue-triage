#include <stdio.h>
#include "../include/search.h"

static void check_result(
    const char *test_name,
    int actual,
    int expected
) {
    if (actual == expected) {
        printf("[PASS] %s\n", test_name);
    } else {
        printf(
            "[FAIL] %s | Expected: %d | Got: %d\n",
            test_name,
            expected,
            actual
        );
    }
}

int main(void) {
    Issue issues[] = {
        {101, "Issue A", 10, 4, "Backend", -1},
        {102, "Issue B", 4, 2, "Frontend", -1},
        {103, "Issue C", 9, 6, "Database", -1},
        {104, "Issue D", 8, 5, "Backend", 103},
        {105, "Issue E", 3, 8, "Frontend", -1},
        {106, "Issue F", 7, 4, "Backend", 103},
        {107, "Issue G", 5, 3, "Frontend", 102}
    };

    int count = 7;

    printf("Binary Search Tests:\n");

    check_result(
        "First element",
        binary_search_iterative(issues, count, 101),
        0
    );

    check_result(
        "Middle element",
        binary_search_iterative(issues, count, 104),
        3
    );

    check_result(
        "Last element",
        binary_search_iterative(issues, count, 107),
        6
    );

    check_result(
        "Missing element",
        binary_search_iterative(issues, count, 999),
        -1
    );

    Issue single[] = {
        {200, "Only issue", 5, 2, "Backend", -1}
    };

    check_result(
        "Single element found",
        binary_search_iterative(single, 1, 200),
        0
    );

    check_result(
        "Single element missing",
        binary_search_iterative(single, 1, 201),
        -1
    );

    check_result(
        "Empty array",
        binary_search_iterative(NULL, 0, 101),
        -1
    );

    return 0;
}
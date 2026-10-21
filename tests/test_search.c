#include <stdio.h>
#include "../include/search.h"

static void test_both_searches(
    const char *test_name,
    const Issue issues[],
    int count,
    int target_id,
    int expected
) {
    int iterative_result =
        binary_search_iterative(issues, count, target_id);

    int recursive_result =
        binary_search_recursive(issues, count, target_id);

    if (iterative_result == expected &&
        recursive_result == expected &&
        iterative_result == recursive_result) {

        printf("[PASS] %s\n", test_name);

    } else {
        printf("[FAIL] %s | Expected: %d | Iterative: %d | Recursive: %d\n",
               test_name,
               expected,
               iterative_result,
               recursive_result);
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

    test_both_searches("First element", issues, count, 101, 0);
    test_both_searches("Middle element", issues, count, 104, 3);
    test_both_searches("Last element", issues, count, 107, 6);
    test_both_searches("Missing element", issues, count, 999, -1);

    Issue single_issue[] = {
        {200, "Only issue", 5, 2, "Backend", -1}
    };

    test_both_searches(
        "Single element found",
        single_issue,
        1,
        200,
        0
    );

    test_both_searches(
        "Single element missing",
        single_issue,
        1,
        201,
        -1
    );

    test_both_searches(
        "Empty array",
        NULL,
        0,
        101,
        -1
    );

    return 0;
}
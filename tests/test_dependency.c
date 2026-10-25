#include <stdio.h>
#include "../include/dependency.h"

static void check_result(const char *test_name, int actual, int expected) {
    if (actual == expected) {
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s | Expected: %d | Got: %d\n",
               test_name, expected, actual);
    }
}

int main(void) {

    /* Normal dependency chain: 109 -> 104 -> 103 */
    Issue issues[] = {
        {101, "Login crash", 10, 4, "Backend", -1},
        {103, "Database timeout", 9, 6, "Database", -1},
        {104, "Authentication API error", 8, 5, "Backend", 103},
        {109, "Password reset failure", 9, 4, "Backend", 104}
    };

    int count = 4;

    printf("Dependency Tests:\n");

    check_result(
        "Find existing issue",
        find_issue_index_by_id(issues, count, 104),
        2
    );

    check_result(
        "Find missing issue",
        find_issue_index_by_id(issues, count, 999),
        -1
    );

    check_result(
        "Issue has dependency",
        has_dependency(&issues[2]),
        1
    );

    check_result(
        "Issue has no dependency",
        has_dependency(&issues[1]),
        0
    );

    check_result(
        "Valid dependencies",
        validate_dependencies(issues, count),
        1
    );

    printf("\nValid Chain Test:");
    print_dependency_chain(issues, count, 109);


    /* Invalid dependency */
    Issue invalid_issues[] = {
        {201, "Issue A", 5, 2, "Backend", -1},
        {202, "Issue B", 6, 3, "Backend", 999}
    };

    check_result(
        "Invalid dependency detected",
        validate_dependencies(invalid_issues, 2),
        0
    );

    printf("\nInvalid Dependency Chain Test:");
    print_dependency_chain(invalid_issues, 2, 202);

    
    printf("\nMissing Issue Test:");
    print_dependency_chain(issues, count, 999);


    /* Circular dependency */
    Issue circular_issues[] = {
        {301, "Issue X", 5, 2, "Backend", 302},
        {302, "Issue Y", 6, 3, "Backend", 303},
        {303, "Issue Z", 7, 4, "Backend", 301}
    };

    printf("\nCircular Dependency Test:");
    print_dependency_chain(circular_issues, 3, 301);

    return 0;
}

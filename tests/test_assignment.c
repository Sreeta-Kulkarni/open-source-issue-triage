#include <stdio.h>
#include "../include/assignment.h"

static void check_count(const char *test_name, int actual, int expected) {
    if (actual == expected) {
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s | Expected: %d | Got: %d\n",
               test_name, expected, actual);
    }
}

int main(void) {

    /* Test 1: Normal assignment */
    Issue issues[] = {
        {101, "Login crash", 10, 4, "Backend", -1},
        {102, "Navbar issue", 4, 2, "Frontend", -1},
        {103, "Database timeout", 9, 6, "Database", -1},
        {104, "API error", 8, 5, "Backend", -1}
    };

    Developer developers[] = {
        {1, "Aman", "Backend", 8},
        {2, "Riya", "Frontend", 6},
        {3, "Rahul", "Database", 10},
        {4, "Neha", "Backend", 5}
    };

    Assignment assignments[4];

    int assignment_count =
        assign_issues(issues, 4, developers, 4, assignments);

    printf("Assignments:\n");

    for (int i = 0; i < assignment_count; i++) {
        printf("Issue %d -> Developer %d\n",
               assignments[i].issue_id,
               assignments[i].developer_id);
    }

    printf("\nRemaining Capacity:\n");

    for (int i = 0; i < 4; i++) {
        printf("%s: %d hours\n",
               developers[i].name,
               developers[i].available_hours);
    }

    printf("\nAssignment Tests:\n");

    check_count(
        "Normal assignment count",
        assignment_count,
        4
    );


    /* Test 2: Insufficient capacity */
    Issue large_issue[] = {
        {201, "Large backend task", 8, 10, "Backend", -1}
    };

    Developer low_capacity[] = {
        {1, "Aman", "Backend", 5}
    };

    Assignment capacity_assignment[1];

    int capacity_count =
        assign_issues(
            large_issue,
            1,
            low_capacity,
            1,
            capacity_assignment
        );

    check_count(
        "Insufficient capacity",
        capacity_count,
        0
    );


    /* Test 3: No matching skill */
    Issue security_issue[] = {
        {202, "Security audit", 9, 3, "Security", -1}
    };

    Developer no_security[] = {
        {1, "Aman", "Backend", 8},
        {2, "Riya", "Frontend", 8}
    };

    Assignment skill_assignment[1];

    int skill_count =
        assign_issues(
            security_issue,
            1,
            no_security,
            2,
            skill_assignment
        );

    check_count(
        "No matching skill",
        skill_count,
        0
    );


    /* Test 4: Empty input */
    int empty_count =
        assign_issues(NULL, 0, NULL, 0, NULL);

    check_count(
        "Empty input",
        empty_count,
        0
    );


    /* Test 5: Demonstrate baseline limitation */
    Issue limitation_issues[] = {
        {301, "Small backend task", 5, 3, "Backend", -1},
        {302, "Large backend task", 10, 6, "Backend", -1}
    };

    Developer limitation_developers[] = {
        {1, "Aman", "Backend", 6},
        {2, "Neha", "Backend", 3}
    };

    Assignment limitation_assignments[2];

    int limitation_count =
        assign_issues(
            limitation_issues,
            2,
            limitation_developers,
            2,
            limitation_assignments
        );

    check_count(
        "Baseline limitation case",
        limitation_count,
        1
    );

    return 0;
}
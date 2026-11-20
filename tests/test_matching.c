#include <stdio.h>
#include "../include/matching.h"

static void check_count(const char *test_name, int actual, int expected) {
    if (actual == expected) {
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s | Expected: %d | Got: %d\n",
               test_name, expected, actual);
    }
}

int main(void) {

    Issue normal_issues[] = {
        {101, "Backend issue", 10, 4, "Backend", -1},
        {102, "Frontend issue", 8, 3, "Frontend", -1},
        {103, "Database issue", 7, 5, "Database", -1}
    };

    Developer normal_developers[] = {
        {1, "Aman", "Backend", 8},
        {2, "Riya", "Frontend", 6},
        {3, "Rahul", "Database", 10}
    };

    Assignment normal_assignments[3];

    int normal_count = maximum_bipartite_matching(
        normal_issues,
        3,
        normal_developers,
        3,
        normal_assignments
    );

    printf("Maximum Bipartite Matching Tests:\n");

    check_count(
        "Normal matching",
        normal_count,
        3
    );

    Issue large_issue[] = {
        {201, "Large backend issue", 9, 10, "Backend", -1}
    };

    Developer low_capacity[] = {
        {1, "Aman", "Backend", 5}
    };

    Assignment capacity_assignment[1];

    int capacity_count = maximum_bipartite_matching(
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

    Issue security_issue[] = {
        {202, "Security issue", 9, 3, "Security", -1}
    };

    Developer no_security[] = {
        {1, "Aman", "Backend", 8},
        {2, "Riya", "Frontend", 8}
    };

    Assignment skill_assignment[1];

    int skill_count = maximum_bipartite_matching(
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

    Issue augmenting_issues[] = {
        {301, "Flexible backend task", 8, 3, "Backend", -1},
        {302, "Large backend task", 10, 6, "Backend", -1}
    };

    Developer augmenting_developers[] = {
        {1, "Aman", "Backend", 6},
        {2, "Neha", "Backend", 3}
    };

    Assignment augmenting_assignments[2];

    int augmenting_count = maximum_bipartite_matching(
        augmenting_issues,
        2,
        augmenting_developers,
        2,
        augmenting_assignments
    );

    check_count(
        "Augmenting path improves matching",
        augmenting_count,
        2
    );

    printf("\nAugmenting Path Result:\n");

    for (int i = 0; i < augmenting_count; i++) {
        printf("Issue %d -> Developer %d\n",
               augmenting_assignments[i].issue_id,
               augmenting_assignments[i].developer_id);
    }

    int empty_count = maximum_bipartite_matching(
        NULL,
        0,
        NULL,
        0,
        NULL
    );

    check_count(
        "Empty input",
        empty_count,
        0
    );
    
    
    Issue multi_issues[] = {
        {401, "Backend task A", 10, 4, "Backend", -1},
        {402, "Backend task B", 9, 3, "Backend", -1}
    };

    Developer multi_developers[] = {
        {1, "Aman", "Backend", 8}
    };

    Assignment multi_assignments[2];

    int multi_count = capacity_aware_matching(
        multi_issues,
        2,
        multi_developers,
        1,
        multi_assignments
    );

    check_count(
        "Multiple issues within developer capacity",
        multi_count,
        2
    );

    Issue capacity_issues[] = {
        {501, "Backend task A", 10, 4, "Backend", -1},
        {502, "Backend task B", 9, 3, "Backend", -1},
        {503, "Backend task C", 8, 2, "Backend", -1}
    };

    Developer capacity_developers[] = {
        {1, "Aman", "Backend", 8}
    };

    Assignment capacity_assignments[3];

    int capacity_aware_count = capacity_aware_matching(
        capacity_issues,
        3,
        capacity_developers,
        1,
        capacity_assignments
    );

    check_count(
        "Developer capacity is not exceeded",
        capacity_aware_count,
        2
    );
    return 0;
}
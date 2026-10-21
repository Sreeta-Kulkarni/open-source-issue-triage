#include <stdio.h>
#include "../include/sorting.h"

static void print_issues(Issue issues[], int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Priority: %d | %s\n",
               issues[i].id,
               issues[i].priority,
               issues[i].title);
    }
}

static int is_sorted_correctly(Issue issues[], int count) {
    for (int i = 0; i < count - 1; i++) {

        if (issues[i].priority < issues[i + 1].priority) {
            return 0;
        }

        if (issues[i].priority == issues[i + 1].priority &&
            issues[i].id > issues[i + 1].id) {
            return 0;
        }
    }

    return 1;
}

static int same_order(Issue a[], Issue b[], int count) {
    for (int i = 0; i < count; i++) {
        if (a[i].id != b[i].id) {
            return 0;
        }
    }

    return 1;
}

static void run_test(const char *test_name, Issue input[], int count) {
    Issue merge_issues[20];
    Issue quick_issues[20];

    for (int i = 0; i < count; i++) {
        merge_issues[i] = input[i];
        quick_issues[i] = input[i];
    }

    merge_sort_issues(merge_issues, count);
    quick_sort_issues(quick_issues, count);

    int merge_pass = is_sorted_correctly(merge_issues, count);
    int quick_pass = is_sorted_correctly(quick_issues, count);
    int same_pass = same_order(merge_issues, quick_issues, count);

    if (merge_pass && quick_pass && same_pass) {
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s\n", test_name);
    }
}

int main(void) {
    Issue merge_issues[] = {
        {105, "Dark mode", 3, 8, "Frontend", -1},
        {103, "Database timeout", 9, 6, "Database", -1},
        {113, "Database backup failure", 10, 6, "Database", -1},
        {102, "Navbar issue", 4, 2, "Frontend", -1},
        {101, "Login crash", 10, 4, "Backend", -1}
    };

    Issue quick_issues[] = {
        {105, "Dark mode", 3, 8, "Frontend", -1},
        {103, "Database timeout", 9, 6, "Database", -1},
        {113, "Database backup failure", 10, 6, "Database", -1},
        {102, "Navbar issue", 4, 2, "Frontend", -1},
        {101, "Login crash", 10, 4, "Backend", -1}
    };

    int count = 5;

    merge_sort_issues(merge_issues, count);
    quick_sort_issues(quick_issues, count);

    printf("Merge Sort Result:\n");
    print_issues(merge_issues, count);

    printf("\nQuick Sort Result:\n");
    print_issues(quick_issues, count);

    printf("\nTest Results:\n");

    if (is_sorted_correctly(merge_issues, count)) {
        printf("[PASS] Merge Sort\n");
    } else {
        printf("[FAIL] Merge Sort\n");
    }

    if (is_sorted_correctly(quick_issues, count)) {
        printf("[PASS] Quick Sort\n");
    } else {
        printf("[FAIL] Quick Sort\n");
    }

    if (same_order(merge_issues, quick_issues, count)) {
        printf("[PASS] Both algorithms produce identical ordering\n");
    } else {
        printf("[FAIL] Algorithms produce different ordering\n");
    }

    printf("\nEdge Case Tests:\n");

    Issue already_sorted[] = {
        {101, "Issue A", 10, 4, "Backend", -1},
        {102, "Issue B", 9, 3, "Frontend", -1},
        {103, "Issue C", 7, 2, "Database", -1},
        {104, "Issue D", 4, 5, "Backend", -1}
    };

    run_test("Already sorted input", already_sorted, 4);

    Issue reverse_sorted[] = {
        {104, "Issue D", 4, 5, "Backend", -1},
        {103, "Issue C", 7, 2, "Database", -1},
        {102, "Issue B", 9, 3, "Frontend", -1},
        {101, "Issue A", 10, 4, "Backend", -1}
    };

    run_test("Reverse sorted input", reverse_sorted, 4);

    Issue duplicate_priorities[] = {
        {113, "Issue C", 10, 4, "Backend", -1},
        {105, "Issue B", 10, 3, "Frontend", -1},
        {101, "Issue A", 10, 2, "Database", -1},
        {120, "Issue D", 8, 5, "Backend", -1}
    };

    run_test("Duplicate priorities", duplicate_priorities, 4);

    Issue single_issue[] = {
        {101, "Only issue", 7, 3, "Backend", -1}
    };

    run_test("Single issue", single_issue, 1);

    merge_sort_issues(NULL, 0);
    quick_sort_issues(NULL, 0);

    printf("[PASS] Zero issues - no crash\n");

    return 0;
    
}
#include <stdio.h>
#include "../include/sorting.h"

static int is_sorted_correctly(const Issue issues[], int count) {
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

static void run_test(const char *test_name, Issue issues[], int count) {
    merge_sort_issues(issues, count);

    if (is_sorted_correctly(issues, count)) {
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s\n", test_name);
    }
}

int main(void) {
    printf("Merge Sort Tests:\n");

    Issue normal[] = {
        {105, "Dark mode", 3, 8, "Frontend", -1},
        {103, "Database timeout", 9, 6, "Database", -1},
        {113, "Database backup failure", 10, 6, "Database", -1},
        {102, "Navbar issue", 4, 2, "Frontend", -1},
        {101, "Login crash", 10, 4, "Backend", -1}
    };

    run_test("Normal unsorted input", normal, 5);

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

    Issue single[] = {
        {101, "Only issue", 7, 3, "Backend", -1}
    };

    run_test("Single issue", single, 1);

    merge_sort_issues(NULL, 0);
    printf("[PASS] Empty input - no crash\n");

    return 0;
}
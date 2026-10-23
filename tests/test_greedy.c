#include <stdio.h>
#include "../include/greedy.h"

static void print_selected(Activity selected[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Issue %d | Start: %d | Finish: %d\n",
               selected[i].issue_id,
               selected[i].start_time,
               selected[i].finish_time);
    }
}

static void check_count(const char *test_name, int actual, int expected) {
    if (actual == expected) {
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s | Expected: %d | Got: %d\n",
               test_name, expected, actual);
    }
}

int main(void) {
    Activity activities[] = {
        {101, 1, 3},
        {102, 2, 5},
        {103, 4, 6},
        {104, 6, 8},
        {105, 5, 9}
    };

    Activity selected[5];

    int selected_count =
        activity_selection(activities, 5, selected);

    printf("Selected Activities:\n");
    print_selected(selected, selected_count);

    printf("\nTotal selected: %d\n", selected_count);

    printf("\nActivity Selection Tests:\n");

    check_count(
        "Normal overlapping activities",
        selected_count,
        3
    );

    Activity compatible[] = {
        {201, 1, 2},
        {202, 2, 3},
        {203, 3, 4},
        {204, 4, 5}
    };

    Activity selected_compatible[4];

    int compatible_count =
        activity_selection(compatible, 4, selected_compatible);

    check_count(
        "All compatible",
        compatible_count,
        4
    );

    Activity overlapping[] = {
        {301, 1, 6},
        {302, 2, 6},
        {303, 3, 6},
        {304, 4, 6}
    };

    Activity selected_overlapping[4];

    int overlapping_count =
        activity_selection(overlapping, 4, selected_overlapping);

    check_count(
        "Overlapping activities",
        overlapping_count,
        1
    );

    Activity single[] = {
        {401, 5, 7}
    };

    Activity selected_single[1];

    int single_count =
        activity_selection(single, 1, selected_single);

    check_count(
        "Single activity",
        single_count,
        1
    );

    int empty_count =
        activity_selection(NULL, 0, NULL);

    check_count(
        "Empty input",
        empty_count,
        0
    );

    return 0;
}
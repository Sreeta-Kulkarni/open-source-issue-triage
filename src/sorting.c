#include "../include/sorting.h"
#include <stddef.h>

static int comes_before(const Issue *a, const Issue *b) {
    if (a->priority > b->priority) {
        return 1;
    }

    if (a->priority < b->priority) {
        return 0;
    }

    return a->id < b->id;
}
static void merge(Issue issues[], int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    Issue left_array[left_size];
    Issue right_array[right_size];

    for (int i = 0; i < left_size; i++) {
        left_array[i] = issues[left + i];
    }

    for (int j = 0; j < right_size; j++) {
        right_array[j] = issues[mid + 1 + j];
    }
        int i = 0;
    int j = 0;
    int k = left;

    while (i < left_size && j < right_size) {
        if (comes_before(&left_array[i], &right_array[j])) {
            issues[k] = left_array[i];
            i++;
        } else {
            issues[k] = right_array[j];
            j++;
        }

        k++;
    }
        while (i < left_size) {
        issues[k] = left_array[i];
        i++;
        k++;
    }

    while (j < right_size) {
        issues[k] = right_array[j];
        j++;
        k++;
    }
}
static void merge_sort_recursive(Issue issues[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    merge_sort_recursive(issues, left, mid);
    merge_sort_recursive(issues, mid + 1, right);

    merge(issues, left, mid, right);
}
void merge_sort_issues(Issue issues[], int count) {
    if (issues == NULL || count <= 1) {
        return;
    }

    merge_sort_recursive(issues, 0, count - 1);
}

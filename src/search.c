#include <stddef.h>
#include "../include/search.h"
int binary_search_iterative(const Issue issues[], int count, int target_id) {
    if (issues == NULL || count <= 0) {
        return -1;
    }

    int low = 0;
    int high = count - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (issues[mid].id == target_id) {
            return mid;
        }

        if (issues[mid].id < target_id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}
static int binary_search_recursive_helper(
    const Issue issues[],
    int low,
    int high,
    int target_id
) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (issues[mid].id == target_id) {
        return mid;
    }

    if (issues[mid].id < target_id) {
        return binary_search_recursive_helper(
            issues,
            mid + 1,
            high,
            target_id
        );
    }

    return binary_search_recursive_helper(
        issues,
        low,
        mid - 1,
        target_id
    );
}
int binary_search_recursive(const Issue issues[], int count, int target_id) {
    if (issues == NULL || count <= 0) {
        return -1;
    }

    return binary_search_recursive_helper(
        issues,
        0,
        count - 1,
        target_id
    );
}
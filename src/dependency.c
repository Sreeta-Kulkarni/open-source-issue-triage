#include <stdio.h>
#include <stddef.h>
#include "../include/dependency.h"

int find_issue_index_by_id(const Issue issues[], int count, int issue_id) {
    if (issues == NULL || count <= 0) {
        return -1;
    }

    for (int i = 0; i < count; i++) {
        if (issues[i].id == issue_id) {
            return i;
        }
    }

    return -1;
}
int has_dependency(const Issue *issue) {
    if (issue == NULL) {
        return 0;
    }

    return issue->dependency_id != -1;
}
int validate_dependencies(const Issue issues[], int count) {
    if (issues == NULL || count <= 0) {
        return 0;
    }

    for (int i = 0; i < count; i++) {

        if (!has_dependency(&issues[i])) {
            continue;
        }

        int dependency_index =
            find_issue_index_by_id(
                issues,
                count,
                issues[i].dependency_id
            );

        if (dependency_index == -1) {
            return 0;
        }
    }

    return 1;
}
void print_dependency_chain(const Issue issues[], int count, int issue_id) {
    if (issues == NULL || count <= 0) {
        printf("No issue data available.\n");
        return;
    }

    int current_index =
        find_issue_index_by_id(issues, count, issue_id);

    if (current_index == -1) {
        printf("Issue %d not found.\n", issue_id);
        return;
    }

    int steps = 0;

    printf("\nDependency Chain:\n");

    while (current_index != -1 && steps < count) {
        const Issue *current = &issues[current_index];

        printf("Issue %d - %s\n",
               current->id,
               current->title);

        if (!has_dependency(current)) {
            printf("No further dependency.\n");
            return;
        }

        printf("    depends on\n");        
        
        int next_index =
            find_issue_index_by_id(
                issues,
                count,
                current->dependency_id
            );

        if (next_index == -1) {
            printf("Issue %d - INVALID DEPENDENCY\n",
                   current->dependency_id);
            return;
        }

        current_index = next_index;
        steps++;
    }    
    printf("Possible circular dependency detected.\n");
}
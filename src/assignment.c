#include <stddef.h>
#include <string.h>
#include "../include/assignment.h"

int assign_issues(const Issue issues[], int issue_count,
                  Developer developers[], int developer_count,
                  Assignment assignments[]) {

    if (issues == NULL || developers == NULL || assignments == NULL ||
        issue_count <= 0 || developer_count <= 0) {
        return 0;
    }

    int assignment_count = 0;

    for (int i = 0; i < issue_count; i++) {

        for (int j = 0; j < developer_count; j++) {

            if (strcmp(issues[i].required_skill,
                       developers[j].skill) == 0 &&
                developers[j].available_hours >= issues[i].estimated_hours) {

                assignments[assignment_count].issue_id = issues[i].id;
                assignments[assignment_count].developer_id = developers[j].id;

                developers[j].available_hours -= issues[i].estimated_hours;

                assignment_count++;

                break;
            }
        }
    }

    return assignment_count;
}
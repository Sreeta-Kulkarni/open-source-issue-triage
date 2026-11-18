#include <stddef.h>
#include <string.h>
#include "../include/matching.h"

static int is_compatible(
    const Issue *issue,
    const Developer *developer
) {
    if (issue == NULL || developer == NULL) {
        return 0;
    }

    if (strcmp(issue->required_skill, developer->skill) != 0) {
        return 0;
    }

    if (developer->available_hours < issue->estimated_hours) {
        return 0;
    }

    return 1;
}

static int try_match(
    int issue_index,
    const Issue issues[],
    const Developer developers[],
    int developer_count,
    int developer_match[],
    int visited[]
) {
    for (int d = 0; d < developer_count; d++) {

        if (!is_compatible(&issues[issue_index], &developers[d])) {
            continue;
        }

        if (visited[d]) {
            continue;
        }

        visited[d] = 1;

        if (developer_match[d] == -1 ||
            try_match(
                developer_match[d],
                issues,
                developers,
                developer_count,
                developer_match,
                visited
            )) {

            developer_match[d] = issue_index;
            return 1;
        }
    }

    return 0;
}
int maximum_bipartite_matching(
    const Issue issues[],
    int issue_count,
    const Developer developers[],
    int developer_count,
    Assignment assignments[]
) {
    if (issues == NULL || developers == NULL ||
        assignments == NULL ||
        issue_count <= 0 || developer_count <= 0) {
        return 0;
    }

    int developer_match[developer_count];

    for (int d = 0; d < developer_count; d++) {
        developer_match[d] = -1;
    }

    int match_count = 0;

    for (int i = 0; i < issue_count; i++) {
        int visited[developer_count];

        for (int d = 0; d < developer_count; d++) {
            visited[d] = 0;
        }

        if (try_match(
                i,
                issues,
                developers,
                developer_count,
                developer_match,
                visited
            )) {
            match_count++;
        }
    }
        int assignment_index = 0;

    for (int d = 0; d < developer_count; d++) {
        if (developer_match[d] != -1) {
            int issue_index = developer_match[d];

            assignments[assignment_index].issue_id =
                issues[issue_index].id;

            assignments[assignment_index].developer_id =
                developers[d].id;

            assignment_index++;
        }
    }

    return match_count;
}
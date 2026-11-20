#include <stddef.h>
#include <string.h>
#include "../include/matching.h"
#include "../include/io.h"

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
int capacity_aware_matching(
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

    Developer remaining_developers[MAX_DEVELOPERS];
    int assigned[MAX_ISSUES];

    for (int d = 0; d < developer_count; d++) {
        remaining_developers[d] = developers[d];
    }

    for (int i = 0; i < issue_count; i++) {
        assigned[i] = 0;
    }

    int total_assignments = 0;

    while (1) {
        Issue remaining_issues[MAX_ISSUES];
        int original_index[MAX_ISSUES];
        int remaining_count = 0;

        for (int i = 0; i < issue_count; i++) {
            if (!assigned[i]) {
                remaining_issues[remaining_count] = issues[i];
                original_index[remaining_count] = i;
                remaining_count++;
            }
        }

        if (remaining_count == 0) {
            break;
        }

        Assignment round_assignments[MAX_ISSUES];

        int round_count = maximum_bipartite_matching(
            remaining_issues,
            remaining_count,
            remaining_developers,
            developer_count,
            round_assignments
        );

        if (round_count == 0) {
            break;
        }

        for (int a = 0; a < round_count; a++) {
            int issue_id = round_assignments[a].issue_id;
            int developer_id = round_assignments[a].developer_id;

            int remaining_issue_index = -1;
            int developer_index = -1;

            for (int i = 0; i < remaining_count; i++) {
                if (remaining_issues[i].id == issue_id) {
                    remaining_issue_index = i;
                    break;
                }
            }

            for (int d = 0; d < developer_count; d++) {
                if (remaining_developers[d].id == developer_id) {
                    developer_index = d;
                    break;
                }
            }

            if (remaining_issue_index == -1 ||
                developer_index == -1) {
                continue;
            }

            int source_index =
                original_index[remaining_issue_index];

            assignments[total_assignments] =
                round_assignments[a];

            total_assignments++;

            remaining_developers[developer_index].available_hours -=
                issues[source_index].estimated_hours;

            assigned[source_index] = 1;
        }
    }

    return total_assignments;
}
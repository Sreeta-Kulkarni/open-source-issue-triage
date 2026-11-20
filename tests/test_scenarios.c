#include <stdio.h>
#include "../include/models.h"
#include "../include/io.h"
#include "../include/sorting.h"
#include "../include/matching.h"

static int run_scenario(
    const char *scenario_name,
    const char *issue_file,
    const char *developer_file
) {
    Issue issues[MAX_ISSUES];
    Developer developers[MAX_DEVELOPERS];
    Assignment assignments[MAX_ISSUES];

    int issue_count = load_issues(
        issue_file,
        issues,
        MAX_ISSUES
    );

    int developer_count = load_developers(
        developer_file,
        developers,
        MAX_DEVELOPERS
    );

    if (issue_count < 0 || developer_count < 0) {
        printf(
            "[FAIL] Could not load %s scenario data.\n",
            scenario_name
        );
        return -1;
    }

    merge_sort_issues(
        issues,
        issue_count
    );

    int match_count = maximum_bipartite_matching(
        issues,
        issue_count,
        developers,
        developer_count,
        assignments
    );

    printf("\n===== %s =====\n", scenario_name);
    printf("Issues: %d\n", issue_count);
    printf("Developers: %d\n", developer_count);
    printf("Matched issues: %d\n", match_count);

    return match_count;
}

int main(void) {
    int normal_matches = run_scenario(
        "NORMAL OPERATION",
        "data/issues_small.csv",
        "data/developers_small.csv"
    );

    int shock_matches = run_scenario(
        "CAPACITY SHOCK",
        "data/issues_small.csv",
        "data/scenario_shock_developers.csv"
    );

    int stress_matches = run_scenario(
        "LARGE-DATA STRESS",
        "data/stress_issues.csv",
        "data/stress_developers.csv"
    );

    if (normal_matches < 0 ||
        shock_matches < 0 ||
        stress_matches < 0) {
        return 1;
    }

    printf("\n===== NORMAL VS CAPACITY SHOCK =====\n");

    printf("Normal matches: %d\n", normal_matches);
    printf("Shock matches: %d\n", shock_matches);

    if (shock_matches < normal_matches) {
        printf(
            "Result: Capacity reduction decreased "
            "assignment coverage.\n"
        );

        printf(
            "Lost matches: %d\n",
            normal_matches - shock_matches
        );
    }

    else if (shock_matches == normal_matches) {
        printf("Result: Match count stayed the same.\n");
        printf(
            "The assignment structure may still "
            "have changed.\n"
        );
    }

    else {
        printf("Result: Unexpected increase in matches.\n");
    }

    printf("\n===== STRESS TEST RESULT =====\n");

    printf(
        "Stress dataset: 75 issues, 25 developers\n"
    );

    printf(
        "Matched issues: %d\n",
        stress_matches
    );

    printf(
        "[PASS] Large-data stress scenario "
        "completed without crash.\n"
    );

    return 0;
}
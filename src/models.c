#include <stdio.h>
#include "models.h"

void print_issue(const Issue *issue) {
    printf("Issue ID: %d\n", issue->id);
    printf("Title: %s\n", issue->title);
    printf("Priority: %d\n", issue->priority);
    printf("Estimated Hours: %d\n", issue->estimated_hours);
    printf("Required Skill: %s\n", issue->required_skill);

    if (issue->dependency_id == -1) {
        printf("Dependency: None\n");
    } else {
        printf("Dependency: Issue %d\n", issue->dependency_id);
    }
}

void print_developer(const Developer *developer) {
    printf("Developer ID: %d\n", developer->id);
    printf("Name: %s\n", developer->name);
    printf("Skill: %s\n", developer->skill);
    printf("Available Hours: %d\n", developer->available_hours);
}

int is_valid_issue(const Issue *issue) {
    if (issue == NULL) {
        return 0;
    }

    if (issue->id <= 0) {
        return 0;
    }

    if (issue->title[0] == '\0') {
        return 0;
    }

    if (issue->priority < 1 || issue->priority > 10) {
        return 0;
    }

    if (issue->estimated_hours <= 0) {
        return 0;
    }

    if (issue->required_skill[0] == '\0') {
        return 0;
    }

    return 1;
}
int is_valid_developer(const Developer *developer) {
    if (developer == NULL) {
        return 0;
    }

    if (developer->id <= 0) {
        return 0;
    }

    if (developer->name[0] == '\0') {
        return 0;
    }

    if (developer->skill[0] == '\0') {
        return 0;
    }

    if (developer->available_hours < 0) {
        return 0;
    }

    return 1;
}
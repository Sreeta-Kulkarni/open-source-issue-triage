#ifndef MODELS_H
#define MODELS_H

#define MAX_TITLE_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_SKILL_LENGTH 50

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    int priority;
    int estimated_hours;
    char required_skill[MAX_SKILL_LENGTH];
    int dependency_id;
} Issue;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char skill[MAX_SKILL_LENGTH];
    int available_hours;
} Developer;

void print_issue(const Issue *issue);
void print_developer(const Developer *developer);

int is_valid_issue(const Issue *issue);
int is_valid_developer(const Developer *developer);

#endif
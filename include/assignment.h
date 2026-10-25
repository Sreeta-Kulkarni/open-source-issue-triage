#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "models.h"

typedef struct {
    int issue_id;
    int developer_id;
} Assignment;

int assign_issues(
    const Issue issues[],
    int issue_count,
    Developer developers[],
    int developer_count,
    Assignment assignments[]
);

#endif
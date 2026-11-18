#ifndef MATCHING_H
#define MATCHING_H

#include "models.h"
#include "assignment.h"

int maximum_bipartite_matching(
    const Issue issues[],
    int issue_count,
    const Developer developers[],
    int developer_count,
    Assignment assignments[]
);

#endif
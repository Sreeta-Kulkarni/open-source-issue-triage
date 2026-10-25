#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include "models.h"

int find_issue_index_by_id(const Issue issues[], int count, int issue_id);
int has_dependency(const Issue *issue);
int validate_dependencies(const Issue issues[], int count);
void print_dependency_chain(const Issue issues[], int count, int issue_id);

#endif
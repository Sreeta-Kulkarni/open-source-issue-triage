#ifndef SEARCH_H
#define SEARCH_H

#include "models.h"

int binary_search_iterative(const Issue issues[], int count, int target_id);
int binary_search_recursive(const Issue issues[], int count, int target_id);

#endif
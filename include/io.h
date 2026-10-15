#ifndef IO_H
#define IO_H

#include "models.h"

#define MAX_ISSUES 100
#define MAX_DEVELOPERS 50

int load_issues(const char *filename, Issue issues[], int max_issues);
int load_developers(const char *filename, Developer developers[], int max_developers);

#endif
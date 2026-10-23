#ifndef GREEDY_H
#define GREEDY_H

typedef struct {
    int issue_id;
    int start_time;
    int finish_time;
} Activity;

int activity_selection(Activity activities[], int count, Activity selected[]);

#endif
#include <stddef.h>
#include "../include/greedy.h"

static void sort_by_finish_time(Activity activities[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (activities[j].finish_time > activities[j + 1].finish_time) {
                Activity temp = activities[j];
                activities[j] = activities[j + 1];
                activities[j + 1] = temp;
            }
        }
    }
}
int activity_selection(Activity activities[], int count, Activity selected[]) {
    if (activities == NULL || selected == NULL || count <= 0) {
        return 0;
    }

    sort_by_finish_time(activities, count);

    int selected_count = 0;

    selected[selected_count] = activities[0];
    selected_count++;

    int last_finish = activities[0].finish_time;

    for (int i = 1; i < count; i++) {
        if (activities[i].start_time >= last_finish) {
            selected[selected_count] = activities[i];
            selected_count++;

            last_finish = activities[i].finish_time;
        }
    }

    return selected_count;
}
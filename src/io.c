#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/io.h"

int load_issues(const char *filename, Issue issues[], int max_issues){
    FILE *file = fopen(filename, "r");

    if(file==NULL){
        return -1;
    }
    char line[300];
    int count = 0;

    if (fgets(line, sizeof(line), file) == NULL){
        fclose(file);
        return -1;
    }
    while (fgets(line, sizeof(line), file) != NULL && count < max_issues){
      char *token = strtok(line, ",");

    if (token == NULL) {
        continue;
    }

    issues[count].id = atoi(token);

    token = strtok(NULL, ",");

    if (token == NULL) {
        continue;
    }

    strncpy(issues[count].title, token, MAX_TITLE_LENGTH - 1);
    issues[count].title[MAX_TITLE_LENGTH - 1] = '\0';  

    token = strtok(NULL, ",");

    if (token == NULL) {
        continue;
    }

    issues[count].priority = atoi(token);
    token = strtok(NULL, ",");

    if (token == NULL) {
        continue;
    }

    issues[count].estimated_hours = atoi(token);
    token = strtok(NULL, ",");

    if (token == NULL) {
        continue;
    }

    strncpy(issues[count].required_skill, token, MAX_SKILL_LENGTH - 1);
    issues[count].required_skill[MAX_SKILL_LENGTH - 1] = '\0';

    token = strtok(NULL, ",\n");

    if (token == NULL) {
        continue;
    }

    issues[count].dependency_id = atoi(token);
    if (!is_valid_issue(&issues[count])) {
        continue;
    }
    count++;
    }
    fclose(file);
    return count;
}

int load_developers(const char *filename, Developer developers[], int max_developers) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        return -1;
    }

    char line[300];
    int count = 0;

    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return -1;
    }

    while (fgets(line, sizeof(line), file) != NULL && count < max_developers) {
        char *token = strtok(line, ",");
    if (token == NULL) {
        continue;
    }

    developers[count].id = atoi(token);

    token = strtok(NULL, ",");

    if (token == NULL) {
        continue;
    }

    strncpy(developers[count].name, token, MAX_NAME_LENGTH - 1);
    developers[count].name[MAX_NAME_LENGTH - 1] = '\0';

    token = strtok(NULL, ",");

    if (token == NULL) {
        continue;
    }

    strncpy(developers[count].skill, token, MAX_SKILL_LENGTH - 1);
    developers[count].skill[MAX_SKILL_LENGTH - 1] = '\0';

    token = strtok(NULL, ",\n");

    if (token == NULL) {
        continue;
    }

    developers[count].available_hours = atoi(token);

    if (!is_valid_developer(&developers[count])) {
        continue;
    }

    count++;    
}
    fclose(file);
    return count;
}
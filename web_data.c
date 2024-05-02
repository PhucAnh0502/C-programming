#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WEBS 10000

typedef struct {
    char date[11];
    char timePoint[9];
    char inforType[5];
    int inforID;
    char noti[50];
} Web;

int processLine(Web *log, int i, FILE *fp) {
    char line[256];
    char *token;

    if (fgets(line, sizeof(line), fp) == NULL) {
        return 0;
    }

    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
    }

    token = strtok(line, " ");
    if (token != NULL) {
        strncpy(log[i].date, token, sizeof(log[i].date) - 1);
        log[i].date[sizeof(log[i].date) - 1] = '\0';
    }

    token = strtok(NULL, " ");
    if (token != NULL) {
        strncpy(log[i].timePoint, token, sizeof(log[i].timePoint) - 1);
        log[i].timePoint[sizeof(log[i].timePoint) - 1] = '\0';
    }

    token = strtok(NULL, " ");
    if (token != NULL) {
        if (strcmp(token, "INFO") == 0) {
            strncpy(log[i].inforType, token, sizeof(log[i].inforType) - 1);
            log[i].inforType[sizeof(log[i].inforType) - 1] = '\0';

            token = strtok(NULL, " ");
            log[i].inforID = atoi(token);

            token = strtok(NULL, "\n");
            strncpy(log[i].noti, token, sizeof(log[i].noti) - 1);
            log[i].noti[sizeof(log[i].noti) - 1] = '\0';
        } else {
            strncpy(log[i].inforType, token, sizeof(log[i].inforType) - 1);
            log[i].inforType[sizeof(log[i].inforType) - 1] = '\0';
            log[i].inforID = 0;

            token = strtok(NULL, "\n");
            strncpy(log[i].noti, token, sizeof(log[i].noti) - 1);
            log[i].noti[sizeof(log[i].noti) - 1] = '\0';
        }
    }
    return 1;
}

int compareLogData(const void *a, const void *b) {
    const Web *logA = (const Web *) a;
    const Web *logB = (const Web *) b;

    // So sánh m?c d? lo?i thông báo (ERRO > WARN > INFO)
    if (strcmp(logA->inforType, "ERRO") == 0) {
        if (strcmp(logB->inforType, "ERRO") != 0) {
            return -1;
        } else return 0;
    } else if (strcmp(logA->inforType, "WARN") == 0) {
        if (strcmp(logB->inforType, "ERRO") == 0) {
            return 1;
        } else if (strcmp(logB->inforType, "WARN") != 0) {
            return -1;
        } else return 0;
    } else if (strcmp(logA->inforType, "INFO") == 0) {
        if (strcmp(logB->inforType, "ERRO") == 0 || strcmp(logB->inforType, "WARN") == 0) {
            return 1;
        } else return 0;
    }

    // So sánh th?i di?m
    int timeComparison = strcmp(logA->timePoint, logB->timePoint);
    if (timeComparison != 0) {
        return timeComparison;
    }

    // So sánh n?i dung thông báo
    return strcmp(logA->noti, logB->noti);
}

int main() {
    Web log[MAX_WEBS];
    int numWebs = 0;

    while (numWebs < MAX_WEBS && processLine(log, numWebs, stdin)) {
        numWebs++;
    }

    qsort(log, numWebs, sizeof(Web), compareLogData);

    for (int j = 0; j < numWebs; j++) {
        if (log[j].inforID == 0) {
            printf("%s %s %s %s\n", log[j].date, log[j].timePoint, log[j].inforType, log[j].noti);
        } else {
            printf("%s %s %s %d %s\n", log[j].date, log[j].timePoint, log[j].inforType, log[j].inforID, log[j].noti);
        }
    }

    return 0;
}

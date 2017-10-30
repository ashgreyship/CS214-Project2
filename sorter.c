#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include "Sorter.h"
#include <sys/mman.h>
#include <limits.h>
#include "mergesort.c"

static int *totalPro;

int main(int agrc, char *argv[]) {
    if (agrc < 3 || agrc == 4 || agrc == 6 || agrc > 7) {
        printf("Format of arguments is incorrect\n");
        return 1;
    }
    if (strcmp(argv[1], "-c") != 0) {
        printf("first argument is incorrect\n");
        return 1;
    }

    char *sortField = argv[2];
    char *inputDir = malloc(sizeof(char) * 100);
    char *outputDir = NULL;

    if (agrc == 5 || agrc == 7) {
        if (strcmp(argv[3], "-d") == 0) {
            inputDir = argv[4];
        } else if (strcmp(argv[3], "-o") == 0) {
            outputDir = argv[4];
        }
    }
    if (agrc == 7) {
        if (strcmp(argv[5], "-d") == 0) {
            inputDir = argv[6];
        } else if (strcmp(argv[5], "-o") == 0) {
            outputDir = argv[6];
        }
    }
    if (inputDir == NULL) {
        inputDir = ".";
    }
    if (outputDir == NULL) {
        outputDir = ".";
    }

    //int totalPro=1;
    int parentPID = getpid();
    printf("Initial PID: %d\n", parentPID);
    printf("PIDS of all child processes: ");
    fflush(stdout);
    int indent;


    totalPro = mmap(NULL, sizeof *totalPro, PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *totalPro = 1;
    readDirectory(inputDir, parentPID, indent);
    printf("\ntotal process:%d\n",*totalPro);
    munmap(totalPro, sizeof *totalPro);



//    unsortMovie **unsortMovies = malloc(sizeof(struct unsortMovie *) * 100000);
//    int row;
//    for (row = 0; row < 100000; row++) {
//        unsortMovies[row] = malloc(sizeof(unsortMovie) * 10000);
//    }
//
//    int totalRow;
//    storeRows(unsortMovies, &totalRow);
//    splitRows(unsortMovies, totalRow);
//
//    int sortFieldToInt;
//    if (checkFieldExistence(unsortMovies, sortField, &sortFieldToInt) == 1) {
//        printf("the field is not exist\n");
//        freeStructArray(unsortMovies);
//        return 1;
//    }
//
//    unsortMovie **preSortMovies = malloc(sizeof(struct unsortMovie *) * 100000);
//
//    excludeFirstStruct(unsortMovies, preSortMovies, totalRow);
//
//    initializeMergeSort(preSortMovies, sortFieldToInt, totalRow - 1);
//    printSortedMovies(unsortMovies, preSortMovies, totalRow - 1);


//    freeStructArray(unsortMovies);
//    free(preSortMovies);
//    free(pidArray);
    return 0;
}

int storeRows(unsortMovie **unsortMovies, int *totalRow) {
    *totalRow = 0;
    char *currRow = malloc(sizeof(char) * 50000);
    while (fgets(currRow, 50000, stdin)) {
        currRow[strcspn(currRow, "\n")] = 0;
        unsortMovies[*totalRow]->aRowString = malloc(sizeof(char) * 5000);
        strcpy(unsortMovies[*totalRow]->aRowString, currRow);
        (*totalRow)++;
    }
    free(currRow);
    return 0;
}

int splitRows(unsortMovie **unsortMovies, int totalRow) {
    int currRowNum;
    for (currRowNum = 0; currRowNum < totalRow; currRowNum++) {
        splitOneRow(unsortMovies, currRowNum);
    }
    return 0;
}

int splitOneRow(unsortMovie **unsortMovies, int currRowNum) {
    char *oneRow = malloc(sizeof(char) * 50000);
    strcpy(oneRow, unsortMovies[currRowNum]->aRowString);
    //char* oneRow= unsortMovies[currRowNum].aRowString;
    deleteSpaces(oneRow);
    formatQuotesFileds(oneRow);
    unsortMovies[currRowNum]->aRowfieldsArray = rowIntoFields(oneRow);
    free(oneRow);
    return 0;
}

void deleteSpaces(char *oneRow) {
    char *i = oneRow;
    char *j = oneRow;
    while (*j != 0) {
        *i = *j++;
        if (*i != ' ')
            i++;
    }
    *i = 0;
}

void formatQuotesFileds(char *oneRow) {
    char *tmpString = malloc(sizeof(char) * 50000);;
    char *token;
    char *beginStr = malloc(sizeof(char) * 50000);
    char *endStr = malloc(sizeof(char) * 50000);
    char *midStr = malloc(sizeof(char) * 50000);

    strcpy(tmpString, oneRow);
    token = strtok(tmpString, "\"");
    strcpy(beginStr, token);
    token = strtok(NULL, "\"");

    if (token) {
        deleteComma(token);
        strcpy(midStr, token);
        token = strtok(NULL, "\"");
        strcpy(endStr, token);

        tmpString[0] = '\0';
        strcat(tmpString, beginStr);
        strcat(tmpString, midStr);
        strcat(tmpString, endStr);
        strcpy(oneRow, tmpString);
    }
    //printf("%s",oneRow);
    free(tmpString);
    free(beginStr);
    free(endStr);
    free(midStr);
}

void deleteComma(char *subString) {
    char *r, *w;
    for (w = r = subString; *r; r++) {
        if (*r != ',') {
            *w++ = *r;
        }
    }
    *w = '\0';
}

char **rowIntoFields(char *oneRow) {
    char **oneRowFields = malloc(sizeof(char *) * 100);
    int i;
    for (i = 0; i < 100; i++) {
        oneRowFields[i] = malloc(sizeof(char) * 50000);
    }
    char *tmpString = malloc(sizeof(char) * 5000);
    strcpy(tmpString, oneRow);
    checkFirstField(tmpString);

    char *tmp = malloc(sizeof(char) * 1000);
    char *comma = malloc(sizeof(char) * 100);
    strcpy(comma, ",");
    int j = 0;
    while (sscanf(tmpString, "%[^,],", tmp) != EOF) {
        // printf("OUTPUT:%s\n", tmp);
        removeFirst(tmpString, tmp);
        removeFirst(tmpString, comma);
        checkFirstField(tmpString);
        strcpy(oneRowFields[j], tmp);
        j++;
    }
    free(tmp);
    free(comma);
    free(tmpString);
    return oneRowFields;
}

void checkFirstField(char *tmpString) {
    char firstChar = tmpString[0];
    if (firstChar == ',') {
        char *newRow = malloc(sizeof(char) * 80000);
        strcpy(newRow, "!");
        strcat(newRow, tmpString);
        strcpy(tmpString, newRow);
        free(newRow);
    }

}

void removeFirst(char *str, const char *toRemove) {
    int i, j;
    int len, removeLen;
    int found = 0;

    len = strlen(str);
    removeLen = strlen(toRemove);

    for (i = 0; i < len; i++) {
        found = 1;
        for (j = 0; j < removeLen; j++) {
            if (str[i + j] != toRemove[j]) {
                found = 0;
                break;
            }
        }
        if (found == 1) {
            for (j = i; j <= len - removeLen; j++) {
                str[j] = str[j + removeLen];
            }
            break;
        }
    }
}

int checkFieldExistence(unsortMovie **unsortMovies, char *sortField, int *sortFieldToInt) {
    int fieldNum;
    *sortFieldToInt = -1;
    int isExistence = 1;  // not exist
    for (fieldNum = 0; fieldNum < 28; fieldNum++) {
        char *currField = malloc(sizeof(char) * 200);
        strcpy(currField, unsortMovies[0]->aRowfieldsArray[fieldNum]);
        delCarriageReturn(currField);
        if (strcmp(currField, sortField) == 0) {
            isExistence = 0;
            *sortFieldToInt = fieldNum + 1;
            break;
        }
        free(currField);
    }

    return isExistence;
}

void delCarriageReturn(char *str) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != '\r') dst++;
    }
    *dst = '\0';
}

void freeStructArray(unsortMovie **unsortMovies) {
    int row;
    int i;


    for (row = 0; row < 100000; row++) {
        free(unsortMovies[row]->aRowfieldsArray);
        free(unsortMovies[row]->aRowString);
        free(unsortMovies[row]);
    }
    free(unsortMovies);
}

void printSortedMovies(unsortMovie **unsortMovies, unsortMovie **preSortMovies, int totalRow) {
    int i;
    printf("%s", unsortMovies[0]->aRowString);
    for (i = 0; i < totalRow; i++) {
        printf("%s", preSortMovies[i]->aRowString);
    }
}

void excludeFirstStruct(unsortMovie **unsortMovies, unsortMovie **preSortMovies, int totalRow) {
    int i;
    for (i = 1; i < totalRow; i++) {
        preSortMovies[i - 1] = unsortMovies[i];
    }
}

//    On each new file in a directory you encounter, you should fork() a child process to do the actual sorting.
//    On each new directory you encounter, you should fork() a child process to process the directory.
void readDirectory(char *inputDir, int parentPID, int indent) {
    DIR *dir;
    struct dirent *dp;
    if (!(dir = opendir(inputDir))) {
        printf("%s directory does not exist\n", inputDir);
        return;
    }
    while ((dp = readdir(dir)) != NULL) {
        if (dp->d_name[0] == '.') {
            continue;
        }
        if (dp->d_type == DT_DIR) {
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", inputDir, dp->d_name);
            //  printf("%*s[%s]\n", indent, "", dp->d_name);
            (*totalPro)++;
            pid_t pid = fork();
            if (pid > 0) {    // it is parent
                printf("%d,", pid);
                fflush(stdout);
            } else if (pid == 0) {    //it is child
                readDirectory(path, parentPID, indent + 2);
                exit(EXIT_SUCCESS);
            }
        } else {
            char *fileExtension = strrchr(dp->d_name, '.');
            if (strcmp(fileExtension + 1, "csv") == 0) {
                (*totalPro)++;
                pid_t pid = fork();
                if (pid > 0) {    // it is parent
                    printf("%d,", pid);
                    fflush(stdout);
                    //keep searching
                } else {
                    //sort the csv file.
                    exit(EXIT_SUCCESS);
                }
            }
        }

    }
    closedir(dir);
    int pid;
    while ((pid=wait(NULL))!=-1) {
        //printf("Process %d terminated\n",pid);
    }
   // printf("\npid is %d", getpid());

}





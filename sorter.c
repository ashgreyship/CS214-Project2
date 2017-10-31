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
    if (agrc < 3 || agrc > 7) {
        printf("Format of arguments is incorrect\n");
        return 1;
    }

    if (strcmp(argv[1], "-c") != 0) {
        printf("first argument is incorrect\n");
        return 1;
    }

    char *sortField = argv[2];
    char *inputDir = NULL;
    char *outputDir = NULL;

    if (agrc == 3) {
        inputDir = ".";
        outputDir = "srcDir";
    }
    if (agrc == 4) {
        if (strcmp(argv[3], "-o") == 0) {
            inputDir = ".";
            outputDir = "currDir";
        } else {
            printf("The format of command line parameters is incorrect ");
            return 1;
        }
    }
    if (agrc == 5) {
        if (strcmp(argv[3], "-d") == 0 && strcmp(argv[4], "-o") != 0) {
            inputDir = argv[4];
            outputDir = "srcDir";
        } else if (strcmp(argv[3], "-o") == 0 && strcmp(argv[4], "-d") != 0) {
            inputDir = ".";
            outputDir = argv[4];
        } else {
            printf("second argument is incorrect\n");
            return 1;
        }
    }

    if (agrc == 6) {
        if (strcmp(argv[3], "-d") == 0 && strcmp(argv[4], "-o") != 0 && strcmp(argv[5], "-o") == 0) {
            inputDir = argv[4];
            outputDir = "currDir";
        } else {
            printf("The format of command line parameters is incorrect\n");
            return 1;
        }
    }

    if (agrc == 7) {
        if (strcmp(argv[3], "-d") == 0 && strcmp(argv[4], "-o") != 0) {
            inputDir = argv[4];
        } else {
            printf("The format of command line parameters is incorrect\n");
            return 1;
        }
        if (strcmp(argv[5], "-o") == 0 && strcmp(argv[6], "-d") != 0) {
            outputDir = argv[6];
        } else {
            printf("The format of command line parameters is incorrect\n");
            return 1;
        }
    }

    char SrcPath[1024];
    getcwd(SrcPath, sizeof(SrcPath));
    printf("Source source path is %s\n", SrcPath);

    int parentPID = getpid();
    printf("Initial PID: %d\n", parentPID);
    printf("PIDS of all child processes: ");
    fflush(stdout);
    int indent;

    totalPro = mmap(NULL, sizeof *totalPro, PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *totalPro = 1;
    readDirectory( inputDir, outputDir, indent, sortField);
    printf("\ntotal process:%d\n", *totalPro);
    munmap(totalPro, sizeof *totalPro);
    return 0;
}


void readDirectory(char *inputDir, char *outputDir, int indent, char *sortField) {
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
            (*totalPro)++;
            pid_t pid = fork();
            if (pid > 0) {    // it is parent
                printf("%d,", pid);
                fflush(stdout);
            } else if (pid == 0) {    //it is child
                readDirectory(path, outputDir, indent + 2, sortField);
                exit(EXIT_SUCCESS);
            }
        } else {
            char *fileExtension = strrchr(dp->d_name, '.');
            if (fileExtension == NULL) {
                continue;
            }
            if (strcmp(fileExtension + 1, "csv") == 0) {
                char path[1024];
                snprintf(path, sizeof(path), "%s/%s", inputDir, dp->d_name);
                (*totalPro)++;
                pid_t pid = fork();
                if (pid > 0) {    // it is parent
                    printf("%d,", pid);
                    fflush(stdout);
                } else {
                    multiSort(dp->d_name, path, sortField, outputDir);
                    exit(EXIT_SUCCESS);
                }
            }
        }
    }
    closedir(dir);
    int pid;
    while ((pid = wait(NULL)) != -1) {
        //printf("Process %d terminated\n",pid);
    }
}

int multiSort(char *CSVName, char *CSVPath, char *sortField, char *outputDir) {
    unsortMovie **unsortMovies = malloc(sizeof(struct unsortMovie *) * 100000);
    int row;
    for (row = 0; row < 100000; row++) {
        unsortMovies[row] = malloc(sizeof(unsortMovie) * 10000);
    }
    int totalRow;

    storeRows(CSVPath, unsortMovies, &totalRow);
    splitRows(unsortMovies, totalRow);


    int sortFieldToInt;
    if (checkFieldExistence(unsortMovies, sortField, &sortFieldToInt) == 1) {
        printf("\nthe field does not exist\n");
        freeStructArray(unsortMovies);
        _exit(0);
    }

    unsortMovie **preSortMovies = malloc(sizeof(struct unsortMovie *) * 100000);
    excludeFirstStruct(unsortMovies, preSortMovies, totalRow);
    initializeMergeSort(preSortMovies, sortFieldToInt, totalRow - 1);

    printSortedMovies(CSVName, CSVPath, sortField, unsortMovies, preSortMovies,
                      totalRow - 1, outputDir);

    freeStructArray(unsortMovies);
    free(preSortMovies);
    return 0;
}

void
printSortedMovies(char *CSVName, char *CSVPath, char *sortField,
                  unsortMovie **unsortMovies,
                  unsortMovie **preSortMovies,
                  int totalRow, char *outputDir) {

    char *outputFileName = malloc(sizeof(char)*10000);
    FILE *fptr;
    if (strcmp(outputDir, "srcDir") == 0) {
        formatOutputNameinSrcDir(outputFileName, sortField, CSVName);
        fptr = fopen(outputFileName, "w");
    } else if (strcmp(outputDir, "currDir") == 0) {
        formatOutputNameinCurrDir(outputFileName, sortField, CSVPath);
        fptr = fopen(outputFileName, "w");
    } else {
        struct stat st = {0};
        if (stat(outputDir, &st) == -1) {
            mkdir(outputDir, 0700);
        }
        formatOutputNameinDir(outputFileName, sortField, outputDir, CSVName);
        fptr = fopen(outputFileName, "w");
    }
    int i;
    fprintf(fptr, "%s\n", unsortMovies[0]->aRowString);
    for (i = 0; i < totalRow; i++) {
        fprintf(fptr, "%s\n", preSortMovies[i]->aRowString);
    }
    fclose(fptr);
    free(outputFileName);

}

void formatOutputNameinSrcDir(char *outputFileName, char *sortField, char *CSVName) {
    // new_str[0] = '\0';
    outputFileName[0]='\0';
    char *CSVNameWithoutExtension = malloc(sizeof(char) * 100000);
    removefileNameExtension(CSVName, CSVNameWithoutExtension);
    strcat(outputFileName, CSVNameWithoutExtension);
    strcat(outputFileName, "-sorted-");
    strcat(outputFileName, sortField);
    strcat(outputFileName, ".csv");
    //printf("\nformatOutputNameinSrcDir is %s\n", outputFileName);
    free(CSVNameWithoutExtension);
}

void formatOutputNameinCurrDir(char *outputFileName, char *sortField, char *CSVPath) {
    // new_str[0] = '\0';
    char *CSVPathWithoutExtension = malloc(sizeof(char) * 100000);
    removefileNameExtension(CSVPath, CSVPathWithoutExtension);
    strcat(outputFileName, CSVPathWithoutExtension);
    strcat(outputFileName, "-sorted-");
    strcat(outputFileName, sortField);
    strcat(outputFileName, ".csv");
    //printf("\nformatOutputNameinCurrDir is %s\n", outputFileName);
    free(CSVPathWithoutExtension);
}

void formatOutputNameinDir(char *outputFileName, char *sortField, char *outputDir, char *CSVName) {
    //new_str[0] = '\0';
    char *CSVNameWithoutExtension = malloc(sizeof(char) * 100000);
    removefileNameExtension(CSVName, CSVNameWithoutExtension);
    strcat(outputFileName, outputDir);
    strcat(outputFileName, "/");
    strcat(outputFileName, CSVNameWithoutExtension);
    strcat(outputFileName, "-sorted-");
    strcat(outputFileName, sortField);
    strcat(outputFileName, ".csv");
    //printf("\nformatOutputNameinSrcDir is %s\n", outputFileName);
    free(CSVNameWithoutExtension);
}

void removefileNameExtension(char *fileName, char *fileWithoutExtension) {
    int num = strstr(fileName, ".") - fileName;
    strncpy(fileWithoutExtension, fileName, num);
}

void storeRows(char *CSVPath, unsortMovie **unsortMovies, int *totalRow) {
    FILE *fp;
    fp = fopen(CSVPath, "r");
    if (fp == NULL) {
        printf("\nfilepath is %s", CSVPath);
        perror("Error opening file");
        _exit(0);
    }

    *totalRow = 0;
    char *currRow = malloc(sizeof(char) * 50000);
    while (fgets(currRow, 50000, fp)) {
        currRow[strcspn(currRow, "\n")] = 0;

        unsortMovies[*totalRow]->aRowString = malloc(sizeof(char) * 5000);
        strcpy(unsortMovies[*totalRow]->aRowString, currRow);
        (*totalRow)++;
    }
    free(currRow);
    fclose(fp);
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
    //printf("j is :%d\n",j);
    if (j != 28) {
        _exit(0);
    }
    free(tmp);
    free(comma);
    free(tmpString);
    return oneRowFields;
}

void checkFirstField(char *tmpString) {    //special case: if the first field is empty space
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
    for (row = 0; row < 100000; row++) {
        free(unsortMovies[row]->aRowfieldsArray);
        free(unsortMovies[row]->aRowString);
        free(unsortMovies[row]);
    }
    free(unsortMovies);
}


void excludeFirstStruct(unsortMovie **unsortMovies, unsortMovie **preSortMovies, int totalRow) {
    int i;
    for (i = 1; i < totalRow; i++) {
        preSortMovies[i - 1] = unsortMovies[i];
    }
}





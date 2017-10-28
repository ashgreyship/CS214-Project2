#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//
#include "Sorter.h"


void initializeMergeSort(unsortMovie **preSortMovies, int sortFieldToInt, int totalRow);

void mergeSort(unsortMovie **preSortMovies, int totalRow, int originalRows, int sortFieldToInt);

void merge(unsortMovie **preSortMovies, unsortMovie **leftUnsortMovies, int leftCount, unsortMovie **rightUnsortMovies,
           int rightCount, int sortFieldToInt);

void initializeMergeSort(unsortMovie **preSortMovies, int sortFieldToInt, int totalRow) {
    mergeSort(preSortMovies, totalRow, totalRow, sortFieldToInt);
}

void mergeSort( unsortMovie **preSortMovies, int totalRow, int originalRows, int sortFieldToInt) {
    if (totalRow < 2) return;
    int middle = totalRow / 2;

    int row;
    unsortMovie **leftArray = malloc(sizeof(struct unsortMovie * ) * middle);
    unsortMovie **rightArray = malloc(sizeof(struct unsortMovie * ) * (totalRow - middle));

//    for (row = 0; row < middle; row++) {
//        leftArray[row] = malloc(sizeof(unsortMovie) * 100000);
//    }
//    for (row = 0; row < (totalRow - middle); row++) {
//        rightArray[row] = malloc(sizeof(unsortMovie) * 100000);
//    }


    int i;
    for (i = 0; i < middle; i++) {
        leftArray[i] = preSortMovies[i];
    }

    for (i = middle; i < totalRow; i++) {
        rightArray[i - middle] = preSortMovies[i];
    }

    mergeSort(leftArray, middle, originalRows, sortFieldToInt);
    mergeSort(rightArray, totalRow - middle, originalRows, sortFieldToInt);
    merge(preSortMovies, leftArray, middle, rightArray, totalRow - middle, sortFieldToInt);


//    for (row = 0; row < middle; row++) {
//        free(leftArray[row]);
//    }
//    for (row = 0; row < (totalRow-middle); row++) {
//        free(rightArray[row]);
//    }
    free(leftArray);
    free(rightArray);

}

void merge(unsortMovie **preSortMovies, unsortMovie **leftUnsortMovies, int leftCount, unsortMovie **rightUnsortMovies,
           int rightCount, int sortFieldToInt) {
    int leftIndex, rightIndex, mergedIndex;
    leftIndex = 0;
    rightIndex = 0;
    mergedIndex = 0;

    if(sortFieldToInt==1||sortFieldToInt==2||sortFieldToInt==7||sortFieldToInt==10||sortFieldToInt==11||sortFieldToInt==12||sortFieldToInt==15||sortFieldToInt==17||sortFieldToInt==18||sortFieldToInt==20||sortFieldToInt==21||sortFieldToInt==22){
        while (leftIndex < leftCount && rightIndex < rightCount) {
            if (strcmp(leftUnsortMovies[leftIndex]->aRowfieldsArray[sortFieldToInt - 1],
                       rightUnsortMovies[rightIndex]->aRowfieldsArray[sortFieldToInt - 1]) < 0) {
                preSortMovies[mergedIndex++] = leftUnsortMovies[leftIndex++];
            } else {
                preSortMovies[mergedIndex++] = rightUnsortMovies[rightIndex++];
            }
        }
    }else{
        while (leftIndex < leftCount && rightIndex < rightCount) {
            if (strtod(leftUnsortMovies[leftIndex]->aRowfieldsArray[sortFieldToInt - 1],NULL)< strtod(rightUnsortMovies[rightIndex]->aRowfieldsArray[sortFieldToInt - 1],NULL)) {
                preSortMovies[mergedIndex++] = leftUnsortMovies[leftIndex++];
            } else {
                preSortMovies[mergedIndex++] = rightUnsortMovies[rightIndex++];
            }
        }
    }

    while (leftIndex < leftCount) {
        preSortMovies[mergedIndex++] = leftUnsortMovies[leftIndex++];
    }
    while (rightIndex < rightCount) {
        preSortMovies[mergedIndex++] = rightUnsortMovies[rightIndex++];
    }
}




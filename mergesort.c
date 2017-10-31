#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//#include "Sorter.h"


void initializeMergeSort(unsortMovie **preSortMovies, int sortFieldToInt, int totalRow);

void mergeSort(unsortMovie **preSortMovies, int totalRow, int originalRows, int sortFieldToInt);

void merge(unsortMovie **preSortMovies, unsortMovie **leftUnsortMovies, int leftCount, unsortMovie **rightUnsortMovies,
           int rightCount, int sortFieldToInt);

void initializeMergeSort(unsortMovie **preSortMovies, int sortFieldToInt, int totalRow) {
    mergeSort(preSortMovies, totalRow, totalRow, sortFieldToInt);

}

void mergeSort(unsortMovie **preSortMovies, int totalRow, int originalRows, int sortFieldToInt) {
    if (totalRow < 2) return;
    int middle = totalRow / 2;

    int row;
    unsortMovie **leftArray = malloc(sizeof(struct unsortMovie *) * middle);
    unsortMovie **rightArray = malloc(sizeof(struct unsortMovie *) * (totalRow - middle));

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

    free(leftArray);
    free(rightArray);

}

void merge(unsortMovie **preSortMovies, unsortMovie **leftUnsortMovies, int leftCount, unsortMovie **rightUnsortMovies,
           int rightCount, int sortFieldToInt) {
    int leftIndex, rightIndex, mergedIndex;
    leftIndex = 0;
    rightIndex = 0;
    mergedIndex = 0;

    if (sortFieldToInt == 1 || sortFieldToInt == 2 || sortFieldToInt == 7 || sortFieldToInt == 10 ||
        sortFieldToInt == 11 || sortFieldToInt == 12 || sortFieldToInt == 15 || sortFieldToInt == 17 ||
        sortFieldToInt == 18 || sortFieldToInt == 20 || sortFieldToInt == 21 || sortFieldToInt == 22) {
        while (leftIndex < leftCount && rightIndex < rightCount) {
            int leftLength = strlen(leftUnsortMovies[leftIndex]->aRowfieldsArray[sortFieldToInt - 1]);
            int rightLength = strlen(rightUnsortMovies[rightIndex]->aRowfieldsArray[sortFieldToInt - 1]);
            int strLength = leftLength;
            if (leftLength > rightLength)
                strLength = rightIndex;
            int j = 0;
            for (j = 0; j < strLength; j++) {
                char leftChar = leftUnsortMovies[leftIndex]->aRowfieldsArray[sortFieldToInt - 1][j];
                char rightChar = rightUnsortMovies[rightIndex]->aRowfieldsArray[sortFieldToInt - 1][j];
                int leftCharToInt = leftChar - '0';
                int rightCharToInt = rightChar - '0';

                int leftIsUpper = isupper((int) leftChar);
                int rightIsUpper = isupper((int) rightChar);

                if (leftIsUpper != 0 && rightIsUpper != 0) {   //both Upper
                    if (leftCharToInt < rightCharToInt) {
                        preSortMovies[mergedIndex++] = leftUnsortMovies[leftIndex++];
                        break;
                    } else if(leftCharToInt > rightCharToInt) {
                        preSortMovies[mergedIndex++] = rightUnsortMovies[rightIndex++];
                        break;
                    }else{
                        continue;
                    }
                } else if (leftIsUpper == 0 && rightIsUpper == 0) {   //both Lower
                    if (leftCharToInt < rightCharToInt) {
                        preSortMovies[mergedIndex++] = leftUnsortMovies[leftIndex++];
                        break;
                    } else if(leftCharToInt > rightCharToInt){
                        preSortMovies[mergedIndex++] = rightUnsortMovies[rightIndex++];
                        break;
                    }else{
                        continue;
                    }
                } else if (leftIsUpper != 0 && rightIsUpper == 0) {   // left Upper, right Lower
                    if (leftCharToInt + 32 == rightCharToInt) {
                        preSortMovies[mergedIndex++] = leftUnsortMovies[leftIndex++];
                        break;
                    }else if(leftCharToInt + 32 < rightCharToInt){
                        preSortMovies[mergedIndex++] = leftUnsortMovies[leftIndex++];
                        break;
                    }else {
                        preSortMovies[mergedIndex++] = rightUnsortMovies[rightIndex++];
                        break;
                    }
                }else if(leftIsUpper == 0 && rightIsUpper != 0){    // left Lower, right Upper
                    if(rightCharToInt+32 == leftCharToInt){

                        break;
                    }else if(rightCharToInt+32 < leftCharToInt){
                        preSortMovies[mergedIndex++] = rightUnsortMovies[rightIndex++];
                        break;
                    }else{
                        preSortMovies[mergedIndex++] = leftUnsortMovies[leftIndex++];
                        break;
                    }
                }
            }
        }
    } else {
        while (leftIndex < leftCount && rightIndex < rightCount) {
            if (strtod(leftUnsortMovies[leftIndex]->aRowfieldsArray[sortFieldToInt - 1], NULL) <
                strtod(rightUnsortMovies[rightIndex]->aRowfieldsArray[sortFieldToInt - 1], NULL)) {
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




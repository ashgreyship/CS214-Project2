typedef struct movie {
    char **aRowfieldsArray;
    char *aRowString;
} unsortMovie;

void readDirectory(char *inputDir, char *outputDir, int indent, char *sortField);

int multiSort(char *CSVName, char *CSVPath, char *sortField, char *outputDir);

void
printSortedMovies(char *CSVName, char *CSVPath, char *sortField,
                  unsortMovie **unsortMovies,
                  unsortMovie **preSortMovies,
                  int totalRow, char *outputDir);

void formatOutputNameinSrcDir(char *outputFileName, char *sortField, char *CSVName);

void formatOutputNameinCurrDir(char *outputFileName, char *sortField, char *CSVPath);

void formatOutputNameinDir(char *outputFileName, char *sortField, char *outputDir, char *CSVName);

void removefileNameExtension(char *fileName, char *fileWithoutExtension);

void storeRows(char *CSVPath, unsortMovie **unsortMovies, int *totalRow);

int splitRows(unsortMovie **unsortMovies, int totalRow);

int splitOneRow(unsortMovie **unsortMovies, int currRowNum);

void deleteSpaces(char *oneRow);

void formatQuotesFileds(char *oneRow);

void deleteComma(char *subString);

char **rowIntoFields(char *oneRow);

void checkFirstField(char *tmpString);

void removeFirst(char *str, const char *toRemove);

int checkFieldExistence(unsortMovie **unsortMovies, char *sortField, int *sortFieldToInt);

void delCarriageReturn(char *str);

void freeStructArray(unsortMovie **unsortMovies);

void excludeFirstStruct(unsortMovie **unsortMovies, unsortMovie **preSortMovies, int totalRow);
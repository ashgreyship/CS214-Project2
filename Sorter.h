typedef struct movie {
    char **aRowfieldsArray;
    char *aRowString;
} unsortMovie;


int storeRows(char *CSVPath, unsortMovie **unsortMovies, int *totalRow);

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

void
printSortedMovies(char *fileWithoutExtension, char *sortField, unsortMovie **unsortMovies, unsortMovie **preSortMovies,
                  int totalRow, char *outputDir);

void excludeFirstStruct(unsortMovie **unsortMovies, unsortMovie **preSortMovies, int totalRow);

void readDirectory(char *inputDir, char *outputDir, int indent, char *sortField);

int multiSort(char *CSVPath, char *sortField, char *outputDir);

void removefileNameExtension(char *fileName, char *fileWithoutExtension);

void formatOutputNameinDir(char *new_str, char *filenameWithoutExtension, char *field, char *directoryName);

void formatOutputNameinCurrDir(char *new_str, char *filenameWithoutExtension, char *field);
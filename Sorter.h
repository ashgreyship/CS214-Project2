typedef struct movie {
    char **aRowfieldsArray;
    char *aRowString;
} unsortMovie;


int storeRows(unsortMovie **unsortMovies, int *totalRow);

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

void printSortedMovies(unsortMovie **unsortMovies, unsortMovie **preSortMovies,int totalRow);

void excludeFirstStruct(unsortMovie **unsortMovies, unsortMovie **preSortMovies, int totalRow);

void readDirectory(char *inputDir, int parentPID, int totalPro, int indent);
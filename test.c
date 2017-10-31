#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include "Sorter.h"
#include <sys/mman.h>
#include <limits.h>

int main() {
   DIR *dir;
    struct dirent *dp;
    dir = opendir("testDir");

    FILE *fptr;
    fptr=fopen("abbd.txt","w");
    fprintf(fptr,"%s","abdd");
    fclose(fptr);

    closedir(dir);
    return (0);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include <dirent.h>
#include <sys/mman.h>
#include <sys/stat.h>

//
//int main() {
//    printf("Hello\n");
//    int parentPID=getpid();
//    int status;
//    int totalProcess=1;
//    pid_t pid = fork();
//
//    if (pid < 0)
//        printf("error");
//    else if (pid == 0) {
//        printf("This is a child process.\n");
//        totalProcess++;
//
//    } else {
//        printf("This is a parent process.\n");
//
//    }
//
//
//    if(parentPID==getpid()){
//        wait(&totalProcess);
//        printf("pid:%d",totalProcess/255);
//    }
//    return totalProcess;
//}



void main()
{
    FILE *fptr;
    char name[20]="davaf";
    int age=12;
    float salary=12.32;

    /*  open for writing */
    struct stat st = {0};

    if (stat("testFolder", &st) == -1) {
        mkdir("testFolder", 0700);
    }else{
        printf("failed to create a folder");
    }


    fptr = fopen("testFolder/emp.csv", "w");



    fprintf(fptr, "Name  = %s\n", name);


    fprintf(fptr, "Age  = %d\n", age);


    fprintf(fptr, "Salary  = %.2f\n", salary);

    fclose(fptr);
}
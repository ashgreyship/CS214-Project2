#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include <dirent.h>

int main() {
    printf("Hello\n");
    int status;
    int totalProcess=1;
    pid_t pid = fork();

    if (pid < 0)
        printf("error");
    else if (pid == 0) {
        printf("This is a child process.\n");
        totalProcess++;

    } else {
        printf("This is a parent process.\n");
        wait(&totalProcess);
        printf("pid:%d",totalProcess/255);
    }

    return totalProcess;
}




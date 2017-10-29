#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

int main() {
    printf("Hello\n");
    int status;
    pid_t pid = fork();

    if (pid < 0)
        printf("error");
    else if (pid == 0) {
        printf("This is a child process.\n");
    } else {
        printf("This is a parent process.\n");
        waitpid(pid, &status, WUNTRACED);
    }
    return 0;
}
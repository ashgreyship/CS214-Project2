#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include <dirent.h>
#include <sys/mman.h>
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




static int *glob_var;

int main(void)
{
    glob_var = mmap(NULL, sizeof *glob_var, PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    *glob_var = 1;

    if (fork() == 0) {
        *glob_var = 5;
        exit(EXIT_SUCCESS);
    } else {
        wait(NULL);
        printf("%d\n", *glob_var);
        munmap(glob_var, sizeof *glob_var);
    }
    return 0;
}

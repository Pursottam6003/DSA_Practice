#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// #include <sys/wait.h>
#define _XOPEN_SOURCE 600
int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        printf("In child process\n");
        /* code to play animated GIF file */
    }
    else
    {
        printf("In parent process\n");
        /* code to copy file */
    }
}

// int main()
// {
//     int pid;
//     pid = fork();
//     if (pid == 0)
//     {
//         printf("In child process\n");
//         /* code to play animated GIF file */
//     }
//     else
//     {
//         printf("In parent process\n");
//         /* code to copy file */
//     }
// }
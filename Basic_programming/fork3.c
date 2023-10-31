#include <stdio.h>
#include <unistd.h>

int main()
{
    int a;
    pid_t b;
    b = fork();
    printf("HELLO");
    if (b == 0)
    {
        printf("child");
    }
    else
    {
        printf("parent");
    }
}
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf("Before fork\n");
    fork();
    printf("After fork\n");
    return 0;
}


// Before Forking
// After Forking
// After Forking (Child)
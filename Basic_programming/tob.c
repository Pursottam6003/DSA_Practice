#include <stdio.h>

int tob(int b, int *arr)
{
    int i;
    for (i = 0; b > 0; i++)
    {
        if (b % 2)
            arr[i] = 1;
        else
            arr[i] = 0;
        b = b / 2;
    }
    return (i);
}

int pp(int a, int b)
{
    int arr[20];
    int i, tot = 1, ex, len;
    ex = a;
    len = tob(b, arr);
    for (i = 0; i < len; i++)
    {
        if (arr[i] == 1)
            tot = tot * ex;
        ex = ex * ex;
    }
    return (tot);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", pp(3, 4));
    return 0;
}
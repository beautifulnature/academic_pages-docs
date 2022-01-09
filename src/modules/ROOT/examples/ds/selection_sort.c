#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, j, n, a[30];
    printf("Enter total elements:\n");
    scanf("%d", &n);
    printf("enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("after sorting is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    return 0;
}

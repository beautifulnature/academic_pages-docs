#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, a[30], i, j;
    printf("Enter total elements:\n");
    scanf("%d", &n);
    printf("enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n; i++)
    {
        j = i;
        while (a[j] < a[j - 1])
        {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }

    printf("after sorting is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    return 0;
}

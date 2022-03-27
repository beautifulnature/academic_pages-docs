#include <stdio.h>

void quicksort(int a[25], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (a[i] <= a[pivot] && i < last)
            {
                i++;
				printf("i = %d\n", j);
            }
            while (a[j] > a[pivot])
            {
                j--;
				printf("j = %d\n", j);
            }
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quicksort(a, first, j - 1);
        quicksort(a, j + 1, last);
    }
}

int main(int argc, char const *argv[])
{
    int n, a[25];
    printf("Enter total elements:\n");
    scanf("%d", &n);
    printf("enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}

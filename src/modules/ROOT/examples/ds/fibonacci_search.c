#include <stdio.h>

int min(int a, int b)
{
    return a <= b ? a : b;
}

int fibonacci_search(int arr[], int x, int n)
{
    int a = 0, b = 1, c = a + b;
    while (c < n)
    {
        a = b;
        b = c;
        c = a + b;
    }

    int offset = -1;
    while (c > 1)
    {
        int i = min(offset + a, n - 1);
        if (x > arr[i])
        {
            c = b;
            b = a;
            a = c - b;
            offset = i;
        }
        else if (x < arr[i])
        {
            c = a;
            b = b - a;
            a = c - b;
        }
        else
            return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    printf("enter an element to search:\n");
    scanf("%d", &x);
    int s = fibonacci_search(arr, x, n);
    if (s == -1)
        printf("element not found\n");
    else
        printf("element found at index %d\n", s);
    return 0;
}

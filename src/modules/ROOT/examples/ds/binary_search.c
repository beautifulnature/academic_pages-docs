#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numberOfElements, searchElement, i, a[100], first, last, middle;
    printf("Enter number of elements:\n");
    scanf("%d", &numberOfElements);
    printf("Enter elements in ascending order:\n");
    for (i = 0; i < numberOfElements; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter an element to search:\n");
    scanf("%d", &searchElement);
    first = 0;
    last = numberOfElements - 1;
    middle = (first + last) / 2;
    while (first <= last)
    {
        if (a[middle] == searchElement)
        {
            printf("Element found at location %d\n", middle);
            break;
        }
        else if (a[middle] < searchElement)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }
    if (first > last)
    {
        printf("Element not found\n");
    }
    return 0;
}

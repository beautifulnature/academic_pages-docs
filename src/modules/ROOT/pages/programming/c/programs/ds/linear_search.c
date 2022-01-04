#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, numberOfElements, array[100], search;
    printf("Enter the number of elements: \n");
    scanf("%d", &numberOfElements);
    printf("Enter the elements: \n");
    for (int i = 0; i < numberOfElements; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the element to be searched: \n");
    scanf("%d", &search);
    for (i = 0; i < numberOfElements; i++)
    {
        if (array[i] == search)
        {
            printf("Element found at index %d\n", i);
            break;
        }
    }
    if (i == numberOfElements)
    {
        printf("Element not found\n");
    }
    return 0;
}

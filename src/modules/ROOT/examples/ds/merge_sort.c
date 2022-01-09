#include <stdio.h>

int n, inputArray[30], sortedArray[30];

void merge(int low, int mid, int high)
{
    int list1_i = low;
    int list2_i = mid + 1;
    int sortArrayList_i = low;

    while (list1_i <= mid && list2_i <= high)
    {
        if (inputArray[list1_i] <= inputArray[list2_i])
        {
            sortedArray[sortArrayList_i] = inputArray[list1_i];
            list1_i++;
        }
        else
        {
            sortedArray[sortArrayList_i] = inputArray[list2_i];
            list2_i++;
        }
        sortArrayList_i++;
    }
    if (list1_i > mid)
    {
        while (list2_i <= high)
        {
            sortedArray[sortArrayList_i] = inputArray[list2_i];
            list2_i++;
            sortArrayList_i++;
        }
    }
    else
    {
        while (list1_i <= mid)
        {
            sortedArray[sortArrayList_i] = inputArray[list1_i];
            list1_i++;
            sortArrayList_i++;
        }
    }
    for (int i = low; i <= high; i++)
    {
        inputArray[i] = sortedArray[i];
    }
}

void merge_sort(int low, int high)
{
    int mid;
    if (low < high)
    {
        // Step 2: Divide the list recursively into two halves till the size becomes one.
        mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main(int argc, char const *argv[])
{
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inputArray[i]);
    }
    merge_sort(0, n - 1);
    printf("Sorted array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", inputArray[i]);
    }
    return 0;
}

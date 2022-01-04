// Radix Sort in C Programming

#include <stdio.h>

// Print an array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// Function to get the largest element from an array
int getMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

// Using counting sort to sort the elements in the basis of significant places
int *countingSort(int array[], int size, int place)
{
    // Step 1 - Define 10 queues each represents a bucket for digits from 0 to 9.
    int count[10] = {0};

    // Step 3 - Insert each number into respective queue based on the least significant digit.
    for (int i = 0; i < size; i++)
    {
        // Take out place digit from the number
        int digit = (array[i] / place) % 10;
        // Increment the count of that digit
        count[digit]++;
    }
    printArray(count, 10);

    // Step 4 - Group all the numbers from queue 0 to 9 in the order they have inserted into their respective queues.
    // Step 4.1 - Update each digit index position.
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    printArray(count, 10);

    // Step 4.2 - Copy the numbers from queue 0 to 9 to the output array in the order they have inserted into their respective queues.
    int output[size];
    for (int i = size - 1; i >= 0; i--)
    {
        int countArrayPos = (array[i] / place) % 10;
        output[count[countArrayPos] - 1] = array[i];
        count[countArrayPos]--;
    }

    // Copy the numbers from output array to the original array.
    for (int i = 0; i < size; i++)
        array[i] = output[i];

    return array;
}

// Main function to implement radix sort
void radixsort(int array[], int size)
{
    // Get maximum element
    int max = getMax(array, size);

    // Step 2 - Consider the least significant digit of every number in the list which is to be sorted.
    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
    {
        countingSort(array, size, place);
        printArray(array, size);
    }
}

// Driver code
int main()
{
    int array[] = {12, 13, 52, 10, 45, 62, 18, 27, 49, 20};
    int n = sizeof(array) / sizeof(array[0]);
    printf("\nOriginal Array : \n");
    printArray(array, n);
    radixsort(array, n);
    printf("\nDistributed Sort Array : \n");
    printArray(array, n);
}

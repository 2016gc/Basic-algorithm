#include <stdio.h>

void printArray(int array[], int start, int end)
{
    int i = start;
    for(i = start; i <= end; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\r\n");
}

void exchange(int array[], int i, int j)
{
    if(i != j)
    {
        array[i] = array[i]^array[j];
        array[j] = array[i]^array[j];
        array[i] = array[i]^array[j];
    }
    return;
}

int PARTITION(int array[], int start, int end)
{
    int i = start - 1;
    int j = start;
    
    for(; j <= end - 1; j++)
    {
        if(array[j] <= array[end])
        {
            i++;
            exchange(array, i, j);
        }
    }
    exchange(array, i + 1, end);
    return i + 1;
}

void QUICK_SORT(int array[], int start, int end)
{
    int mid;
    if(start < end)
    {
        mid = PARTITION(array, start, end);
        QUICK_SORT(array, start, mid - 1);
        QUICK_SORT(array, mid + 1, end);
    }
    return;
}

int main(void) { 
    int arrayA[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int arrayB[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrayC[10] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    
    QUICK_SORT(arrayA, 0, 9);
    printArray(arrayA, 0, 9);
    
    QUICK_SORT(arrayB, 0, 9);
    printArray(arrayB, 0, 9);
    
    QUICK_SORT(arrayC, 0, 9);
    printArray(arrayC, 0, 9);
    return 0;
}

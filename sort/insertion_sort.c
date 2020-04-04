#include <stdio.h>

void printArray(int array[], int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\r\n");
}

void insert(int array[], int start, int end)
{
    int i = 0; /* 数组下标: 已排序好部分的最后一个元素的下标 */
    int j = 0; /* 数组下标: 即将要进行排序的那个元素的数组下标 */
    int key = 0; /* 数组值：即将要进行排序的那个数组元素 */
    
    for(j = start + 1; j <= end; j++)
    {
        i = j - 1; 
        key = array[j];
        
        while(i >= start && array[i] > key)
        {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }
    return;
}

int main()
{
    int array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    insert(array, 0, 9);
    printArray(array, 10);
}

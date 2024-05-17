#include <stdio.h>

/*
* This is a quicksort algorithm.
*
*/
void quicksort(int *array, int length) {
    if (length < 2) return;
int pivot = array[length / 2];
int i, j;
    for (i = 0, j = length - 1; ; i++, j--) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i >= j) break;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
quicksort(array, i);
quicksort(array + i, length - i);
}

int main (){

    int array[] = {3, 5, 2};

    printf("Original array: ");
    for (int i = 0; i < 3; i++)
        printf("%d ", array[i]);
    printf("\n");

    quicksort(array, 3);
    for (int i = 0; i < 3; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}
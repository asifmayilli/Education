#include <iostream>
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    } // i > j

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int main() {

    const int SIZE = 10;

    int array[SIZE] = {54,26,93,17,77,31,44,55,20,-5};
    for(int i = 0; i < SIZE; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout<<"\n\n";
    quickSort(array, 0, SIZE);

    for(int i = 0; i < SIZE; i++)
    {
        std::cout << array[i] << " ";
    }

    return 0;
}

// Sort array using Quick Sort

/*

Different approach: -
1. Let i be at -1 index and j be at 0th index. When jth value is less than pivotIndex, then ++i and swap ith and jth value so that at every iteration of while loop, we place all smaller value than pivotIndex at left place. And when while loop ends, ++i and place pivot element at ith index.
2. After, do this recursively so that both left side and right side of pivot is placed at there correct place. 

*/

#include<iostream>
using namespace std;

void placePivotAtRightPlace(int* arr, int start, int pivotIndex)
{
    if(start >= pivotIndex) return ;
    int i = start-1;
    int j = start;

    while(j < pivotIndex)
    {
        if(arr[j] < arr[pivotIndex]) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivotIndex]);

    placePivotAtRightPlace(arr, start, i-1);
    placePivotAtRightPlace(arr, i+1, pivotIndex);

}
void sortUsingQuickSort(int* arr, int size)
{
    placePivotAtRightPlace(arr, 0, size-1); // Assuming last element as pivot.
}
int main(){
    int arr[] = {7, 4, 3, 5, 8, 1, 3, 0};
    int size = sizeof(arr) / sizeof(int);
    cout << "Before ";
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
    sortUsingQuickSort(arr, size);

    cout << "After ";
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
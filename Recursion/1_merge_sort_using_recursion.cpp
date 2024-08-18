#include<iostream>
using namespace std;

// recursive tree for better understanding.

void Merge(int* arr, int l, int mid, int r, int actualsize) {
    int leftsize = mid-l+1;
    int rightsize = r-mid;

    int *leftarr = new int[leftsize];
    int *rightarr = new int[rightsize];
    int traverse = 0;
    while(traverse < leftsize) {                    // storing left side array in leftarr
        leftarr[traverse] = arr[l+traverse];
        traverse++;
    }
    traverse = 0;
    while(traverse < rightsize) {                   // storing right side array in rightarr
        rightarr[traverse] = arr[mid+1+traverse];
        traverse++;
    }
    int leftptr = 0, rightptr = 0;
    traverse = l;
    while(leftptr < leftsize && rightptr < rightsize) {     // comparing each value of leftarr and rigth arr, and storing the lesser value in actual arr until one of the array is not finished.
        if(leftarr[leftptr] <= rightarr[rightptr]) {
            arr[traverse] = leftarr[leftptr];
            traverse++, leftptr++;
        }
        else {
            arr[traverse] = rightarr[rightptr];
            traverse++, rightptr++;
        }
    }
    while(leftptr < leftsize) {                 // if some elements left in leftarr, then place it in actual array, as they are already sorted so no need to worry:)
        arr[traverse++] = leftarr[leftptr++];
    }
    while(rightptr < rightsize) {               // if some elements left in rightarr, then place it in actual array, as they are already sorted so no need to worry:)
        arr[traverse++] = rightarr[rightptr++];    
    }
}

void mergeSort(int* arr, int l, int r, int actualsize)
{
    if(l >= r) return ;

    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid, actualsize);         // left side array recursive function
    mergeSort(arr, mid+1, r, actualsize);       // right side array recursive function
    Merge(arr, l, mid, r, actualsize);          // As, the last recursive iteration will be when we have both single element in left side and right side array, so we just want to compare and place in actual array. And continue till the actual arr is not sorted.
}

int main(){
    int arr[] = {20, 10, 30, 50, 5, 10};

    int size = sizeof(arr) / sizeof(int);

    cout << "Before" << endl;
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, size-1, size);
    cout << "After" << endl;
    for(int i = 0; i < size; i++) cout << arr[i] << " ";

    return 0;
}


// revision

/*

#include<iostream>
using namespace std;

void Merge(int* arr, int low, int mid, int high) {
    int leftSize = mid-low+1;
    int rightSize = high-mid;

    int leftArr[leftSize], rightArr[rightSize];

    for(int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[low+i];
    }

    for(int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid+1+i];
    }

    int leftptr = 0, rightptr = 0, traverse = low;
    while(leftptr < leftSize && rightptr < rightSize) {
        if(leftArr[leftptr] <= rightArr[rightptr]) {
            arr[traverse++] = leftArr[leftptr++];
        }
        else arr[traverse++] = rightArr[rightptr++];
    }

    while(leftptr < leftSize) {
        arr[traverse++] = leftArr[leftptr++];
    }

    while(rightptr < rightSize) {
        arr[traverse++] = rightArr[rightptr++];
    }
}

void mergeSort(int* arr, int low, int high) {
    if(low >= high) return ;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    Merge(arr, low, mid, high);
}

int main() {
    int arr[] = {3, 2, 5, 4, 7, 6, 1, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n);

    cout << "after sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}

*/
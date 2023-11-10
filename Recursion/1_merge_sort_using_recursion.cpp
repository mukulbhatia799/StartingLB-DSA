#include<iostream>
using namespace std;

void Merge(int* arr, int l, int mid, int r, int actualsize)
{
    int leftsize = mid-l+1;
    int rightsize = r-mid;

    // cout << "leftsize: " << leftsize << endl;   //
    // cout << "rightsize: " << rightsize << endl; //
    // cout << "l: " << l << endl; //
    // cout << "mid: " << mid << endl; //
    // cout << "r: " << r << endl; //

    int *leftarr = new int[leftsize];
    int *rightarr = new int[rightsize];
    int traverse = 0;
    // cout << "leftarr: ";    //
    while(traverse < leftsize)
    {
        leftarr[traverse] = arr[l+traverse];
        // cout << leftarr[traverse] << " "; //
        traverse++;
    }
    // cout << endl;   //
    traverse = 0;
    // cout << "rightarr: ";    //
    while(traverse < rightsize)
    {
        rightarr[traverse] = arr[mid+1+traverse];
        // cout << rightarr[traverse] << " "; //
        traverse++;
    }
    // cout << endl;   //
    int leftptr = 0, rightptr = 0;
    traverse = l;
    while(leftptr < leftsize && rightptr < rightsize)
    {
        if(leftarr[leftptr] <= rightarr[rightptr])
        {
            arr[traverse] = leftarr[leftptr];
            traverse++, leftptr++;
        }
        else {
            arr[traverse] = rightarr[rightptr];
            traverse++, rightptr++;
        }
    }
    while(leftptr < leftsize)
    {
        arr[traverse++] = leftarr[leftptr++];
    }
    while(rightptr < rightsize)
    {
        arr[traverse++] = rightarr[rightptr++];    
    }
}

void mergeSort(int* arr, int l, int r, int actualsize)
{
    if(l >= r) return ;

    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid, actualsize);
    mergeSort(arr, mid+1, r, actualsize);
    Merge(arr, l, mid, r, actualsize);
    // cout << "arr after iteration: ";    //
    // for(int i = 0; i < actualsize; i++) cout << arr[i] << " ";  //
    // cout << endl << endl;   //
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
    cout << endl;

    return 0;
}
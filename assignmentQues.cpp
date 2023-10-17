// // sort colors - implemented using 3 pointers approach.
#include<bits/stdc++.h>
using namespace std;
// eg:  2 1 0 2 2 1 0 0 2 0 0
void sortColorsInPlace(int arr[], int n)
{
    int low = 0, mid = 0, high = n-1;
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        } 
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sortColorsInPlace(arr, n);

    cout << "after sorting: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
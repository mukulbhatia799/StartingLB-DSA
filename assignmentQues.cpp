// reverse an array.

#include<iostream>
using namespace std;

void reverseAnArray(int arr[], int n)
{
    for(int i = 0; i < n/2; i++)
    {
        swap(arr[i], arr[n-i-1]);
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

    reverseAnArray(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }    

    return 0;
}
// move all -ve number to the left side of an array.
#include<bits/stdc++.h>
using namespace std;

void moveAllNegativeNumberToLeft(int arr[], int n)
{
    int ptr = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < 0) {
            swap(arr[i], arr[ptr]);
            ptr++;
        }
    }
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    moveAllNegativeNumberToLeft(arr, n);

    cout << "After func. call: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";


    return 0;
}
// find pivot index:- find the index where the exact left and exact right sum is equal without including the pivot index.
// If pivot index not found than return -1.
#include<bits/stdc++.h>
using namespace std;

int findPivotIndex(int arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int leftsum = 0, rightsum = sum;
    for(int i = 0; i < n; i++)
    {
        if(i > 0) {
            leftsum += arr[i-1];
        }
        rightsum -= arr[i];
        if(leftsum == rightsum) return i;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = findPivotIndex(arr, n);

    cout << ans << endl;

    return 0;
}
// min number in a sorted array.

#include<iostream>
#include<climits>
using namespace std;

int findMinEle(int arr[], int n)
{
    int x = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        x = min(arr[i], x);
    }
    return x;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Min value in list: " << findMinEle(arr, n) << endl;

    return 0;
}
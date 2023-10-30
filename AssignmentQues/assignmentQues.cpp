#include<iostream>
#include<climits>
using namespace std;

void maxSubArray(int arr[], int n)
{
    int sum = 0;
    int maxsum = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        sum = max(arr[i], arr[i]+sum);
        maxsum = max(maxsum, sum);
    }
    cout << "Max subarray sum is " << maxsum << endl;
}

int main(){

    int arr[8]={-1, -2, -8, -3, -6, -8, -5, -8};
    int n = 8;

    maxSubArray(arr, n);

    return 0;
}

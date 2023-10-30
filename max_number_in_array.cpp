#include<iostream>
using namespace std;

int maxNumber(int arr[], int n)
{
    static int ans = 0;
    if(n == -1) return ans;

    ans = max(ans, arr[n]);
    return maxNumber(arr, n-1);
}

int main(){
    int n = 5;

    int arr[n]={10, 30, 90, 401, 5};

    cout << "Max number is " << maxNumber(arr, n-1);

    return 0;
}
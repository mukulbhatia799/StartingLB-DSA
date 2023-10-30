#include<iostream>
using namespace std;

int listIntoNumber(int* arr, int n, int i)  // or we can call ans in this function by call by reference and store answer in it.
{
    static int ans = 0;
    if(n == -1) return ans;
    ans += arr[n]*i;
    listIntoNumber(arr, n-1, i*10);
}

int main() {
    int n = 5;
    int arr[]={1, 4, 5, 6, 9}; // answer should be 14569 integer value.

    int ans = listIntoNumber(arr, n-1, 1);
    cout << "Number is " << ans << endl;

    return 0;
}
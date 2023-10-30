#include<iostream>
using namespace std;

void printIndex(int arr[], int n, int k)
{
    if(n == -1) return ;
    printIndex(arr, n-1, k);
    if(arr[n] == k)                 // written after recursive function because we want to print the indexes in 0 to n order.
    {
        cout << "found at " << n << endl;
    }
}

int main() {
    int n = 8;
    int k;
    cout << "Enter the element to find it's occ. indexes:";
    cin >> k;
    int arr[n] = {10, 30, 20, 10, 40, 30, 10, 20};

    printIndex(arr, n-1, k);

    return 0;
}
#include<iostream>
using namespace std;

int findele(int* arr, int n, int k)
{
    if(n == -1) return -1;
    if(arr[n] == k)
        return n;
    
    return findele(arr, n-1, k);
}

int main(){
    int n = 5;
    int k;
    cin >> k;
    int arr[n]={10, 20, 30, 40, 50};

    int index = findele(arr, n-1, k);

    if(index == -1) cout << "Element not found.";
    else 
        cout << "Element found at index " << index << endl;

    return 0;
}
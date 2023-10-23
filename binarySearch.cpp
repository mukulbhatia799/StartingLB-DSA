/*
    find the odd occuring element in array.
    eg: 2 4 5 4 2. Here the odd occuring element is 5 because it is occuring 1 time and 1 is odd.

*/

#include<iostream>
using namespace std;

int FindOddOccElement(int* arr, int n)
{
    int XOR = 0;
    for(int i = 0; i < n; i++)
    {
        XOR = XOR ^ arr[i];
    }
    return XOR;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ele = FindOddOccElement(arr, n);

    if(ele != -1) 
        cout << "Odd times occuring element is " << ele << endl;
    else 
        cout << "Odd occuring element not found!" << endl;

    return 0;
}
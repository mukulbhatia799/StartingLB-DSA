// right shift an array by 1.
// input:  1 2 3 4 5 6
// output: 6 1 2 3 4 5
#include<iostream>
using namespace std;

void rightShiftAnArrayBy1(int arr[], int n)
{
    int left = 0, right = n-2;
    // first swap the elments from 0th to n-1 elements.
    while(left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    // now, reverse the array
    left = 0, right = n-1;
    while(left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    cout << "input array: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    rightShiftAnArrayBy1(arr, n);

    cout << "After shifting: "; 
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
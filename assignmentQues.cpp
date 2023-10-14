// right shift an array by k.
// input:  1 2 3 4 5 6
// k = 3
// output: 4 5 6 1 2 3
#include<iostream>
using namespace std;

void rightShiftByKElements(int arr[], int n, int k)
{
    k = k % n;      // this statment will be beneficial when the number of shift is greater than the number of elements because w know that after every n rounds the array will be as same as know. so, thatswhy we are taking mod of that k number.

    // reverse the left array.
    int left = 0, right = n - k - 1;
    while(left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    // reverse the right array
    left = n - k, right = n-1;
    while(left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    // reverse the whole array
    left = 0, right = n-1;
    while(left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    int arr[n];
    cout << "input array: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    rightShiftByKElements(arr, n, k);

    cout << "After shifting: "; 
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
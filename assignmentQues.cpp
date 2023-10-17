// remove duplicates from sorted array using two pointers approach.
/*

Method->(two pointers appraoch): First pointer will point till the unique elements 
and second pointer will traverse to the whole array in each itertion and check whether 
the second pointer element is equal to first pointer element or not. If not then first++ then swap and then second++;
Time Complexity: O(n)       Space Complexity: O(1).


*/
#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n)
{
    int ptr1 = 0, ptr2 = 1;
    while(ptr2 < n)
    {
        if(arr[ptr2] != arr[ptr1])  // here 
        {
            // ptr1++;
            // swap(arr[ptr1], arr[ptr2]);
            // ptr2++;
            swap(arr[++ptr1], arr[ptr2++]); // prev. 3 lines of code in just one line. ptr1 should be pre increment first, and ptr2 should be post increment means first the ptr2 value is store as index in arr and after swapping then the ptr2 value is updated to +1.
        }
        else ptr2++;
    }
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int k = removeDuplicates(arr, n);       // return the index till all elements are unique.

    cout << "After removing duplicates: ";
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';

    return 0;
}
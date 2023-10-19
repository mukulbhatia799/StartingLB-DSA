// Find Peak Index in a Mountain Array.
// leetcode problem

/*

    This ques can be done using linear search with Time Complexity O(n).
    But using binary search we can solve this ques in O(logn) time complexity.

    ***The key point in this ques is that first the array will be in increasing order
    and after the peak index it starts decreasing.***

    So, the intution is when the arr[mid] element is greater than its next element, 
    move high = mid;


    **extra**   When low and high diff. is 1 then mid = (low+high)/2 = low.

*/

#include<iostream>
#include<climits>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<iomanip>

using namespace std;


int findPeakElementIndex(int* arr, int n)
{
    int low = 0, high = n-1;
    int mid;
    while(low < high)           // We will not take low <= high because last element will be our peak element.
    {
        mid = low + (high - low) / 2;   // same as mid = (low + high) / 2;
        cout << "low: " << low << " high: " << high << " mid: " << mid << endl;
        if(arr[mid] < arr[mid+1])
        {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return low;
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    int index = findPeakElementIndex(arr, n);
    cout << "peak element index: " << arr[index] << endl;
    
    return 0;
}
// find the pivot index in rotated and sorted array means from where the sorted array break or last sorted element.
// eg: 50 60 10 20 30 40
#include<iostream>
using namespace std;

/* 
using binary search algorithm we can solve this ques in O(logn) time complexity.
Approach is first store the greater element from 0th and (n-1)th index in ans variable and then apply binary search.
*/
int findPivotIndex(int* arr, int n)
{
    int low = 0, high = n-1;
    int ans = (arr[0] > arr[n-1])? arr[0] : arr[n-1];
    while(low < high)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] > arr[mid-1]) 
        {
            ans = max(ans, arr[mid]);
            low = mid + 1;
        }
        else {
            ans = max(ans, arr[mid-1]);
            break;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans = findPivotIndex(arr, n);

    cout << "pivot element is " << ans << endl;

    return 0;
}
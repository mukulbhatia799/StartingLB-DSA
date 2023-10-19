// find first occurence of a number in sorted array.

// As sorted array is given, so we can use binary search here.

#include<iostream>
using namespace std;

int findFirstOccOfK(int arr[], int n, int k)
{
    int low = 0, high = n-1, ans = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == k)
        {
            high = mid-1;
            ans = mid;
        }
        else if(arr[mid] > k) high = mid-1;
        else low = mid+1;
    }
    return ans;
}
// 5 5 5 5 5 5 5 8

int main(){
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0;i < n; i++) cin >> arr[i];
    int indexOfK = findFirstOccOfK(arr, n, k);
    if(indexOfK == -1) cout << "k value not found." << endl;
    else cout << "First occ of k found at index " << indexOfK << endl;

    return 0;
}
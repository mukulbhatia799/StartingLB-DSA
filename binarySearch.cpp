// find total occurence of a number in sorted array.

// As sorted array is given, so we can use binary search here.

/*
    To find total occurence, if we Know the first and last occ. then we can subt.
    the indexes of first and last occ. to know the total occ. of K.
*/

#include<iostream>
using namespace std;

int findLastOccOfK(int *arr, int n, int k)
{
    int low = 0, high = n-1, ans = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2; 
        if(arr[mid] == k)
        {
            low = mid+1;
            ans = mid;
        }
        else if(arr[mid] > k) high = mid-1;
        else low = mid+1;
    }
    return ans;
}

int findFirstOccOfK(int *arr, int n, int k)
{
    int low = 0, high = n-1, ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == k)
        {
            ans = mid;
            high = mid - 1;
        }
        else if(arr[mid] > k) high = mid - 1;
        else low = mid + 1;
    }
    return ans;
}

int findTotalOccOfK(int *arr, int n, int k)
{
    int firstIndex = findFirstOccOfK(arr, n, k);
    int lastIndex = findLastOccOfK(arr, n, k);

    if(firstIndex == -1) return -1;
    
    return lastIndex-firstIndex+1;
}

int main(){
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0;i < n; i++) cin >> arr[i];
    int indexOfK = findTotalOccOfK(arr, n, k);
    cout << "Total occ. of k variable is ";
    if(indexOfK == -1) cout << 0 << endl;
    else cout << indexOfK << endl;

    return 0;
}
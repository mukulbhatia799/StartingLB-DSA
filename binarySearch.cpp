// find missing element in a sorted array.
// Elements range is [1, N].

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

/*

   eg: 1 2 3 4 6 7 8 9
index: 0 1 2 3 4 5 6 7
As we can see, each value should be at element-1 index. So we just have to check 
from where the element and its index difference are not 1.

*/
int findMissingElement(int* arr, int n)
{
    int low = 0, high = n-1, ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid]-mid != 1)
        {
            ans = mid+1;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    int n = 8;
    int arr[n]={1, 2, 3, 4, 6, 7, 8, 9};    // Here missing element is 5.

    int missingele = findMissingElement(arr, n);

    if(missingele == -1) cout << "Missing element not found" << endl;
    else cout << "Missing element is " << missingele << endl;
    
    return 0;
}
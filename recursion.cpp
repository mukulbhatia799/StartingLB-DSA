// find min in array recursively.

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

int minNoInArray(int* arr, int n, int &minNumber)
{
    cout << "min: " << minNumber << " " << "arr[i]: " << arr[n] << endl;
    minNumber = min(minNumber, arr[n]);
    if(n == 0) 
        return minNumber;
    minNoInArray(arr, n-1, minNumber);
}


int main(){
    int n = 5;
    int arr[n]={1, 20, 5, 40, 20};

    int ans = INT_MAX;
    minNoInArray(arr, n-1, ans);        // storing answer in ans variable.
    cout << "Min number in array is " << ans << endl;
    
    return 0;
}
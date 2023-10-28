// Search in array recursively.

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

bool searchRecursively(int* arr, int n, int target)
{
    if(arr[n] == target)
    {
        return true;
    }
    if(n == 0) return false;

    searchRecursively(arr, --n, target);
}

int main(){
    int n = 5, target;
    int arr[n]={10, 20, 30, 40, 50};
    cout << "Enter target value: ";
    cin >> target;

    if(searchRecursively(arr, n-1, target)) cout << "Value found" << endl;
    else cout << "value not found" << endl;
    
    return 0;
}
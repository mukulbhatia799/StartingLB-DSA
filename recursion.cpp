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

void recursive(int arr[], int n)
{
    if(n == 0) return ;
    recursive(arr, --n);
    cout << arr[n] << " ";
}

int main(){
    int arr[5]{1, 2, 3, 4, 5};

    int n = sizeof(arr) / sizeof(int);
    recursive(arr, n);
    
    return 0;
}
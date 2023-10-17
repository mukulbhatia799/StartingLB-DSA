// missing number in an array where elements in the range [0, n].
#include<bits/stdc++.h>
using namespace std;

int main(){
    // int arr[]={1, 3, 2};
    // int arr[]={0, 3, 2, 4};
    int arr[]={0, 4, 2, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = size*(size+1) / 2;

    for(int i = 0; i < size; i++)
    {
        sum -= arr[i];
    }

    cout << "Missing value is " << sum << endl;


    return 0;
}
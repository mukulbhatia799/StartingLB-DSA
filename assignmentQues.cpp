// expreme print in an array.
// eg: 10 20 30 40 50 60.
// output:- 10 60 20 50 30 40.

#include<iostream>
using namespace std;

void extremePrint(int arr[], int n)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        if(low == high) {
            cout << arr[low] << endl;
            return ;
        }
        cout << arr[low] << " ";
        cout << arr[high] << " ";
        low++;
        high--;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    cout << "new array: " << endl;
    extremePrint(arr, n); 

    return 0;
}
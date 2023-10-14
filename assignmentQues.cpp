// find unique element in an array(where all elements have 1 occurence except 1 element. Find that element.).

#include<iostream>
using namespace std;

int findUnique(int arr[], int n)
{
    int XOR = 0;
    for(int i = 0; i < n; i++)
    {
        XOR ^= arr[i];
    }
    return XOR;
}

int main(){
    int n;  // n should be odd as 2*(number of occ.) + 1 unique element.
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int unique = findUnique(arr, n);
    cout << "unique element is " << unique << endl;

    return 0;
}
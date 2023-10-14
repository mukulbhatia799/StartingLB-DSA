#include<iostream>
using namespace std;

void printAllPermutations(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << "{" << arr[i] << ", " << arr[j] << "}" << endl;
        }
        cout << endl;
    }
}

int main(){
    int arr[]={10, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    printAllPermutations(arr, n);

    return 0;
}
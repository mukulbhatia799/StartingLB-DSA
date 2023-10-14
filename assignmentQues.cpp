#include<iostream>
using namespace std;

void printTripletPermutations(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                cout << "{" << arr[i] << ", " << arr[j] << ", " << arr[k] << "} ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    printTripletPermutations(arr, n);


    return 0;
}
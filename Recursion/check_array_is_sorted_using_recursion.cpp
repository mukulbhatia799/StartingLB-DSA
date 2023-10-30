#include<iostream>
using namespace std;

void checkSorted(int* arr, int n)
{
    if(n == 0)
    {
        cout << "Array is sorted" << endl;
        return ;
    }
    if(arr[n] < arr[n-1]) {
        cout << "Array is not sorted" << endl;
        return ;
    }
    checkSorted(arr, n-1);
}

int main(){
    int n = 5;
    int arr[n] = {10, 20, 0, 40, 50};

    checkSorted(arr, n-1);

    return 0;
}
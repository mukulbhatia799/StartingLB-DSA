#include<iostream>
using namespace std;

int main(){
    int arr[] = {8, 2, 9, 3, 10, 6};

    int size = sizeof(arr) / sizeof(int);

    int slar = 0, lar = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > lar)
        {
            slar = lar;
            lar = arr[i];
        }
        if(arr[i] > slar && arr[i] < lar)
        {
            slar = arr[i];
        }
    }
    cout << "second largest: " << slar << endl;

    return 0;
}
#include<iostream>
using namespace std;

void findTarget(int* arr, int low, int high, int target)
{
    if(low > high) 
    {
        cout << "Target not found" << endl;
        return ;
    }
    int mid = low + (high - low)/2;
    if(arr[mid] == target) {
        cout << "Target found at index: " << mid << endl;
        return ;
    }
    else if(arr[mid] > target) high = mid - 1;
    else low = mid + 1;

    findTarget(arr, low, high, target);
}

int main(){
    int target;
    cout << "Enter target value: ";
    cin >> target;
    int n = 5;
    int arr[] = {10, 20, 30, 40, 50};

    findTarget(arr, 0, n-1, target);

    return 0;
}
// sort 0's and 1's

#include<iostream>
using namespace std;

void sort0sand1s(int arr[], int n)
{
    // using 2 pointers approach.
    int left = 0, right = n-1;
    while(left <= right)
    {
        while(left <= right)    // loop till 1 is not found from left.
        {
            if(arr[left] == 1) break;
            left++;
        }
        while(right >= left)    // loop till 0 is not found from right.
        {
            if(arr[right] == 0) break;
            right--;
        }
        if(arr[left] == 1 && arr[right] == 0)   // check whether on both side we found 0 and 1 or not.
        {
            swap(arr[left], arr[right]);    
        }
        left++;
        right--;    // As, current left and right pointer indexes are swapped. So just increment and decrement the pointers.
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sort0sand1sInNcomplexity(int arr[], int n)
{
    int count1s = 0;    // just count the number of occ. of 1s in an array and write those number of 1s at the last of the array.
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 1) count1s++;
    }
    for(int i = 0; i < n-count1s; i++)
    {
        cout << 0 << " ";
    }
    for(int i = 0; i < count1s; i++)
    {
        cout << 1 << " ";
    }
}

int main(){
    int n; 
    cin >> n;

    int arr[n];
    cout << "Enter only 0's and 1's: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort0sand1s(arr, n);
    // sort0sand1sInNcomplexity(arr, n);

    return 0;
}



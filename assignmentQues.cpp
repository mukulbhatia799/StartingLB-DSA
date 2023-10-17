// ques link: https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1

#include<bits/stdc++.h>
using namespace std;

int firstRepeatingElement(int arr[], int n)
{
    unordered_map<int, int> mpp;

    for(int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for(int i = 0; i < n; i++)
    {
        if(mpp[arr[i]] > 1) return i+1;
    }

    return -1;  // If none of the values is repeating.
}

int main(){
    int n = 7;

    int arr[n] = {1, 5, 3, 4, 3, 5, 6};

    int index1based = firstRepeatingElement(arr, n);

    cout << "Index of the first repeating element: " << index1based << endl;

    return 0;
}
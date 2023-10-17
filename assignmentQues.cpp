// Missing elements from an array with duplicates. Range of elements is [0, N].
/*
Arroach 1: 
We can name this approach as index as elements.
Range of elements is   [1, N]    thaswhy we can use indexes as elements.
As the index starts from 0 so we have to make element -ve at 
arr[element-1]. We will make the element present in elements 
index as -ve because we are traversing the array so we also need 
the values which will come in the coming iterations. 
In each iteration, we will take the abs of that value because 
the element might be changed to -ve in previous iterations.

Approach 2:
Use elements as index and make the elements index element as -ve. In next loop, find those values which are positive. Positive elements means those elements indexes are not present in array.

Time complexity: O(n)   Space complexity: O(n)
*/

#include<iostream>
#include<vector>
using namespace std;


// Approach 1
vector<int> MissingValueUsingElementsAsIndex(int arr[], int n)
{
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        int index = arr[i]-1;
        if(arr[index] != arr[i]) 
        {
            swap(arr[index], arr[i]);
        }
        else ++i;
    }
    for(int i = 0; i < n; i++) 
    {
        if(arr[i]-1 != i) ans.push_back(i+1);
    }
    
    return ans;
}


// Approach 2: 
vector<int> MissingValueByPlacingElementIndexAsNegative(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int index = abs(arr[i]);    // abs is required the element at ith index might be changed to index during previous iterations.
        if(arr[index-1] > 0) arr[index-1] *= -1;
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) 
    {
        if(arr[i] > 0) ans.push_back(i+1);
    }

    return ans;
}

int main(){
    int n = 5;
    // cin >> n;

    int arr[n]={1, 3, 3, 3, 3};
    // for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans = MissingValueByPlacingElementIndexAsNegative(arr, n);
    // vector<int> ans = MissingValueUsingElementsAsIndex(arr, n);

    cout << "Missing elements: ";
    for(auto it: ans) cout << it << " ";
    cout << endl;

    return 0;
}
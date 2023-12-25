/*
suppose queue is 2 -5 4 -3 -2 8 and K(window size) is 3.
There are n-k+1 windows {2, -5, 4}, {-5, 4, -3}, {4, -3, -2}, {-3, -2, 8}.
So, number of first negative in every window(n-k+1) is -5, -5, -3, -3.
If there is not any negative number in a queue, put 0 for that window.

just take first window separetely because after that all windows will remove the one old element and add one new element so just need to check those element extra.
*/

#include <iostream>
#include <queue>
using namespace std;

void findFirstNegativeInEveryWindow(int *arr, int size, int K)
{
    queue<int> index;

    // for first window
    for (int i = 0; i < K; i++)
    {
        if (arr[i] < 0)
            index.push(i);
    }
    if (!index.empty())
        cout << arr[index.front()] << " "; // if any index with negative element, print it.

    for (int i = K; i < size; i++) // for 2nd window to (size-k+1)th window.
    {
        if (arr[i] < 0)
            index.push(i);
        if (index.front() >= i - K + 1)
            cout << arr[index.front()] << " ";
        else
        {
            index.pop();
            if (index.front() >= i - K + 1)
                cout << arr[index.front()] << " ";
            else
                cout << 0 << " ";
        }
    }
}

int main()
{
    // int arr[] = {2, -5,4, -3, -2, 8};
    int arr[] = {2, -5, 4, -1, -2, 0, 5};
    int size = sizeof(arr) / sizeof(int);

    int K = 3; // number of elements in a window.
    findFirstNegativeInEveryWindow(arr, size, K);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int solve()
{
    // brute force approach - O(n^2) time complexity.
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        bool rowcheck = true;
        bool colcheck = true;
        // check ith row, if all are zeroes then that person can be a celebrity.
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == 1)
            {
                rowcheck = false;
                break;
            }
        }
        if (!rowcheck)
            continue;
        // check ith col, if everyone knows ith person leaving himself then that person is a celebrity.
        for (int j = 0; j < n; j++)
        {
            if (M[j][i] == 0 && i != j)
            {
                colcheck = false;
                break;
            }
        }
        if (rowcheck && colcheck)
            return i;
    }
    return -1;
}

int main()
{
    int ans = solve();

    if (ans == -1)
        cout << "not any celeb" << endl;
    else
        cout << "celeb is " << ans << " index." << endl;

    return 0;
}
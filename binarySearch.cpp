#include<iostream>
#include<climits>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<iomanip>

using namespace std;

void printDiagonals(vector<vector<int>> arr, int size)
{
    int j = 0;
    cout << "1st diagonal: ";
    for(int i = 0; i < size; i++)
    {
        cout << arr[i][i] << " ";
    }
    cout << endl;
    cout << "2nd diagonal: ";
    for(int i = 0; i < size; i++)
    {
        cout << arr[i][size-i-1] << " ";
    }
}


int main(){
    int n;
    cout << "Enter n*n matrix size: ";
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
        }
    }

    printDiagonals(vec,n);
    
    return 0;
}
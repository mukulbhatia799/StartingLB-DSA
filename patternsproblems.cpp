#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 2*(n-1)-i+1; j++)
        {
            cout << "*";
        }
        for(int j = 1; j <= 2*i-1; j++)
        {
            if(j % 2 == 0) cout << "*";
            else cout << i;
        }
        for(int j = 1; j <= 2*(n-1)-i+1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}

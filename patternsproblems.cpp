#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        char c = 'A';
        for(int j = 1; j <= 2*i-1; j++)
        {
            cout << c << " ";
            if(j < (2*i)/2) c++;
            else c--;
        }
        cout << endl;
    }

    return 0;
}

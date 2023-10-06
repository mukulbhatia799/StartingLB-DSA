#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    while(n != 0)
    {
        int mod = n % 10;
        n /= 10;
        cout << mod;
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int count = 0;
    while(n)
    {
        int lastbit = n & 1;
        if(lastbit == 1) count++;
        n = n >> 1;
    }

    cout << count << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int pow2 = 1;
    int ans = 0;
    while(n)
    {
        int checkbit = n & 1;
        if(checkbit == 1 || k == 0) ans += pow2;
        pow2 *= 2;
        n = n >> 1;
        k--;
    }

    cout << ans << endl;

    return 0;
}
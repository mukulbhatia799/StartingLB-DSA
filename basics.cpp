#include<bits/stdc++.h>
using namespace std;

void convertdecimaltobinary(int n)
{
    string ans = "";

    while(n != 0)
    {
        ans = to_string(n%2) + ans;
        n /= 2;
    }
    for(int i = 0; i < ans.length(); i++)
    {
        cout << ans[i];
    }
    cout << endl;
}

int main(){
    
    int n;
    cin >> n;

    convertdecimaltobinary(n);

    return 0;
}

// first make string variable where the bits will be stored.
// add the bit in front of the string using + operator.
// and divide n by 2 in each iteration.
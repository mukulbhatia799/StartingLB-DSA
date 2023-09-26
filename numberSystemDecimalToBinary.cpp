#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void decimaltobinaryconversion(int n)
{
    vector<int> vec;
    while(n != 0)
    {
        int mod = n % 2;
        vec.push_back(mod);
        n /= 2;
    }
    for(int i = vec.size()-1; i >= 0; i--)
    {
        cout << vec[i];
    }
    cout << endl;
}

void binarytodecimalconversion(string s)
{
    int ans = 0;
    for(int i = s.length()-1; i >= 0; i--)
    {
        if(s[i] == '1') 
            ans += pow(2, s.length()-i-1);
    }
    cout << ans << endl;
}

int main(){
    int n;
    cin >> n;

    decimaltobinaryconversion(n);

    string s;
    cin >> s;

    binarytodecimalconversion(s);

    return 0;
}
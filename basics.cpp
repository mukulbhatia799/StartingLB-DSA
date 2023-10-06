#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> vec;
    while(n)
    {
        int mod = n % 10;
        n /= 10;
        vec.push_back(mod);
    }
    cout << "all digits are: ";
    for(int i = vec.size()-1; i >= 0; i--)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}
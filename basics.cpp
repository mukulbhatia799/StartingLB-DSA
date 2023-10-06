#include<bits/stdc++.h>
using namespace std;

int main(){
    int no;
    cout << "Enter number of digits: ";
    cin >> no;

    int j = 0, ans = 0;
    for(int i = 0; i < no; i++)
    {
        int digit;
        cin >> digit;
        ans = ans*10 + digit;
        j++;
    }
    cout << ans << endl;

    return 0;
}
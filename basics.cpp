#include<iostream>
using namespace std;

int main(){
    int n = 10;

    int ans = ++n * n++;

    /*
    first ++n = 11 then * then n++ = 12 so 132 is answer.
    */

    cout << ans << endl;

    return 0;
}
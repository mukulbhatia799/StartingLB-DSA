#include<iostream>
using namespace std;

int main(){

    // remember, the calculation is done from right to left .

    int n = 10;

    int ans;

    cout << ++n * n++ << endl;
    /*
    first ++n = 11 then * then n++ = 12 so 132 is answer.
    */



    // cout << n++ * ++n << endl;
    n = 10;
    // ans = n++ * ++n;

    cout << n++ * ++n << endl;


    /*
    first n++ = 11 then * then ++n = 1
    */

    return 0;
}
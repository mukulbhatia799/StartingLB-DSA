#include<iostream>
using namespace std;

int main(){
    int n = 10;

    /*
    '<<' or '>>' shifts the bits by the given number of times.
    << means left shift.
    >> means right shift.

    if left shift then the number is multiplied by the pow(2, value).
    like (10 << 1) will give ans 10 * 2^1 = 20.
    same as (10 << 3) will give ans 10 * 2^3 = 80.

    
    */

    cout << (n << 1) << endl;   
    cout << (n << 2) << endl;
    cout << (n << 3) << endl;
    cout << (n << 4) << endl;
    cout << (n << 5) << endl;
    cout << (n << 6) << endl;



    return 0;
}

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    // given number is even or odd using bitwise operator.

    if(n & 1) cout << "number is odd. " << endl;
    else cout << "number is even." << endl;

    return 0;
}
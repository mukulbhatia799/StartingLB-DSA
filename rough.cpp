#include<iostream>
using namespace std;

int main(){
    int a;
    cout << a << endl;  // will print garbage value

    static int b;
    cout << b << endl;  // by default, static value is 0.

    return 0;
}
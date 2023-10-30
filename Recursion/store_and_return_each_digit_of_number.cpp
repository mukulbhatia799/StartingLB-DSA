#include<iostream>
#include<vector>
using namespace std;

void returnDigits(int n)    // without storing digits.
{
    if(n == 0) return ;
    int digit = n % 10;
    n /= 10;
    returnDigits(n);
    cout << digit << " ";   // printing after recursive func. to print the digit from start to end order.
}

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;

    returnDigits(n);

    return 0;
}
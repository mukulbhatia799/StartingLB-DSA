// count set bits;

#include<iostream>
using namespace std;

void countSetBits(int n)
{
    int count1 = 0;
    while(n)
    {
        // int bit = n % 2; // if last bit is 1 than store 1.
        int bit = n & 1;    // if last bit is 1 than the bit variable will store 1.
        if(bit == 1) count1++;
        n = n >> 1;
    }
    cout << "Count of set bits in number " << n << " is " << count1 << endl;
}

int main(){
    int n;
    cin >> n;

    countSetBits(n);

    return 0;
}
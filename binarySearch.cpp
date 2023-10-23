/*
Find the integer root of any number.
Eg: root of 45 is 6.X something. But return 6 as answer. root of 63 is 7.X. but return 7 as answer.

approach 1: we run a loop from i=2 to n/2 to find the sq. root of any number. Time complexity is O(n/2) -> O(n).
approach 2: Binary search approach. run a while loop and everytime take mid value of range [2, n/2] then update low and high accordingly. Time Complexity O(logn).
*/ 

#include<iostream>
using namespace std;

void findsquareroot(int n)
{
    int low = 2, high = n/2, ans = -1;
    while(high-low > 1)
    {
        int mid = (low + high)/2;
        if(mid*mid < n) {
            ans = mid;
            low = mid;
        }
        else {
            high = mid;
        }
    }
    if(low*low == n) ans = low;
    else if(high*high == n) ans = high;
    cout << "So root of " << n << " is " << ans << endl;
}

int main(){
    int n;
    cin >> n;

    findsquareroot(n);

    return 0;
}
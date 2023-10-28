// fibonacci series using recursive approach. 
// Time complexity is exponential means O(2^n).
// space complexity is O(n). As maximum depth is o(n).
#include<iostream>
#include<climits>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<iomanip>

using namespace std;

int fib_series_using_recursion(int n)
{
    if(n == 1) return 0;
    if(n == 2) return 1;
    // if(n <= 2) return n-1;
    return fib_series_using_recursion(n-1) + fib_series_using_recursion(n-2);
}

int main(){
    int n;
    cin >> n;

    cout << "nth fib is " << fib_series_using_recursion(n) << endl;
    
    return 0;
}
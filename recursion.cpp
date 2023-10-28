// leetcode: 70 climbing stairs.
// Using recursion, time complexity is O(2^n) but using dp, can be done using O(n).
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int noofsteps(int steps){
    static int count = 0;
    if(steps <= 0)
    {
        if(steps == 0) count++;
        return 0;
    }
    noofsteps(steps-1);
    noofsteps(steps-2);
    return count;
}

int main(){
    int n;
    cin >> n;

    cout << "No. of ways to reach n: " << noofsteps(n) << endl;

    return 0;
}
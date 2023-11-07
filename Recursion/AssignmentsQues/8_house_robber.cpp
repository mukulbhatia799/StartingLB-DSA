// house robber leetcode ques

/*
    Approach: As we can't rob the adjacent house. So, either we can rob current house and move (i+2)th house and rob. or we will not rob current house and start from (i+1)th house.
    Eg: {2, 1, 1, 2}
    In this eg. max rob money will be 4 which we get by robbing the 0th and 3th index houses.

*/


// This ques will give tle using recursion. But can be solved using recursion with better time complexity and will not give tle.

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int robAmount(vector<int>& nums, int i)
{
    // base cond.
    if(i >= nums.size()) return 0;
    // recursive func.
    int amount1 = nums[i] + robAmount(nums, i+2);
    int amount2 = 0 + robAmount(nums, i+1);
    return max(amount1, amount2);
}
int rob(vector<int>& nums) {
    return robAmount(nums, 0);
}

int main(){
    vector<int> vec = {2, 1, 1, 2};

    cout << "Max robbed amount could be " << rob(vec) << endl;

    return 0;
}



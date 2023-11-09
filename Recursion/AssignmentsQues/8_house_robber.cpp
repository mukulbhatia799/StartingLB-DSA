// house robber leetcode ques

/*
    Approach: As we can't rob the adjacent house. So, either we can rob current house and move (i+2)th house and rob. or we will not rob current house and start from (i+1)th house.
    Eg: {2, 1, 1, 2}
    In this eg. max rob money will be 4 which we get by robbing the 0th and 3th index houses.

*/


// This ques will give tle using recursion. But can be solved using recursion with better time complexity and will not give tle.

#include<iostream>
#include<vector>
using namespace std;

int robbingHouse(vector<int> vec, int i)
{
    if(i >= vec.size())
        return 0;
    
    int sum1 = vec[i] + robbingHouse(vec, i+2);

    int sum2 = robbingHouse(vec, i+1);

    return max(sum1, sum2);    
}

int main(){
    vector<int> vec = {2, 4, 1, 2, 4, 1};
    // vector<int> vec = {2, 1, 1, 2};

    cout << "Max amount could be robbed is " << robbingHouse(vec, 0);

    return 0;
}
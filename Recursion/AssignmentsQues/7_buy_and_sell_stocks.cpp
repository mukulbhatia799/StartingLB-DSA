#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void findMaxProfit(vector<int>& prices, int i, int minn, int& maxx)
{
    // base cond.
    if(i == prices.size())
    {
        return ;
    }

    if(prices[i] < minn) minn = prices[i];
    int profit = prices[i] - minn;
    if(profit > maxx) maxx = profit;

    // recursive functon.
    findMaxProfit(prices, i+1, minn, maxx);
}
int maxProfit(vector<int>& prices) {
    int start = 0;
    int minn = INT_MAX;
    int maxx = INT_MIN;
    findMaxProfit(prices, start, minn, maxx);

    return maxx;
}

int main(){
    vector<int> vec = {7,1,5,3,6,4};

    cout << "Max profit using recursion: " << maxProfit(vec);
    

    return 0;
}
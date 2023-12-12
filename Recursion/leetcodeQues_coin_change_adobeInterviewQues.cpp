// recursion solution but tle would be given by the compiler.
// Can be solved using dynamic programming(DP) without tle.
// The pattern used in this ques is called *(exploring all possible ways)*.

#include<iostream>
#include<vector>
using namespace std;

int findnoofcoins(vector<int> coins, int amount, int i)
{
    
}
int main(){
    vector<int> coins{6, 8, 5};
    int amount = 11;

    int minCoinsNeeded = findnoofcoins(coins, amount, 0);
    cout << "Coins needed: " << minCoinsNeeded << endl;

    return 0;
}
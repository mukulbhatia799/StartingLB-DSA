#include <iostream>
using namespace std;

int numRollsToTarget(int n, int k, int target)
{
    // base case;
    if (n == 0)
    {
        if (target == 0)
            return 1;
        return 0;
    }
    if (n != 0 && target == 0)
        return 0;
    // one cond.
    long long int count = 0;
    for (int i = 1; i <= k; i++)
    {
        count += numRollsToTarget(n - 1, k, target - i);
    }

    return count;
}

int main()
{
    int n = 3, k = 2, target = 6; // one (2, 2, 2) gives 6. So count=1 solution.

    cout << "Number of solutions: " << numRollsToTarget(n, k, target) << endl;

    return 0;
}
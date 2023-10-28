// iterative approach for fibonacci series.

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

int iterative_app_fibSeries(int n)
{
    int first = 0, second = 1, nthNumber = 0;
    if(n == 1) return 0;
    else if(n == 2) return 1;
    for(int i = 3; i <= n; i++)
    {
        nthNumber = first + second;
        first = second;
        second = nthNumber;
    }
    return nthNumber;
}

using namespace std;


int main(){
    int n;
    cin >> n;

    cout << "nth fib. no is: " << iterative_app_fibSeries(n) << endl;

    
    return 0;
}
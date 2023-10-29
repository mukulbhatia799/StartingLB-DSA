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


void recursion(int n)
{
    if(n == 0) return ;
    cout << "n value during recursion: " << n << endl;
    recursion(n-1);
    cout << "n value while returning: " << n << endl;
}


int main(){
    int n;
    cin >> n;

    recursion(n);
    
    return 0;
}
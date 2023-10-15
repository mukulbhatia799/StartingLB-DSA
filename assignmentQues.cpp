#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

pair<int, int> findsum(int n, int target)
{
    unordered_map<int, int> mpp;
    int val;
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        mpp[val] = i;
    }
    for(auto it = mpp.begin(); it != mpp.end(); it++)
    {
        int comp = target - (it->first);
        auto found = mpp.find(comp);
        if(found != mpp.end())
        {
            return {it->second, found->second};
        }
    }
}

int main(){
    int n, target;
    cin >> n >> target;

    pair<int, int> prr = findsum(n, target);

    cout << "value found at index {" << prr.first << ", " << prr.second << "}." << endl;
    
    return 0;
}
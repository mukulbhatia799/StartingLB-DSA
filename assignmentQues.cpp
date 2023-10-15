#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec{3, 0, 1, 2, 5};
    vector<int> store(vec.size()+1, -1);
    for(int i = 0; i < vec.size(); i++)
    {
        store[vec[i]] = 0;
    }

    auto it = find(store.begin(), store.end(), -1);

    if(it != store.end())
    {
        cout << "Missing value is: " << it - store.begin() << endl;
    }

    return 0;
}
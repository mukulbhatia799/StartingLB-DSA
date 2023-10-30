#include<iostream>
#include<vector>
using namespace std;

void returnDigits(int n, vector<int> &vec)
{
    if(n == 0) return ;
    vec.push_back(n%10);
    returnDigits(n/10, vec);
}

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;

    vector<int> ans;
    returnDigits(n, ans);

    if(ans.size() == 0) cout << "Vector is empty~" << endl;
    cout << "Displaying digits: ";
    for(auto it: ans) cout << it << " ";
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include<stack>
using namespace std;

int solve()
{
    // using stack data structure.
    int n;
    cin >> n;
    vector<vector<int> > M(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }

    stack<int> st;

    for(int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while(st.size() != 1)
    {
        int p1 = st.top(); st.pop();
        int p2 = st.top(); st.pop();

        if(M[p1][p2] == 1) {
            st.push(p2);
        } else {
            st.push(p1);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(M[st.top()][i] == 1) return -1;
        if(M[i][st.top()] == 0 && st.top() != i) return -1;
    }

    return st.top();
}

int main()
{
    int ans = solve();

    if (ans == -1)
        cout << "not any celeb" << endl;
    else
        cout << "celeb is " << ans << " index." << endl;

    return 0;
}
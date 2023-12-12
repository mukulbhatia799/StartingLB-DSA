// stack STL
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;

    st.push(12);
    st.push(13);
    st.push(14);
    st.push(15);

    cout << st.top() << endl;
    cout << st.size() << endl;
    st.pop();
    cout << st.size() << endl;
    cout << st.top() << endl;

    if (st.empty()) // returns either 0 or 1. if empty then return 1.
        cout << "stack is empty!" << endl;
    else
        cout << "not empty!" << endl;

    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() << endl;

    return 0;
}
// using recursion + backtracking.
#include <iostream>
#include <stack>
using namespace std;

void deleteMidHelper(stack<int> &st, int pos)
{
    // base case
    if (pos == 1)
    {
        cout << "deleted mid element: " << st.top() << endl;
        st.pop();
        return;
    }

    // one case
    int temp = st.top();
    st.pop();
    pos--;
    // recursive function
    deleteMidHelper(st, pos);
    // backtracking
    st.push(temp);
}

void deleteMidElement(stack<int> &st)
{
    if (st.top() == -1)
    {
        cout << "stack is empty! can't delete mid" << endl;
    }
    else
    {
        int pos = (st.size() & 1) ? (st.size() / 2 + 1) : (st.size() / 2);
        cout << "mid pos: " << pos << endl;
        deleteMidHelper(st, pos);
    }
}

void display(stack<int> &st)
{ // displaying using recursion + backtracking.

    // base case
    if (st.size() == 0)
        return;

    // one case
    cout << st.top() << " ";
    int temp = st.top();
    st.pop();

    // recursive function
    display(st);

    // backtracking
    st.push(temp);
}

int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    deleteMidElement(st);
    cout << "stack: ";
    display(st);

    cout << endl
         << endl;

    deleteMidElement(st);
    cout << "stack: ";
    display(st);

    return 0;
}
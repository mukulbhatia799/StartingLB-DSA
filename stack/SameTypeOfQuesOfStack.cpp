/*
similar approach for all these type of ques. (Recursion + backtracking).
1. insert at bottom in a stack.
2. find middle element in a stack.
3. delete middle element in a stack.
4. reverse a stack.
5. insert in a sorted stack.
5. sort a stack.
*/

#include <iostream>
#include <stack>

using namespace std;

void insertInSorted(stack<int> &st, int value)
{
    // base case
    if (st.empty() || value > st.top())
    {
        st.push(value);
        return;
    }

    // one case
    int temp = st.top();
    st.pop();

    // recursive function
    insertInSorted(st, value);

    // backtracking
    st.push(temp);
}

void sortStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }

    // one case
    int temp = st.top();
    st.pop();

    // recursion
    sortStack(st);

    // backtracking
    insertInSorted(st, temp);
}

void display(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    cout << st.top() << " ";
    int temp = st.top();
    st.pop();
    display(st);
    st.push(temp);
}

int main()
{
    stack<int> st;

    st.push(10);
    st.push(7);
    st.push(15);
    st.push(12);
    st.push(20);

    display(st);
    cout << endl;

    sortStack(st); // time complexity: O(n^2).

    display(st);
    cout << endl;

    return 0;
}
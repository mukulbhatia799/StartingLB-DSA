#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        int value = q.front();
        q.pop();
        st.push(value);
    }
    while(!st.empty())
    {
        int value = st.top();
        st.pop();
        q.push(value);
    }
}

void display(queue<int> q)
{
    cout << "Displaying: ";
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    display(q);
    reverseQueue(q);
    display(q);

    return 0;
}
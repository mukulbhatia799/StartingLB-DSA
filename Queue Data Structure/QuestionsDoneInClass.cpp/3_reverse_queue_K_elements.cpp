#include <iostream>
#include <queue>
using namespace std;

// using recursion, reverse K elements.
void ReverseKelements(queue<int> &q, int K)
{
    if (K <= 0)
        return;
    int value = q.front();
    q.pop();
    ReverseKelements(q, K - 1);
    q.push(value);
}

void display(queue<int> q)
{
    cout << "Display: ";
    while (!q.empty())
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
    q.push(70);

    display(q);
    ReverseKelements(q, 3); // result: 40 50 60 70 10 20 30
    display(q);

    return 0;
}
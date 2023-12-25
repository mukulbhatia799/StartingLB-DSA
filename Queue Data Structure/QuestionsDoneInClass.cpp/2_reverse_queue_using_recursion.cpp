#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int>& q)
{
    if(q.empty()) return ;

    int value = q.front();
    q.pop();
    reverseQueue(q);
    q.push(value);
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

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);

    display(q);
    reverseQueue(q);
    display(q);

    return 0;
}
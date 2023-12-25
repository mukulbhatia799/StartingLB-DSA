// take first half and second half and place each half element one by one in new queue.

#include<iostream>
#include<queue>
using namespace std;

void interLeaveQueue(queue<int>& q)
{
    queue<int> temp;        // place first half(n/2th) queue in temp queue.
    int size = q.size();
    for(int i = 0; i < size/2; i++)
    {
        int value = q.front();
        q.pop();
        temp.push(value);
    }

    for(int i = 0; i < size/2; i++)
    {
        int value = temp.front();
        temp.pop();
        q.push(value);
        
        value = q.front();
        q.pop();
        q.push(value);
    }
}

void display(queue<int> q)
{
    cout << "display: ";
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// queue size will always be even for this question.
int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    // required output: 10 40 20 50 30 60.

    display(q);

    interLeaveQueue(q);

    display(q);

    return 0;
}
// circular queue.

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int size)
    {
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = 0;
        this->size = size;
        front = -1;
        rear = -1;
    }
    void push(int val)
    {
        cout << "=============push=============" << endl;
        // overflow condition.
        // if rear on last index or not. Also, if it is, then check if front == 0 or not. if it is, then the queue is full else we can push the element in it.
        // then check queue is empty or not.
        // if rear is neither at last index or queue is overflowed then update rear and push the element.
        if (rear == size - 1)
        {
            if (front == 0)
                cout << "overflow" << endl;
            else
            {
                rear = 0;
                arr[rear] = val;
            }
        }
        else if (front == -1 && rear == -1)
        { // insert first element.
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    void pop()
    {
        cout << "============pop==============" << endl;
        // check underflow condition.
        // check empty or not.
        // check if front on last index or not. If it is, then check rear at last index or not. If it is, then the queue is empty else place the front at first index and pop().
        // At last, else part when neither the stack is empty or underflow or front on last index.
        if (front == -1 && rear == -1)
        {
            cout << "underflow" << endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    void print()
    {
        cout << "front: " << front << " rear: " << rear << endl;
        cout << "displaying queue: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Queue q(3);
    q.push(10); q.print();
    q.push(20); q.print();
    q.push(30); q.print();

    q.pop(); q.print();
    q.pop(); q.print();

    q.push(40); q.print();
    q.push(50); q.print();

    q.pop(); q.print();
    q.pop(); q.print();
    q.pop(); q.print();

    q.push(60); q.print();

    return 0;
}
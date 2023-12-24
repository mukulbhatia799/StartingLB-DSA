#include <iostream>
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
        cout << "================" << endl;
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
            cout << "pushed at empty" << endl;
        }
        else if (rear == size - 1)
        {
            cout << "can't push, queue overflow!" << endl;
        }
        else
        {
            rear++;
            arr[rear] = val;
            cout << "pushed at non-empty" << endl;
        }
    }
    void pop()
    {
        cout << "================" << endl;
        if ((front == -1 && rear == -1) || front > rear)
        {
            cout << "can't pop, empty queue" << endl;
        }
        else
        {
            if (front == rear)
                cout << "popped when 1 element" << endl;
            else
                cout << "popped" << endl;
            arr[front] = -1;
            front++;
        }
    }
    int getSize()
    {
        if (front == -1 && rear == -1)
            return 0;
        return rear - front + 1;
    }
    bool isempty()
    {
        if (front > rear || (front == -1 && rear == -1))
        {
            return 1;
        }
        return 0;
    }
    void print()
    {
        cout << "front: " << front << " rear: " << rear << endl;
        cout << "Displaying queue: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(3);
    cout << "================" << endl;
    q.print();

    q.push(10);
    q.print();
    q.push(20);
    q.print();

    q.pop();
    q.print();
    q.pop();
    q.print();

    q.push(10);
    q.print();

    cout << "queue size: " << q.getSize() << endl;

    q.pop();
    q.print();

    cout << "queue size: " << q.getSize() << endl;

    if (q.isempty())
        cout << "empty queue" << endl;
    else
        cout << "queue is not empty" << endl;

    return 0;
}
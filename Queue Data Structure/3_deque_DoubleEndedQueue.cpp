// dequeue :- insertion and deletion done at both side of the end(front and rear).

// *we can also implement dequeue with circular array/circular queue. Sometimes interviewer ask.

#include<iostream>
using namespace std;

class Dequeue {
    int *arr;
    int size;
    int front;
    int rear;
public:
    void pushRear(int val) {                // by default, push from end is done.
        if(rear == size-1) {
            cout << "Overflow" << endl;
        } else if(front == -1 && rear == -1) {
            front++;
            rear++;
            arr[rear] = val;
        } else {
            rear++;
            arr[rear] = val;
        }
    }
    void pushFront() {              // push from front.

    }
    void popFront() {               // by default, pop from front is done.

    }
    void popRear() {                 // pop fron end.

    }
};

int main(){
    

    return 0;
}
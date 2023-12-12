#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int size;

public:
    Stack()
    {
        cout << "size of stack: ";
        cin >> this->size;
        this->top = -1;
        this->arr = new int(this->size);
    }
    Stack(int size)
    {
        this->arr = new int(size); // creating dynamic memory of given size.
        this->top = -1;            // -1 defines stack is empty.
        this->size = size;
    }
    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "overflow! can't push()." << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    void pop()
    {
        if (top == -1)
            cout << "underflow! can't pop()." << endl;
        else
        {
            top--;
        }
    }
    int findTop()
    {
        if (top == -1)
            cout << "stack is empty!" << endl;
        else
        {
            return arr[top];
        }
        return -1;
    }
    bool findIsEmpty()
    {
        if (top == -1)
            return 1;
        return 0;
    }
    int findSize()
    {
        return top + 1;
    }
    void display()
    {
        cout << "top: " << top << endl;
        if (top == -1)
        {
            cout << "stack is empty!";
        }
        else
        {
            cout << "top element: " << arr[top] << endl;
            cout << "Displaying stack: ";
            for (int i = 0; i < findSize(); i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl
             << endl;
    }
};

int main()
{
    Stack st(3);

    st.push(10);
    st.display();

    st.push(20);
    st.display();

    st.push(30);
    st.display();

    st.pop();
    st.display();

    st.pop();
    st.display();

    st.pop();
    st.display();

    st.pop();
    st.display();

    st.push(100);
    st.display();
    st.push(200);
    st.display();
    st.push(300);
    st.display();
    st.push(400);
    st.display();

    return 0;
}
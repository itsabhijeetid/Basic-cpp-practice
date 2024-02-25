#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int nextIndex;
    int maxSize;
    int delElement; // for storing last deleted element
public:
    Stack()
    {
        nextIndex = 0;
        maxSize = 2;
        arr = new int[maxSize];
    }
    void push(int);
    void pop();
    int top();
    int size();
    bool isEmpty();
    bool isFull();
};

int Stack::size()
{
    return nextIndex;
}

bool Stack ::isEmpty()
{
    return nextIndex == 0;
}

bool Stack ::isFull()
{
    if (nextIndex == maxSize)
    {
        int *new_arr = new int[2 * maxSize];
        for (int i = 0; i < maxSize; i++)
        {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        maxSize *= 2;
    }
    return false;
}

void Stack ::push(int data)
{
    if (!isFull())
    {
        arr[nextIndex] = data;
        nextIndex += 1;
    }
    else
    {
        cout << "Stack is Full\n";
    }
}

void Stack ::pop()
{
    if (!(isEmpty()))
    {
        delElement = arr[nextIndex];
        nextIndex -= 1;
        cout << "Element deleted succesfully\n";
    }
    else
    {
        cout << "Stack is Empty\n";
    }
}

int Stack ::top()
{
    if (!(isEmpty()))
        return arr[nextIndex - 1];
    else
        return -1;
}

int main()
{
    Stack s1;
    int data = 0;
    cout << "To stop input press -1\n ";
    while (true)
    {
        cin >> data;
        if (data == -1)
        {
            break;
        }
        s1.push(data);
    }
    if (s1.top() == -1)
    {
        cout << "Stack is Empty\n";
    }
    else
    {
        cout << s1.top() << endl;
    }
    s1.pop();
    if (s1.top() == -1)
    {
        cout << "Stack is Empty\n";
    }
    else
    {
        cout << s1.top() << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int nextIndex;
    int maxSize;
    int delElement; // for storing last deleted element
public:
    Stack(int size)
    {
        nextIndex = 0;
        arr = new int[size];
        maxSize = size;
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
    return nextIndex == maxSize;
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
    if (!isEmpty())
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
    if (!isEmpty())
    {
        return arr[nextIndex - 1];
    }
    else
        return 0;
}

int main()
{
    int size;
    cout << "Enter the size of stack : ";
    cin >> size;
    Stack s1(size);
    int data;
    for (int i = 0; i < size; i++)
    {
        cin >> data;
        s1.push(data);
    } 
    s1.push(999);
    cout << "size : " << s1.size() << endl;
    if (s1.top() == 0)
    {
        cout << "Stack is Empty\n";
    }
    else
    {
        cout << s1.top() << endl;
    }
    s1.pop();
    if (s1.top() == 0)
    {
        cout << "Stack is Empty\n";
    }
    else
    {
        cout << s1.top() << endl;
    }
    return 0;
}

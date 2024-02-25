#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    T *data;
    int maxCapacity;
    int nextIndex;
    int deletedElement;

public:
    Stack()
    {
        maxCapacity = 2;
        nextIndex = 0;
        data = new T[maxCapacity];
    }
    bool isFull()
    {
        if (nextIndex == maxCapacity)
        {
            T *new_data = new T[2 * maxCapacity];
            for (int i = 0; i < maxCapacity; i++)
            {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            maxCapacity *= 2;
        }
        return false;
    }
    void push(T n)
    {
        if (!isFull())
        {
            data[nextIndex] = n;
            nextIndex++;
        }
    }
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void pop()
    {
        if (!isEmpty())
        {
            deletedElement = data[nextIndex];
            nextIndex--;
            cout << "Element deleted Succesfully\n";
        }
        else
        {
            cout << "No Element found\n";
        }
    }
    T top()
    {
        if (!isEmpty())
        {
            return data[nextIndex-1];
        }
        else
        {
            cout << "No Element found\n";
            return 0;
        }
    }
    int size()
    {
        return nextIndex;
    }
};

int main()
{
    Stack<int> s1;
    for (int i = 0; i < 4; i++)
    {
        s1.push(i + 11);
    }
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    cout << s1.isEmpty() << endl;
    cout << s1.size() << endl;
    s1.pop();
    cout << s1.top() << endl;
    return 0;
}
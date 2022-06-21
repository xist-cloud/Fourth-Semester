#include <iostream>
#define MAX 10

using namespace std;

class Stack
{
private:
    int top, size;
    int *stack;

public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop(void);
    bool isFull(void);
    bool isEmpty(void);
};

Stack::Stack(int size)
{
    this->top = -1;
    this->size = size;
    this->stack = new int[size];
}

Stack::~Stack()
{
    delete[] this->stack;
}

bool Stack::isFull()
{
    return (this->top == size - 1);
}

bool Stack::isEmpty()
{
    return (this->top == -1);
}

void Stack::push(int x)
{
    if (isFull())
    {
        return;
    }
    this->top++;
    this->stack[this->top] = x;
}

int Stack::pop()
{
    if (isEmpty())
        return -1;
    else
    {
        int temp = this->stack[this->top];
        this->top--;
        return temp;
    }
}

int main()
{
    Stack *s = new Stack(MAX);
    int choice, value;
    while (true)
    {
        cout << endl
             << endl
             << "Stack Operations: " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Exit" << endl;
        cout << endl
             << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (s->isFull())
            {
                cout << "Stack Full." << endl;
            }
            else
            {
                cout << "Enter value: ";
                cin >> value;
                s->push(value);
            }
            break;
        case 2:
            if (!s->isEmpty())
            {
                value = s->pop();
                cout << value << endl;
            }
            else
            {
                cout << "Stack Empty.";
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Enter correct choice!!";
        }
    }
    return 0;
}
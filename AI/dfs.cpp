#include <iostream>

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
    int vertices;
    // Vertices
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    // Create Queue
    Stack *s = new Stack(2 * vertices);

    // Visited List
    bool visited[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = false;
    }

    // Adjacency Matrix
    int adjMat[vertices][vertices];
    cout << "Enter adjacency matrix (one row at a time): " << endl;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            cin >> adjMat[i][j];

    // Start Node
    int startNode;
    cout << "Enter start node: ";
    cin >> startNode;

    // Depth First Search
    int currentNode = startNode;
    s->push(currentNode);
    while (!s->isEmpty())
    {
        currentNode = s->pop();
        cout << currentNode;
        visited[currentNode] = true;
        for (int i = 0; i < vertices; i++)
        {
            if ((adjMat[currentNode][i] == 1) && (!visited[i]))
            {
                visited[i] = true;
                s->push(i);
            }
        }
    }
}
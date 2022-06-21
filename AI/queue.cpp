#include <iostream>
#define MAX 10

using namespace std;

class Queue
{
private:
    int front, rear, size;
    int *queue;

public:
    Queue(int size);
    ~Queue();

    void Enqueue(int x);
    int Dequeue(void);
    bool isFull();
    bool isEmpty();
};

Queue::Queue(int size = 10)
{
    this->front = -1;
    this->rear = -1;
    this->size = size;
    this->queue = new int[this->size];
}

Queue::~Queue()
{
    delete[] this->queue;
}

bool Queue::isEmpty()
{
    return (this->front == this->rear);
}
bool Queue::isFull()
{
    return (this->front == this->size - 1);
}

void Queue::Enqueue(int x)
{
    if (isFull())
        return;
    this->front++;
    this->queue[this->front] = x;
}

int Queue::Dequeue()
{
    if (!isEmpty())
    {
        this->rear++;
        return this->queue[rear];
    }
    return -1;
}

int main(void)
{
    Queue *q = new Queue(MAX);
    int choice, value;
    while (true)
    {
        cout << endl
             << endl
             << "Queue Operations: " << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Exit" << endl;
        cout << endl
             << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (q->isFull())
            {
                cout << "Queue Full." << endl;
            }
            else
            {
                cout << "Enter value: ";
                cin >> value;
                q->Enqueue(value);
            }
            break;
        case 2:
            if (!q->isEmpty())
            {
                value = q->Dequeue();
                cout << value << endl;
            }
            else
            {
                cout << "Queue Empty.";
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
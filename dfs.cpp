#include <iostream>

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
    delete[] queue;
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
    return 0;
}

int main(void)
{
    Queue *queue = new Queue(5);
}
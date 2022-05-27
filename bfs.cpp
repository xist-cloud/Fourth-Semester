//Breadth first search

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
	int vertices;
	//Vertices
	cout << "Enter the number of vertices: ";
	cin >> vertices;
	
	//Create Queue
	Queue *q = new Queue(2*vertices);
	
	//Visited List
	bool visited[vertices];
	for(int i =0; i<vertices;i++){
		visited[i] = false;
	}
	
	//Adjacency Matrix
	int adjMat[vertices][vertices];
	cout << "Enter adjacency matrix (one row at a time): "<<endl;
	for(int i = 0; i < vertices; i++)
		for(int j = 0; j<vertices; j++)
			cin >> adjMat[i][j];
	
	//Start Node
	int startNode;
	cout << "Enter start node: ";
	cin >> startNode;
	
	//Breadth First Search
	int currentNode;
	currentNode = startNode;
	q->Enqueue(startNode);
	while(!q->isEmpty()){
		currentNode = q->Dequeue();
		cout << currentNode;
		visited[currentNode] = true;
		
		for(int i = 0; i<vertices; i++){
			if((adjMat[currentNode][i] == 1) && (!visited[i])){
				visited[i] = true;
				q->Enqueue(i);
			}
		}
	}
}
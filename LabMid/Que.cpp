#include <iostream>
using namespace std;

// Node class representing an element of the queue
class Node
{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

// Queue class using linked list
class Queue
{
private:
    Node* front;  // Pointer to the front element
    Node* rear;   // Pointer to the rear element
    int size;     // Size of the queue

public:
    // Constructor to initialize an empty queue
    Queue()
    {
        front = rear = nullptr;
        size = 0;
    }

    // Enqueue (insert element at the rear)
    void enqueue(int x)
    {
        Node* newNode = new Node(x);

        // If the queue is empty, set front and rear to the new node
        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
    }

    // Dequeue (remove element from the front)
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Cannot dequeue from an empty queue." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        // If the queue becomes empty, set rear to nullptr as well
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        size--;
    }

    // Peek at the front element without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;  // Returning -1 to indicate empty queue
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Get the current size of the queue
    int getSize()
    {
        return size;
    }

    // Display the entire queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Destructor to clear the queue and free memory
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    Queue queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Display the queue
    cout << "Queue after enqueuing 10, 20, 30:" << endl;
    queue.display();

    // Peek at the front element
    cout << "Front element: " << queue.peek() << endl;

    // Dequeue an element
    queue.dequeue();
    cout << "Queue after dequeuing an element:" << endl;
    queue.display();

    // Get the size of the queue
    cout << "Current size of the queue: " << queue.getSize() << endl;

    // Check if the queue is empty
    cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

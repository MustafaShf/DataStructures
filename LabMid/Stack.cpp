#include <iostream>
using namespace std;

// Node class for the linked list
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

// Stack class using linked list
class Stack
{
private:
    Node* top;  // Pointer to the top of the stack
    int size;   // Size of the stack

public:
    Stack()
    {
        top = nullptr;
        size = 0;
    }

    // Push element onto the stack
    void push(int x)
    {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Pop element from the stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    // Peek at the top element of the stack
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;  // Returning -1 to indicate empty stack
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Get the size of the stack
    int getSize()
    {
        return size;
    }

    // Display the entire stack
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Destructor to clear the stack and free memory
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{
    Stack stack;

    // Pushing elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display the stack
    cout << "Stack after pushing 10, 20, 30:" << endl;
    stack.display();

    // Peek at the top element
    cout << "Top element: " << stack.peek() << endl;

    // Pop an element from the stack
    stack.pop();
    cout << "Stack after popping an element:" << endl;
    stack.display();

    // Get the size of the stack
    cout << "Current size of the stack: " << stack.getSize() << endl;

    // Check if the stack is empty
    cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Node
class Node
{
public:
    int Data;
    Node *next;

    Node(int x = 0)
    {
        this->Data = x;
        this->next = nullptr;
    }
};

// LinkedList
class LinkedList
{
public:
    Node *Head;
    LinkedList(int size)
    {
        if (size > 0)
        {
            Head = new Node(0);
            Node *current = Head;

            // Create the rest of the nodes
            for (int i = 1; i < size; ++i)
            {
                current->next = new Node(i);
                current = current->next;
            }
        }
        else
        {
            Head = nullptr;
        }
    }
    
    // Function to display the list
    void display()
    {
        Node *temp = Head;
        while (temp != nullptr)
        {
            cout << temp->Data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Insert at end
    void insertAtEnd(int x)
    {
        Node *T = new Node(x);
        if (Head == nullptr) {
            Head = T;
            return;
        }
        Node *temp = Head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = T;
    }

    // Insert at a specific position
    void insert(int x, int pos)
    {
        if (pos == 0)
        {
            Node *T = new Node(x);
            T->next = Head;
            Head = T;
        }
        else if (pos > 0)
        {
            Node *T = new Node(x);
            Node *temp = Head;
            for (int i = 0; i < pos - 1 && temp != nullptr; i++)
            {
                temp = temp->next;
            }
            if (temp != nullptr)
            {
                T->next = temp->next;
                temp->next = T;
            }
        }
    }

    // Deletion by position
    void deletion(int pos)
    {
        if (Head == nullptr)
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        if (pos == 0)
        {
            Node *temp = Head;
            Head = Head->next;
            delete temp;
        }
        else if (pos > 0)
        {
            Node *p = Head;
            Node *q = nullptr;
            for (int i = 0; i < pos - 1 && p != nullptr; i++)
            {
                q = p;
                p = p->next;
            }
            if (p != nullptr)
            {
                q->next = p->next;
                delete p;
            }
        }
    }

    // Reverse the linked list
    void reverseLinkedList()
    {
        Node *p = Head;
        Node *q = nullptr;
        Node *r = nullptr;
        while (p != nullptr)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        Head = q;
    }

    // Find the size of the list
    int size()
    {
        int count = 0;
        Node *temp = Head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Search for a specific element in the list
    bool search(int key)
    {
        Node *temp = Head;
        while (temp != nullptr)
        {
            if (temp->Data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Find the middle element of the list
    int findMiddle()
    {
        Node *slow = Head;
        Node *fast = Head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return (slow != nullptr) ? slow->Data : -1;
    }

    // Detect if there is a cycle in the list (Floyd’s cycle detection algorithm)
    bool detectCycle()
    {
        Node *slow = Head;
        Node *fast = Head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    // Clear the linked list (free all nodes)
    void clear()
    {
        Node *current = Head;
        Node *next;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
        Head = nullptr;
    }

    ~LinkedList() {
        clear();
    }
};

int main()
{
    int size;
    cout << "Enter the size of the linked list: ";
    cin >> size;
    LinkedList list(size);
    cout << "The linked list is: ";
    list.display();

    list.insertAtEnd(100);
    list.display();

    list.insert(10, 0);
    list.display();

    list.insert(-99, 3);
    list.display();

    cout << "Size of the linked list: " << list.size() << endl;
    
    list.deletion(0);
    list.display();

    list.deletion(3);
    list.display();

    cout << "Middle element of the linked list: " << list.findMiddle() << endl;

    list.reverseLinkedList();
    list.display();

    cout << "Searching for 100: " << (list.search(100) ? "Found" : "Not Found") << endl;
    cout << "Searching for 200: " << (list.search(200) ? "Found" : "Not Found") << endl;

    return 0;
}

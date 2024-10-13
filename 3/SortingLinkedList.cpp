#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node*next;
  Node(int data)
  {
    this->data=data;
  }  
};
class LinkedList
{
     Node* head;
     public:
     LinkedList()
    {
        head = nullptr;
    }
    //innsert at end

    void insertAtEnd(int data)
    {
        Node* newNode = new Node(data);
        
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void display()
    {
        if (head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
    void swapnodes(Node*& head, Node* a, Node* b)
{
 
    Node* prev=head;
    if (head == NULL) {
        cout << "list is null" << endl;
        return;
    }
    else if (head->next == NULL)
    {
        cout << "list has only one item" << endl;
        return;
    }
    else if (head == a && head->next == b)
    {
        cout << "at start" << endl;
        head->next = head->next->next;                                        
        b->next = a;
        head = b;
    }
    else
    {
        while (prev->next != a&& prev->next != NULL)
        {
            cout << "Searching prev of a" << endl;
            prev = prev->next;
        }
        if (a->next == b)
        {
            prev->next = b;
            a->next = b->next;
            b->next = a;
            cout << "swapped" << endl;
        }
        else {
            cout << "a and b are not consecutive" << endl;
        }
    }
}
    void Sorting(Node* &head)
{
    Node* outer = head;
    while (outer != nullptr)
    {
        Node* innertemp = head;
        while (innertemp->next!=nullptr)
        {
            cout << "Comparing data" << endl;
            if (innertemp->next!=nullptr&& innertemp->data > innertemp->next->data)
            {
                cout << "swapping"<<endl;
                swapnodes(head ,innertemp, innertemp->next);
            }
            innertemp = innertemp->next;
        }
        outer = outer->next;
    }

}
    // Destructor to free memory
    ~LinkedList()
    {
        Node* temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

};

int main()
{

    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Linked List: ";
    list.display();

    return 0;
}
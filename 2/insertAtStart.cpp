#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
   
};
void InsertAtStart(Node*& head, int d)
{
    Node* temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        cout << "Inserted at empty list\n";
    }
    else
    {
        temp->next = head;
        head = temp;
        cout << "Inserted at head\n";
    }
}
void Print(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;

}
int main() {
    Node* head = NULL;
    InsertAtStart(head, 10);
    InsertAtStart(head, 20);
    Print(head);
    InsertAtStart(head, 30);
    InsertAtStart(head, 40);
    InsertAtStart(head, 50);
    Print(head);
}
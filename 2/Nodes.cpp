#include<iostream>
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
int main() {
    Node* head = NULL;
    head = new Node(1);
    
    cout<<head<<endl;
    cout<<head->data<<endl;
    cout<<head->next<<endl;

    head->next= new Node(2);

    cout<<head->data<<endl;
    cout<<head->next->data<<endl;
    

    head->next->next = new Node(3);
    Node* temp=head;
    while (temp!= NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

}
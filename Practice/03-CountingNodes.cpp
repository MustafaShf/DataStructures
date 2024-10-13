#include<iostream>
using namespace std;

class Node{
    public:
    int Data;
    Node*next;

    Node(int v)
    {
        Data=v;
        next=NULL;
    }
};
Node* Head=NULL;

void ArrayToLinkedList(int Arr[],int n)
{
    if(n == 0) return;
    Head = new Node(Arr[0]);
    Node* temp = Head;
     for(int i = 1; i < n; i++)
    {
        temp->next = new Node(Arr[i]); 
        temp = temp->next; 
    }
}

void PrintLinkedList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->Data << "->";
        temp = temp->next;
    }
    cout<<"Null" << endl;
}

    int CountNodes(Node *H)
    {
         Node* temp = H;
        int c=0;
        if(temp==NULL) 
        {
            cout<<"No Nodes\n";
            return 0;}
        else
            while(temp)
            {
                c++;
                temp=temp->next;
            }
        return c;
    }


int main()

{
    int arr[]={1,2,3,4,5};
    int size =sizeof(arr)/sizeof(arr[0]);
    ArrayToLinkedList(arr,size);
    PrintLinkedList(Head);
    cout<<"Total Nodes "<<CountNodes(Head);
    return 0;
}
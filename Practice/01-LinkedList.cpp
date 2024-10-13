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




int main()

{
    int arr[]={1,2,3,4,5};
    int size =sizeof(arr)/sizeof(arr[0]);
    Node* Head=new Node(1);

    cout<<Head<<" Head \n";
    cout<<Head->Data<<" Head->Data \n";
    cout<<Head->next<<" Head->next \n";

    Head->next=new Node(2);
    Head->next->next=new Node(3);
    Head->next->next->next=new Node(4);

    Node *Triverse=Head;

    while(Triverse!=0)
    {
        cout<<Triverse->Data<<"->";
        Triverse=Triverse->next;
    }

    

    return 0;
}
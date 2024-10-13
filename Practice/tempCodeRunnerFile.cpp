    cout<<"Null" << endl;
}

    int CountNodes(Node *H)
    {
         Node* temp = H;
        int c=0;
        if(temp) return;
        else
            while(!temp)
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
    cout<<"Total No
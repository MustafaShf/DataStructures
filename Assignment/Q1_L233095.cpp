#include <iostream>
using namespace std;

class Node
{
public:
    Node *left, *right, *up, *down;
    int data;
    string name;
    bool isRoad;
    Node(int x)
    {
        left = right = up = down = NULL;
        data = x;
        name = "";
        isRoad = false;
    }
};

class Map
{
public:
    Node *mainHead;
    Map()
    {
        mainHead = NULL;
    }
    Map(int r, int c)
    {
        mainHead = NULL;
        Node **Head = new Node *[r];
        for (int i = 0; i < r; i++)
        {
            Head[i] = nullptr;
            //cout << "Enter digits for "<<i<<"th row\n";
            for (int j = 0; j < c; j++)
            {
                Node *t1;
                int num;
                //cin >> num;
                num=0;
                Node *newptr = new Node(num);
                if (!mainHead)
                    mainHead = newptr;
                if (!Head[i])
                {
                    Head[i] = newptr;
                    t1 = Head[i];
                }
                else
                {
                    t1->right = newptr;
                }
                t1 = newptr;
            }
            Node *temp, *temp2;
            temp = Head[i];
            temp2 = nullptr;
            while (temp != nullptr)
            {
                temp->left = temp2;
                temp2 = temp;
                temp = temp->right;
            }
            if (i > 0)
            {
                temp = Head[i];
                temp2 = Head[i - 1];
                while (temp && temp2)
                {
                    temp->up = temp2;
                    temp2->down = temp;
                    temp = temp->right;
                    temp2 = temp2->right;
                }
            }
        }
    }
    void Print()
    {
        cout<<"Your Matrix Data Printing ....\n";
        Node *row = mainHead;
        while (row)
        {
            Node *col = row;
            while (col)
            {
                cout << col->data << " ";
                col = col->right;
            }
            cout << endl;
            row = row->down;
        }
        cout<<"Your Data Printed ....\n";
    }
    void ConstructRoad(int row, int col, string pointA, string pointB, int lengthOfRoad, string direction)
    {
        Node *Start = Search(row, col);
        if (!Start)
        {
            cout << "Starting point not found.\n";
            return;
        }

        Start->name = pointA;
        int i = 0;

        // Mark starting point as road
        Start->isRoad = true;

        if (direction == "right")
        {
            while (i < lengthOfRoad - 1)
            {
                if (Start->right)
                {
                    Start = Start->right;
                    Start->isRoad = true;
                    i++;
                }
                else
                {
                    cout << "You input a length longer than the available road to the right.\n";
                    return;
                }
            }
        }
        else if (direction == "down")
        {
            while (i < lengthOfRoad - 1)
            {
                if (Start->down)
                {
                    Start = Start->down;
                    Start->isRoad = true;
                    i++;
                }
                else
                {
                    cout << "You input a length longer than the available road downwards.\n";
                    return;
                }
            }
        }
        else if (direction == "left")
        {
            while (i < lengthOfRoad - 1)
            {
                if (Start->left)
                {
                    Start = Start->left;
                    Start->isRoad = true;
                    i++;
                }
                else
                {
                    cout << "You input a length longer than the available road to the left.\n";
                    return;
                }
            }
        }
        else if (direction == "up")
        {
            while (i < lengthOfRoad - 1)
            {
                if (Start->up)
                {
                    Start = Start->up;
                    Start->isRoad = true;
                    i++;
                }
                else
                {
                    cout << "You input a length longer than the available road upwards.\n";
                    return;
                }
            }
        }
        else
        {
            cout << "Invalid direction.\n";
            return;
        }

        Start->name = pointB;
        cout<<"Your Road is Constructed from "<<pointA<<" to "<<pointB<<endl;
    }
    void ConstructRoad(string pointA, string pointB, int lengthOfRoad, string direction)
    {
        Node *current = mainHead;
        int row = 0, col = 0;
        bool found = false;

        // Traverse until name == pointA
        while (current)
        {
            Node *temp = current;
            col = 0;
            while (temp)
            {
                if (temp->name == pointA)
                {
                    found = true;
                    break;
                }
                temp = temp->right;
                col++;
            }
            if (found)
                break;
            current = current->down;
            row++;
        }

        if (!found)
        {
            cout << "Starting point '" << pointA << "' not found.\n";
            return;
        }
        cout << "Col " << col << " row " << row << endl;
        // Now as we have row and col
        ConstructRoad(row, col, pointA, pointB, lengthOfRoad, direction);
    }
    void PrintRoad()
    {
        cout<<"The (*) is the road is shown in map\n";
        Node *row = mainHead;
        while (row)
        {
            Node *col = row;
            while (col)
            {
                if (col->isRoad == 1)
                    cout << "*";
                else
                    cout << "-";
                col = col->right;
            }
            cout << endl;

            row = row->down;
        }
    }
    void RemoveRoad(const string& pointA, const string& pointB)
    {
        //search nodes
        Node *startNode=SearchByName(pointA);
        Node *endNode=SearchByName(pointB);
        //check 
        if(!startNode && !endNode) {
            cout<<"The one or both node not found (Try to give nodes that live in same line)\n";
            return;}
        //check if in same row or col (assume)
        if(isHaveDirectPath(startNode,endNode))
        {
            
            //Update Matrix Roads
            UpdateRoad(startNode,endNode,false);
        }else
        {
            cout<<"The one or both node not found try to give node o same line\n";
            return;
        }
        
    }
private:
    Node *Search(int r, int c)
    {
        Node *row = mainHead;
        int rc = 0;
        while (row && rc < r)
        {
            row = row->down;
            rc++;
        }
        if (!row)
            return nullptr;

        Node *col = row;
        int cc = 0;
        while (col && cc < c)
        {
            col = col->right;
            cc++;
        }
        return col;
    }
    Node *SearchByName(string name)
    {
        Node *current = mainHead;
        while(current)
        {
            Node *temp=current;
            while(temp)
            {
                if(temp->name==name)
                {
                    return temp;
                }
                temp=temp->right;
            }
            current=current->down;
        }
        return nullptr;
    }
    bool isHaveDirectPath(Node *startNode, Node *endNode)
    {
        return isSameRow(startNode,endNode)||isSameCol(startNode,endNode);
    }
    bool isSameRow(Node *startNode, Node *endNode)
    {
        Node*current=startNode;
        // Check right
        while (current) {
            if (current == endNode) {
                return true;
            }
            current = current->right;
        }
        current=startNode;
        // Check right
        while (current) {
            if (current == endNode) {
                return true;
            }
            current = current->left;
        }
         return false;
    }
    bool isSameCol(Node *startNode, Node *endNode)
    {
        Node*current=startNode;
        // Check down
        while (current) {
            if (current == endNode) {
                return true;
            }
            current = current->down;
        }
        current=startNode;
        // Check up
        while (current) {
            if (current == endNode) {
                return true;
            }
            current = current->up;
        }
         return false;
    }
    bool CheckEndNodePathDirec(Node* start, Node* end, string direction) {
    Node* current = start;

    if (direction == "right") {
        while (current && current != end) {
            current = current->right;
        }
    } else if (direction == "left") {
        while (current && current != end) {
            current = current->left;
        }
    } else if (direction == "down") {
        while (current && current != end) {
            current = current->down;
        }
    } else if (direction == "up") {
        while (current && current != end) {
            current = current->up;
        }
    }

    return current == end;
}
    void UpdateRoad(Node *startNode,Node *endNode,bool changeRoad)
    {
        if (isSameRow(startNode, endNode)) {
        // Check first in both right and left directions
        if (CheckEndNodePathDirec(startNode, endNode, "right")) {
            // Now update the path (right direction)
            Node* current = startNode;
            while (current && current != endNode) {
                current->isRoad = changeRoad;
                current = current->right;
            }
            if (current == endNode) {
                current->isRoad = changeRoad;
            }
        } else if (CheckEndNodePathDirec(startNode, endNode, "left")) {
            // Now update the path (left direction)
            Node* current = startNode;
            while (current && current != endNode) {
                current->isRoad = changeRoad;
                current = current->left;
            }
            if (current == endNode) {
                current->isRoad = changeRoad;
            }
        } else {
            cout << "No direct path found in the horizontal direction.\n";
        }
    } else if (isSameCol(startNode, endNode)) {
        // Check first in both down and up directions
        if (CheckEndNodePathDirec(startNode, endNode, "down")) {
            // Now update the path (down direction)
            Node* current = startNode;
            while (current && current != endNode) {
                current->isRoad = changeRoad;
                current = current->down;
            }
            if (current == endNode) {
                current->isRoad = changeRoad;
            }
        } else if (CheckEndNodePathDirec(startNode, endNode, "up")) {
            // Now update the path (up direction)
            Node* current = startNode;
            while (current && current != endNode) {
                current->isRoad = changeRoad;
                current = current->up;
            }
            if (current == endNode) {
                current->isRoad = changeRoad;
            }
        } else {
            cout << "No direct path found in the vertical direction.\n";
        }
    } else {
        cout << "No direct path found.\n";
    }
    }
};

int main()
{
    cout<<"Enter map dimension\n";
    int d;
    cout<<"Enter Dimension\n";
    cin>>d;
    cout<<"A d*d map Generated\n";
    Map M(d, d);
    M.Print();
    M.ConstructRoad(5,3,"a","b",5,"right");
    //M.ConstructRoad(4,5,"c","d",5,"right");
    //M.ConstructRoad(1, 0, "a", "b", 3, "right");
   // M.ConstructRoad("a", "c", 2, "down");
    // M.ConstructRoad("c", "d", 2, "right");
    // M.ConstructRoad("d", "e", 3, "up");
    //cout<<endl;
    M.PrintRoad();
    //M.RemoveRoad("a","b");
    //M.PrintRoad();
    // M.RemoveRoad("d","e");
    // M.PrintRoad();
    
}

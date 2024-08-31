#include<iostream>
using namespace std;

class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node

    Node(int value) : data(value), next(nullptr) {;} // Constructor
};


class LinkedList {
private:
    Node* head;  // Pointer to the first node in the list

public:
    LinkedList() : head(nullptr) {}  // Constructor initializes an empty list

    // Method to insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);  // Create a new node
        if (head == nullptr) {            // If the list is empty
            head = newNode;               // Set the new node as the head
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {  // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;            // Insert the new node at the end
        }
    }

    // Method to display the list
    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";  // Print the data of the current node
            temp = temp->next;              // Move to the next node
        }
        std::cout << std::endl;
    }

    // Destructor to clean up memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList list;

    // Insert some values into the linked list
    list.insert(10);
    list.insert(20);
    list.insert(30);

    // Display the list
    std::cout << "Linked List: ";
    list.display();

    return 0;
}
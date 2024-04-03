#include <iostream>
#include <fstream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Function to create the first node
    void create(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        head = newNode;
    }

    // Function to add a node in sorted order
    void add(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (!head || value < head->data) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->data < value) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to delete a node
    void deleteNode(int value) {
        Node* temp = head;
        Node* prev = nullptr;

        // Traverse until the node to delete is found or end of list
        while (temp && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        // If node to delete is found
        if (temp) {
            // If it's the first node
            if (temp == head)
                head = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            cout << "Node with value " << value << " deleted." << endl;
        } else {
            cout << "Node with value " << value << " not found." << endl;
        }
    }

    // Function to get length of linked list
    int length() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to traverse and print elements of linked list
    void traverse() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to get head of the linked list
    Node* getHead() {
        return head;
    }

    // Destructor to deallocate memory
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    // Read data from file and populate linked list
    ifstream inputFile("input.txt");
    int value;
    LinkedList list;
    while (inputFile >> value) {
        if (!list.length())
            list.create(value);
        else
            list.add(value);
    }
    inputFile.close();

    // Interaction loop
    char choice;
    do {
        cout << "Choose an action:\n"
             << "a) Add a node\n"
             << "b) Delete a node\n"
             << "c) Enumerate the elements of the list\n"
             << "d) Length of the list\n"
             << "e) End\n";

        cin >> choice;

        switch (choice) {
            case 'a': {
                cout << "Enter value to add: ";
                cin >> value;
                list.add(value);
                break;
            }
            case 'b': {
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            }
            case 'c': {
                cout << "Elements of the list: ";
                // Traverse and print elements of the list using getHead()
                Node* temp = list.getHead();
                while (temp) {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
                break;
            }
            case 'd': {
                cout << "Length of the list: " << list.length() << endl;
                break;
            }
            case 'e': {
                // Store current linked list in output.txt
                ofstream outputFile("output.txt");
                Node* temp = list.getHead();
                while (temp) {
                    outputFile << temp->data << " ";
                    temp = temp->next;
                }
                outputFile.close();
                cout << "Exiting. Current list stored in output.txt." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please choose again." << endl;
                break;
            }
        }
    } while (choice != 'e');

    return 0;
}

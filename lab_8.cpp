#include <iostream>
#include <fstream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Global variable for the start of the linked list
Node* start = nullptr;

// Function prototypes
void create(int data);
void add(int data);
void remove(int data);
int length();
void traverse(bool increasing);
void storeListToFile();

// Function to create the very first node
void create(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    start = newNode;
}

// Function to insert numbers in sorted order
void add(int data) {
    if (start == nullptr || data < start->data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = start;
        start = newNode;
        return;
    }

    Node* current = start;
    Node* prev = nullptr;
    while (current != nullptr && current->data < data) {
        prev = current;
        current = current->next;
    }
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = current;
    prev->next = newNode;
}

// Function to delete a node
void remove(int data) {
    Node* current = start;
    Node* prev = nullptr;
    while (current != nullptr && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Not found" << endl;
        return;
    }
    if (prev == nullptr) {
        start = current->next;
    } else {
        prev->next = current->next;
    }
    delete current;
    cout << "Deleted " << data << endl;
}

// Function to find the length of the linked list
int length() {
    int count = 0;
    Node* current = start;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to traverse and print elements of the linked list
void traverse(bool increasing) {
    Node* current = start;
    if (increasing) {
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    } else {
        Node* prev = nullptr;
        while (start != nullptr) {
            Node* next = start->next;
            start->next = prev;
            prev = start;
            start = next;
        }
        start = prev;
        traverse(true);
    }
    cout << endl;
}

// Function to store the linked list to a file
void storeListToFile() {
    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        Node* current = start;
        while (current != nullptr) {
            outputFile << current->data << " ";
            current = current->next;
        }
        outputFile.close();
        cout << "Linked list stored in output.txt" << endl;
    } else {
        cout << "Unable to open output.txt for writing" << endl;
    }
}

int main() {
    // Create and populate the linked list from external file
    ifstream inputFile("numbers.txt");
    if (inputFile.is_open()) {
        int num;
        while (inputFile >> num) {
            if (start == nullptr) {
                create(num);
            } else {
                add(num);
            }
        }
        inputFile.close();
    } else {
        cout << "Unable to open numbers.txt" << endl;
        return 1;
    }

    // Actions loop
    int choice;
    do {
        cout << "Choose an action:" << endl;
        cout << "1. Add a node" << endl;
        cout << "2. Delete a node" << endl;
        cout << "3. Enumerate the elements of the list in increasing order" << endl;
        cout << "4. Enumerate the elements of the list in decreasing order" << endl;
        cout << "5. Length of the list" << endl;
        cout << "6. End and store the current linked list" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                add(data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter data to delete: ";
                cin >> data;
                remove(data);
                break;
            }
            case 3:
                cout << "Elements of the list in increasing order: ";
                traverse(true);
                break;
            case 4:
                cout << "Elements of the list in decreasing order: ";
                traverse(false);
                break;
            case 5:
                cout << "Length of the list: " << length() << endl;
                break;
            case 6:
                storeListToFile();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}

#include <iostream>
#include <algorithm> //for sorting
#include <string>

using namespace std;

struct Student {
    string name;
    int marks[3]; // Array to store marks of 3 courses
};

// Function to initialize student information
void initialize_Students(int n, Student* pointer_array[]) {
    for (int i = 0; i < n; ++i) {
        pointer_array[i] = new Student; // Allocate memory for each student
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> pointer_array[i]->name;
        cout << "Enter marks for Math, Chem, and Physics: ";
        for (int j = 0; j < 3; ++j) {
            cin >> pointer_array[i]->marks[j];
        }
    }
}

// Function to sort students name
void sort_Students(int n, Student* pointer_array[]) {
    sort(pointer_array, pointer_array + n, [](const Student* a, const Student* b) {
        return a->name < b->name;
    });
}

// Function to print sorted students list
void print_List(int n, Student* pointer_array[]) {
    cout << "Sorted List of Students:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Name: " << pointer_array[i]->name << "\tMarks: ";
        for (int j = 0; j < 3; ++j) {
            cout << pointer_array[i]->marks[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int size = 3;
    Student* pointer_array[size];

    initialize_Students(size, pointer_array);
    sort_Students(size, pointer_array);
    print_List(size, pointer_array);

    // Free allocated memory
    for (int i = 0; i < size; ++i) {
        delete pointer_array[i];
    }

    return 0;
}

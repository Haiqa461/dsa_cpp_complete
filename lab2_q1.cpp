#include <iostream>
#include <string>
#include <algorithm> // for sorting
#include <cmath>

using namespace std;
// Declare a structure named 'student'
struct Student {
    string name;
    int Math;
    int Chem;
    int Physics;
};
// 
void initial(int n, struct Student **pointer_array) {
    cout << "----------- Loading ----------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "[" << i + 1 << "]: " << "Enter the name of Student: ";
        cin >> pointer_array[i]->name;
        cout << endl;
        cout << "Enter the chemistry marks: ";
        cin >> pointer_array[i]->Math;
        cout << "Enter the physics marks: ";
        cin >> pointer_array[i]->Chem;
        cout << "Enter the math marks: ";
        cin >> pointer_array[i]->Physics;
        cout << endl;
    }

    return;
}

bool compareByName(const Student* a, const Student* b) {
    return a->name < b->name;
}

// sorting function
void sort(int n, struct student **pointer_array) {
    cout << "---------- Alphabetized order ----------" << endl;
    sort(pointer_array, pointer_array + n, compareByName);
    return;
}

void printing(int n, Student** pointer_array){
    for (int i = 0; i < n; i++) {
        cout << "[" << i + 1 << "]: " << "Name: " << pointer_array[i]->name
        << " Chemistry: " << pointer_array[i]->
        << " Physics: " << pointer_array[i]->
        << " Math: " << pointer_array[i]-> << endl;
       
    }
}


int main() {
    // Make an array of structures with size 10
    const int size = 10;
    Student students[size];
student* arr[size]; // array of structure
    student* pointer_array[size]; // pointer array points to structure.
    for (int i = 0; i < size ; i++) {
        pointer_array[i] = new Student; // new pointer structure & new multiples dynamic memory allocations.
    }
    cout << endl;
    initial(n, ptr_arr); // calling with original ptr_arr[] instead of data_arr[].
    sort(n, ptr_arr);
    printing(n, ptr_arr);
    cout << "Length of Function: " << length << endl;
    for (int i = 0; i < n; i++) {
        delete ptr_arr[i];
    }
    return 0;
// Initialize names and marks via user input
   

 // print the sorted list of students
  

    return 0;
}




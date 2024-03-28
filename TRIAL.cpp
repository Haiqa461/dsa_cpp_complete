// #include <iostream>
// #include <string>
// #include <algorithm> // Added for sorting
// #include <cmath>

// using namespace std;

// struct student {
//     string name;
//     double chem;
//     double phy;
//     double math;
// };

// int length = 0;

// void initial(int n, struct student **data_arr) {
//     cout << "----------- Loading ----------" << endl;
//     for (int i = 0; i < n; i++) {
//         cout << "[" << i + 1 << "]: " << "Enter the name of Student: ";
//         cin >> data_arr[i]->name;
//         cout << endl;
//         cout << "Enter the chemistry marks: ";
//         cin >> data_arr[i]->chem;
//         cout << "Enter the physics marks: ";
//         cin >> data_arr[i]->phy;
//         cout << "Enter the math marks: ";
//         cin >> data_arr[i]->math;
//         cout << endl;
//     }
//     cout << "---------- Please Wait ----------" << endl;
//     length = length + 1;
//     cout << endl;
//     return;
// }

// void calculate_average() {
//     // Your implementation for calculating average goes here
//     return;
// }

// bool compareByName(const student* a, const student* b) {
//     return a->name < b->name;
// }

// void sort(int n, struct student **data_arr) {
//     cout << "---------- Alphabetized order ----------" << endl;
//     sort(data_arr, data_arr + n, compareByName);
//     return;
// }

// void printing(int n, struct student **data_arr) {
//     cout << "---------- Loading -----------" << endl;
//     cout << endl << "---------- Recorded Data -----------" << endl;
//     for (int i = 0; i < n; i++) {
//         cout << "[" << i + 1 << "]: " << "Name: " << data_arr[i]->name
//             << " Chemistry: " << data_arr[i]->chem
//             << " Physics: " << data_arr[i]->phy
//             << " Math: " << data_arr[i]->math << endl;
//         double avg = (data_arr[i]->chem + data_arr[i]->phy + data_arr[i]->math) / 3.0;
//         cout << " Average: " << avg << endl;
//     }
//     cout << endl;
//     length = length + 1;
// }

// int main() {
//     int n;
//     cout << "Enter the number of student's data that you want to store in structure: ";
//     cin >> n;
//     cout << endl;
//     student* arr[n]; // array of structure
//     student* ptr_arr[n]; // pointer array points to structure.
//     for (int i = 0; i < n; i++) {
//         ptr_arr[i] = new student; // new pointer structure & new multiples dynamic memory allocations.
//     }
//     cout << endl;
//     initial(n, ptr_arr); // calling with original ptr_arr[] instead of data_arr[].
//     sort(n, ptr_arr);
//     printing(n, ptr_arr);
//     cout << "Length of Function: " << length << endl;
//     for (int i = 0; i < n; i++) {
//         delete ptr_arr[i];
//     }
//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
#include <new>
#include <fstream>
#include <time.h>
#include <string.h>
#include <ctime>
using namespace std;

struct element
{
    int r,c, *p;
};

void initialize_matrix(int row, int col, int *ptr, ifstream* file_in)
{
    int k;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            (*file_in) >> k;
            *(ptr + i*col + j) = k;
        }
    }
    return;
}

element addition_matrces(int r1, int c1, int r2, int c2, int *p1, int *p2)
{
    element matrix;
    try
    {
        if ((r1==r2) && (c1==c2))
        {
           cout<<"Processing addition of matrices"<<endl;
            matrix.c = c1;
            matrix.r = r1;
            matrix.p = new int [r1*c1];
            int a,b,c;
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    a= *(p1 + i*c1 + j);
                    b = *(p2 + i*c1 + j);
                    c = a + b;
                    *(matrix.p + i*c1 + j) = c;
                }
            }
        }
        else throw(c1);
    }
    catch(...)
    {
        cout<<"Addition is not possible at this time"<<endl;
        matrix.c = 0;
        matrix.r = 0;
        matrix.p = NULL;
    }
    return matrix;
}

element substraction_matrces(int r1, int c1, int r2, int c2, int *p1, int *p2)
{
    element matrix;
    try
    {
        if ((r1==r2) && (c1==c2))
        {
            cout<<"Processing subtraction of matrices"<<endl;
            matrix.c = c1;
            matrix.r = r1;
            matrix.p = new int [r1*c1];
            int a,b,c;
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    a= *(p1 + i*c1 + j);
                    b = *(p2 + i*c1 + j);
                    c = a - b;
                    *(matrix.p + i*c1 + j) = c;
                }
            }
        }
        else throw(c1);
    }
    catch(...)
    {
        cout<<"substraction is not possible at this time"<<endl;
        matrix.c = 0;
        matrix.r = 0;
        matrix.p = NULL;
    }
    return matrix;
}

void printing_matrix(int row, int col, int *ptr) {
    for (int i = 0; i < row; i++) {
        cout << "[";
        for (int j = 0; j < col; j++) {
            cout << " " << *ptr;
            ptr = ptr + 1;
        }
        cout << " ]" << endl;
    }
}

int main()
{
  int r1, c1;
  int r2, c2;
  ifstream myfile;

  
  myfile.open ("xy.txt");
  cout<<"The dimensions of matrix X are: ";
  myfile >> r1;cout<<" ";myfile>>c1;
  cout<<r1<<" "<<c1;
  cout<<endl;
  cout<<"The dimensions of matrix Y are: ";
  myfile >> r2;cout<<" ";myfile>>c2;
  cout<<r2<<" "<<c2;
  cout<<endl;
  int *p1, *p2;
  p1 = new int [r1*c1];
  p2 = new int [r2*c2];
  initialize_matrix(r1,c1,p1,&myfile);
  printing_matrix(r1,c1,p1);
  initialize_matrix(r2,c2,p2,&myfile);
  printing_matrix(r2,c2,p2);
  element matrix1, matrix2;
  matrix1 = addition_matrces(r1,c1,r2,c2,p1,p2);
  printing_matrix(matrix1.r, matrix1.c, matrix1.p);
  matrix2 = substraction_matrces(r1,c1,r2,c2,p1,p2);
  printing_matrix(matrix2.r, matrix2.c, matrix2.p);

  delete [] p1;
  delete [] p2;
  myfile.close(); 
  return 0;
}
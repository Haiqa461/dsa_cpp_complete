#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main(int argc, char *argv [])
{
    string A;
    try
    {
        if (argc != 3)
        {
           throw(argc);
        }
        else
        {
            cout<<"Lets start the program"<<endl;
            A = argv[0];
            cout<<"Write Program Name: "<<A<<endl;
            A = argv[1];
            cout<<"Name of program to be repeated: "<<A<<endl;
            A = argv[2];
            cout<<"How many times: "<<A<<" x "<<endl;

            // convertng string to number to int to repeatitions 
            int i, tau;
            stringstream ss;
            ss<<argv[2];
            ss>>tau;

            // printing how many times depends on user last input
            for (int i = 0; i <= tau; i++)
            {
                cout<<"[ "<<i<<" ]"<<argv[1]<<endl;
            }
        }
    }
    catch(...)
    {
        cout<<"This program has 3 parameters: "<<endl;
        cout<<"[1] Name of parameter like : Hello.exe"<<endl;
        cout<<"[2] Parametter- number of times you want to print Hello"<<endl;
        cout<<"[3] How many times you want to print the name of user: "<<endl;
        cout<<endl;
        cout<<"for e.g: Typing the following"<<endl;
        cout<<"Hello.exe 7 "<<endl;
        cout<<"Will print Hello seven Times "<<endl;
    }
    return 0;
}
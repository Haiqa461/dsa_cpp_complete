#include <iostream> 
#include <bits/stdc++.h> 
#include <string> 
#include <time.h>
using namespace std;
int main(int argc, char *argv[]) 
{
if (argc != 2) 
{
cout << "This program has 2 arguments:" << endl;
cout << " [1] Name of the program: Hello.exe " << endl;
cout << " [2] Parameter - number of times you want to print Hello" << endl; 
cout << "For e.g.: typing the following:"<< endl;
cout << "Hello.exe [7]" << endl;
cout << "Will print Hello seven times" << endl; 
}
else 
{
cout << "Lets start the program" << endl;
// Convert string number to integer number 
int length = strlen( argv[1] );
int tau = 0; 
int p, o = 1 ;
for( p = o -1 ; p > -1 ; p = p - 1 ) 
{
tau = tau + ( (int) argv[2][p] - 48 ) * o ; 
o = o * 10 ;
}
// Printing hello tau number of time 
for ( int i = 1; i <= tau; i++)
cout << "[" << i << "] Hello" << endl; 
} // end of else
return 0;
} // end of main function
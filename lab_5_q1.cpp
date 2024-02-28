#include<iostream>
#include<new>
using namespace std;


void print_array(int r, int c , int *ptr){
 int i,j;
    for (i=0; i< r ; i++){
     cout<<"[";

      for(j=0; j< c; j++){
    
        cout <<" "<< *ptr;
        ptr= ptr+1 ;
      }
        cout<< " ]"<< endl;
      
    }
return;

}

int main (){
    int c,r,i,j,k, a[0][0];
    int m,n,p,*p;
cout << "Enter dimensions for matrix (m x n): ";
    cin >> r >> c;
    p= new int[r*c];
cout<<"Enter a number till you are done"<< endl;
cout<<"press enter after each entry"<<endl;

for (i=0, i < r , i ++ ){
    for(j=0, j<c ,j++){
        cin>>k;
        *(p+i*c+j) = k ;
    }
}

cout<<endl<<"your matrix";

return 0 ;

}

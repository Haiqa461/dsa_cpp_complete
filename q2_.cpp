#include<iostream>
#include<math.h>
using namespace std;
// I want to calculate arithmatic series of some following function.

double ArithmaticSeriesFunction(double a, double d, double n){
	return (n/2.0)*((2*a)+(n-1)*d);
}
// Again code for geometric series.
double geometricSeries(double a, double n, double r){
	if(r>0){
		return (a*(pow(r,n)-1))/(r-1);
	}
	else if(r<0){
		return (a*(1-pow(r,n)))/(1-r);
	}
}
double infinteGeometricSeries(double r, double a){

	if(r>1){
		for(float i=0.1;i<1.0;i++){
			return a/(r-1);	
}

	}
	else if(r<1){
		for(float i=0.1;i<1.0;i++){
			return a/(1-r);
		}
	}


}
// Now its time to call this fuction into the main function.
int main(){
	double a, d, r; int n;
	char option;
	cout<<"Welcome To Series Calculator"<<endl;
	cout<<"Enter value of a: ";cin>>a;cout<<endl;
	cout<<"Enter value of r: "; cin>>r; cout<<endl;
	cout<<"Enter the value to calculate N number of Geometric Series: "; cin>>n; cout<<endl;
	cout<<"What you to calculate from the following:"<<endl;
	cout<<"1.Sum of Arithmatic Series. \n2.Sum of Geometric Series. \n3.Sum of Infinte Geometric Series."<<endl;
	cout<<endl;cin>>option;
	switch (option){
		case'1':
			cout<<"The Arithmatic Series Expansion is here: "<<ArithmaticSeriesFunction(a, d, n)<<endl;
			break;
		case'2':
			cout<<"The Finite Geometric Series: "<<geometricSeries(a,n,r)<<endl;
			break;
		case'3':
			cout<<"The Infinte Geometric Series: "<<infinteGeometricSeries(r,a)<<endl;
			break;
		default:
			cout<<"Incorrect Choice::::"<<endl;
			break;
	}	
	return 0;
}

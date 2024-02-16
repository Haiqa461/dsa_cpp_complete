#include <iostream>
#include <math.h>
using namespace std;

struct GeometricSeries
{
  double X;
  double Y; 
};

// writing to calculate X "sum of geometric  series"
GeometricSeries geometric_series(double a, double r, int n) {
    GeometricSeries result;
    if (r > 1) {
        result.X = (a * (pow(r, n) - 1)) / (r - 1);
    } else if (r < 1) {
        result.X = a * (1 - pow(r, n)) / (1 - r);
    } else {
        cout << "Invalid input \n r should be a finite value " << endl;
        result.X = 0;
    }
// code for Y "sum of infinite geometric series"
    if (r < 1) {
        result.Y=  a / (1 - r);
    } else if (r > 1) {
        result.Y = a / (r - 1);
    } else {
        cout << " Invalid input \n r should be less than 1" << endl;
        result.Y = 0;
    }
}

int main() {
    double a, r;int n;
    GeometricSeries result = geometric_series(a,r,n);

    cout << "Enter the first term (a): ";
    cin >> a;
    cout << "Enter the common ratio (r): ";
    cin >> r;
    cout<<"Enter the value to calculate N number of Geometric Series: "; cin>>n; cout<<endl;
    cout<<"X: "<<result.X<<endl;
    cout<<"Y: "<<result.Y<<endl;

    return 0;
    
}



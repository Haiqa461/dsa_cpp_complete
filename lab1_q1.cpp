#include<iostream>
using namespace std;

#include <iostream>

double arithmeticSeriesSum(double a, double d, int n) {
    // Sn = n/2 * [2a + (n-1)d]
    double sum = n * (2 * a + (n - 1) * d) / 2;
    return sum;
}

int main() {
    // Example usage:
    double a = 3.0;  // First term
    double d = 2.0;  // Common difference
    int n = 5;       // Number of terms

    double result = arithmeticSeriesSum(a, d, n);

    std::cout << "Sum of the arithmetic series: " << result << std::endl;

    return 0;
}
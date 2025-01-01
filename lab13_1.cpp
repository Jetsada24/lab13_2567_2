#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double arr[], int size, double result[]) {
    double sum = 0.0, sumSquares = 0.0, product = 1.0, harmonicSum = 0.0;
    double maxVal = arr[0], minVal = arr[0];

    for (int i = 0; i < size; ++i) {
        sum += arr[i];
        sumSquares += arr[i] * arr[i];
        product *= arr[i];
        harmonicSum += 1.0 / arr[i];
        maxVal = max(maxVal, arr[i]);
        minVal = min(minVal, arr[i]);
    }

    double mean = sum / size;
    double variance = (sumSquares / size) - (mean * mean);
    double stdDev = sqrt(variance);
    double geoMean = pow(product, 1.0 / size);
    double harmMean = size / harmonicSum;

    result[0] = mean;
    result[1] = stdDev;
    result[2] = geoMean;
    result[3] = harmMean;
    result[4] = maxVal;
    result[5] = minVal;
}

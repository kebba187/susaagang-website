#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to check if the distribution density property is satisfied
bool checkDistributionDensity(const vector<double>& distribution) {
    double sum = 0.0;
    for (double yi : distribution) {
        sum += yi;
    }
    return abs(sum - 1.0) < 1e-6; // Tolerance for floating point comparison
}

// Function to calculate the mathematical expectation
double calculateExpectation(const vector<double>& x_values, const vector<double>& y_values) {
    double expectation = 0.0;
    for (size_t i = 0; i < x_values.size(); ++i) {
        expectation += x_values[i] * y_values[i];
    }
    return expectation;
}

// Function to calculate the variance
double calculateVariance(const vector<double>& x_values, const vector<double>& y_values, double expectation) {
    double variance = 0.0;
    for (size_t i = 0; i < x_values.size(); ++i) {
        variance += y_values[i] * pow((x_values[i] - expectation), 2);
    }
    return variance;
}

int main() {
    vector<double> x_values, y_values;
    int n;

    // Input the number of terms in the distribution series
    cout << "Enter the number of terms in the distribution series: ";
    cin >> n;

    // Input the distribution series
    cout << "Enter the xi values:" << endl;
    for (int i = 0; i < n; ++i) {
        double xi;
        cin >> xi;
        x_values.push_back(xi);
    }

    cout << "Enter the yi values:" << endl;
    for (int i = 0; i < n; ++i) {
        double yi;
        cin >> yi;
        y_values.push_back(yi);
    }

    // Check if distribution density property is satisfied
    if (!checkDistributionDensity(y_values)) {
        cout << "Error: Distribution density property is not satisfied. Aborting." << endl;
        return 1;
    }

    // Calculate the mathematical expectation
    double expectation = calculateExpectation(x_values, y_values);
    cout << "Mathematical Expectation (M(x)): " << expectation << endl;

    // Calculate the variance
    double variance = calculateVariance(x_values, y_values, expectation);
    cout << "Variance (D(x)): " << variance << endl;

    // Calculate the mean square deviation
    double meanSquareDeviation = sqrt(variance);
    cout << "Mean Square Deviation (σ): " << meanSquareDeviation << endl;

    return 0;
}

#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - Chef is a boy, so total boys = A + 1.
 * - Total girls = B.
 * - Each boy eats 4 slices, each girl eats 3 slices.
 * - Total slices needed = (A + 1) * 4 + B * 3.
 * - Each pizza has 8 slices.
 * - Number of pizzas needed = ceil(Total slices / 8).
 * - Using integer arithmetic, ceil(x / y) = (x + y - 1) / y.
 * 
 * Input Format:
 * - The problem specifies a single line containing A and B.
 * - No test case count T is provided.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    // Read A and B directly as per the problem statement
    if (cin >> A >> B) {
        long long total_boys = A + 1;
        long long total_girls = B;
        
        long long total_slices = (total_boys * 4) + (total_girls * 3);
        
        // Calculate ceiling division: (total_slices + 7) / 8
        long long pizzas_needed = (total_slices + 7) / 8;
        
        cout << pizzas_needed << endl;
    }

    return 0;
}
#include <iostream>
#include <cmath>
#include <cstdlib>

/**
 * Problem: Interesting Match
 * Logic: The match is interesting if |X - Y| <= 2.
 * Constraints: 0 <= X, Y <= 10.
 * Note: The problem input does not specify a number of test cases T.
 */

using namespace std;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    // Read X and Y directly as per the problem format
    if (cin >> x >> y) {
        // Calculate absolute difference
        int diff = abs(x - y);
        
        // Check condition: |X - Y| <= 2
        if (diff <= 2) {
            cout << "Interesting" << endl;
        } else {
            cout << "Boring" << endl;
        }
    }
    
    return 0;
}
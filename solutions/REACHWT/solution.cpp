#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - 1kg weight costs 20.
 * - 2kg weight costs 30.
 * - Cost per kg for 1kg weight = 20.
 * - Cost per kg for 2kg weight = 15.
 * 
 * Strategy:
 * To minimize cost, maximize the number of 2kg weights used.
 * - If N is even: Use (N/2) weights of 2kg. Total cost = (N/2) * 30.
 * - If N is odd: Use one 1kg weight and (N-1)/2 weights of 2kg. 
 *   Total cost = 20 + ((N-1)/2) * 30.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        if (!(cin >> n)) break;

        if (n % 2 == 0) {
            // Even N: Use only 2kg weights
            cout << (n / 2) * 30 << "\n";
        } else {
            // Odd N: Use one 1kg weight, remainder is even
            cout << 20 + ((n - 1) / 2) * 30 << "\n";
        }
    }

    return 0;
}
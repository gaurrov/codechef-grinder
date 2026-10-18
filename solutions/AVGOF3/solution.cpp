#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find three distinct integers A1, A2, A3 such that:
 * (A1 + A2 + A3) / 3 = X
 * This implies A1 + A2 + A3 = 3 * X.
 * 
 * A simple construction is to pick numbers around X.
 * Let A1 = X - 1, A2 = X, A3 = X + 1.
 * Sum = (X - 1) + X + (X + 1) = 3X.
 * Mean = 3X / 3 = X.
 * 
 * Constraints:
 * 1 <= A1, A2, A3 <= 1000
 * 2 <= X <= 100
 * 
 * If X = 2:
 * A1 = 2-1 = 1, A2 = 2, A3 = 2+1 = 3.
 * 1, 2, 3 are distinct and within [1, 1000].
 * 
 * This construction works for all X >= 2.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;
        
        // Using the construction: X-1, X, X+1
        // Since X >= 2, X-1 >= 1, which satisfies the lower bound.
        // Since X <= 100, X+1 <= 101, which satisfies the upper bound.
        // The numbers are distinct because (X-1) < X < (X+1).
        cout << (x - 1) << " " << x << " " << (x + 1) << "\n";
    }

    return 0;
}
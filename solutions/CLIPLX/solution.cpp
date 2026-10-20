#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem: CLIPLX
 * Logic: 
 * Let W be the number of wins.
 * Points = 2 * W + (Ties).
 * To minimize W, we maximize Ties.
 * Max Ties = Y - W.
 * Total Points = 2W + (Y - W) = W + Y.
 * We need W + Y >= X, so W >= X - Y.
 * Since W cannot be negative, W = max(0, X - Y).
 */

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // If X <= Y, we can get all points by tying, so 0 wins needed.
        // If X > Y, we need (X - Y) wins.
        int wins = max(0, x - y);
        cout << wins << "\n";
    }
    
    return 0;
}
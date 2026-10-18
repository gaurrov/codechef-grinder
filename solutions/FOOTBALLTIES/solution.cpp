#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A win gives 3 points, a loss gives 0 points, and a draw gives 1 point.
 * Let wA be the number of wins for team A, lA be the number of losses for team A, and dA be the number of draws.
 * Let wB be the number of wins for team B, lB be the number of losses for team B, and dB be the number of draws.
 * 
 * Since they play against each other:
 * wA = lB
 * lA = wB
 * dA = dB = D (number of draws)
 * 
 * Score for A: X = 3 * wA + D
 * Score for B: Y = 3 * wB + D
 * 
 * We want to minimize D.
 * From the equations:
 * X % 3 = (3 * wA + D) % 3 = D % 3
 * Y % 3 = (3 * wB + D) % 3 = D % 3
 * 
 * This implies that D must have the same remainder as X (and Y) when divided by 3.
 * Since we want to minimize D, we look at the remainder of X mod 3.
 * D = X % 3.
 * 
 * Let's verify:
 * If X = 1, Y = 1: D = 1 % 3 = 1. (1 = 3*0 + 1, 1 = 3*0 + 1). Correct.
 * If X = 3, Y = 0: D = 3 % 3 = 0. (3 = 3*1 + 0, 0 = 3*0 + 0). Correct.
 * If X = 11, Y = 5: D = 11 % 3 = 2. (11 = 3*3 + 2, 5 = 3*1 + 2). Correct.
 * If X = 9, Y = 9: D = 9 % 3 = 0. (9 = 3*3 + 0, 9 = 3*3 + 0). Correct.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // The number of draws D must satisfy:
        // X = 3 * wA + D
        // Y = 3 * wB + D
        // This implies X % 3 == D % 3 and Y % 3 == D % 3.
        // The smallest non-negative integer D satisfying this is X % 3.
        cout << (x % 3) << "\n";
    }

    return 0;
}
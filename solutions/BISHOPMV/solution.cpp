#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A bishop moves along diagonals.
 * Two cells (x1, y1) and (x2, y2) are on the same diagonal if:
 * 1. x1 + y1 == x2 + y2 (Anti-diagonal)
 * 2. x1 - y1 == x2 - y2 (Main diagonal)
 * 
 * If they are on the same diagonal, the distance is 1.
 * If they are not on the same diagonal, we check if they are reachable.
 * A bishop can only reach cells of the same color as the starting cell.
 * The color of a cell (x, y) is determined by (x + y) % 2.
 * If (x1 + y1) % 2 != (x2 + y2) % 2, it is impossible (-1).
 * If they are the same color and not on the same diagonal, it always takes 2 moves.
 */

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Check if same color
    if ((x1 + y1) % 2 != (x2 + y2) % 2) {
        cout << -1 << "\n";
        return;
    }

    // Check if same diagonal
    // Condition 1: x1 + y1 == x2 + y2
    // Condition 2: x1 - y1 == x2 - y2
    if (abs(x1 - x2) == abs(y1 - y2)) {
        cout << 1 << "\n";
    } else {
        // Same color but not same diagonal, always 2 moves
        cout << 2 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
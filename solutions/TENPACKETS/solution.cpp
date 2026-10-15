#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs 10 packets.
 * Options:
 * - 2 packets for X
 * - 4 packets for Y
 * 
 * We need to represent 10 as a sum of 2s and 4s.
 * Possible combinations (number of 4-packs, number of 2-packs):
 * 1. (0, 5): 0 * Y + 5 * X = 5X
 * 2. (1, 3): 1 * Y + 3 * X = Y + 3X
 * 3. (2, 1): 2 * Y + 1 * X = 2Y + X
 * 
 * We need to find the minimum of these three values.
 * Given constraints: X < Y <= 2X.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    // Calculate the three possible ways to get 10 packets
    long long option1 = 5 * X;
    long long option2 = Y + 3 * X;
    long long option3 = 2 * Y + X;

    // Find the minimum of the three options
    long long min_cost = min({option1, option2, option3});

    cout << min_cost << "\n";
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
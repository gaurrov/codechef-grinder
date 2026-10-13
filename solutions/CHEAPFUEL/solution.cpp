#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Petrol price after K months: P = X + (A * K)
 * Diesel price after K months: D = Y + (B * K)
 * 
 * We compare P and D:
 * - If P < D, print PETROL
 * - If D < P, print DIESEL
 * - If P == D, print SAME PRICE
 * 
 * Complexity: O(1) per test case, O(T) total.
 * Space Complexity: O(1).
 */

void solve() {
    long long X, Y, A, B, K;
    if (!(cin >> X >> Y >> A >> B >> K)) return;

    long long final_petrol = X + (A * K);
    long long final_diesel = Y + (B * K);

    if (final_petrol < final_diesel) {
        cout << "PETROL" << "\n";
    } else if (final_diesel < final_petrol) {
        cout << "DIESEL" << "\n";
    } else {
        cout << "SAME PRICE" << "\n";
    }
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
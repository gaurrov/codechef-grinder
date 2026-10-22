#include <iostream>

/**
 * Problem: RATING
 * Logic:
 * We are given X + Y = S, with X > 0 and Y < 0.
 * We want to maximize X * Y.
 * Since Y = S - X, the product is X(S - X) = SX - X^2.
 * To maximize this, we want X and Y to be as close to each other as possible.
 * However, Y must be negative. The largest negative integer is -1.
 * If we set Y = -1, then X = S + 1.
 * The product is (S + 1) * (-1) = -(S + 1).
 */

using namespace std;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        long long S;
        cin >> S;
        // The maximum product is -(S + 1)
        cout << -(S + 1) << "\n";
    }

    return 0;
}
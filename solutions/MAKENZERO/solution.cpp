#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to represent N as 3*x + 4*y = N, where x, y >= 0.
 * This is a variation of the Frobenius Coin Problem (or Change-Making Problem).
 * For two numbers a and b, any integer N > (a*b - a - b) can be represented 
 * as a linear combination of a and b with non-negative coefficients.
 * Here, a=3 and b=4. The largest number that cannot be represented is 
 * (3*4 - 3 - 4) = 5.
 * 
 * Let's check small values:
 * 1: NO
 * 2: NO
 * 3: YES (3*1)
 * 4: YES (4*1)
 * 5: NO
 * 6: YES (3*2)
 * 7: YES (3*1 + 4*1)
 * 8: YES (4*2)
 * 9: YES (3*3)
 * 10: YES (3*2 + 4*1)
 * 11: YES (3*1 + 4*2)
 * 12: YES (3*4 or 4*3)
 * 
 * It appears that for all N >= 6, the answer is YES.
 * The only values that cannot be formed are 1, 2, and 5.
 */

void solve() {
    int n;
    cin >> n;
    if (n == 1 || n == 2 || n == 5) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
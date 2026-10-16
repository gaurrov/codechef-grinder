#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to distribute N chocolates into three jars (a, b, c) such that:
 * 1. a + b + c = N
 * 2. At least one jar has an odd number of chocolates.
 * 3. Exactly two jars have the same number of chocolates.
 * 4. a, b, c >= 1
 * 
 * Strategy:
 * Let the two equal jars have x chocolates each.
 * Then the third jar has (N - 2x) chocolates.
 * We need N - 2x >= 1, so 2x <= N - 1, or x <= (N - 1) / 2.
 * 
 * Case 1: N is even.
 * Let x = 1. Then the jars are (1, 1, N - 2).
 * - Two jars are equal (1, 1).
 * - At least one is odd (1 is odd).
 * - Valid for N >= 4.
 * 
 * Case 2: N is odd.
 * Let x = (N - 1) / 2. Then the jars are (x, x, 1).
 * - Two jars are equal (x, x).
 * - At least one is odd (1 is odd).
 * - Valid for N >= 3.
 * 
 * Both strategies work for all N >= 4.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        if (n % 2 == 0) {
            // Even N: (1, 1, N-2)
            // Example N=4: 1, 1, 2. (Two 1s, one is odd)
            cout << 1 << " " << 1 << " " << (n - 2) << "\n";
        } else {
            // Odd N: ((N-1)/2, (N-1)/2, 1)
            // Example N=7: 3, 3, 1. (Two 3s, all are odd)
            long long x = (n - 1) / 2;
            cout << x << " " << x << " " << 1 << "\n";
        }
    }

    return 0;
}
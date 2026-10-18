#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array contains the first N positive odd numbers.
 * The first N positive odd numbers are: 1, 3, 5, ..., (2N - 1).
 * The sum of the first N positive odd numbers is N^2.
 * 
 * Let x be the number that appears K times.
 * The array consists of all N odd numbers once, plus (K-1) extra copies of x.
 * The sum S is given by:
 * S = (Sum of first N odd numbers) + (K - 1) * x
 * S = N^2 + (K - 1) * x
 * 
 * Rearranging for x:
 * (K - 1) * x = S - N^2
 * x = (S - N^2) / (K - 1)
 * 
 * Constraints:
 * N <= 10^4, N^2 <= 10^8.
 * S <= 10^9.
 * K <= 10^4.
 * All calculations fit within standard 64-bit integers (long long).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, s;
        cin >> n >> k >> s;

        // Calculate the sum of the first N odd numbers
        long long sum_n = n * n;

        // Calculate the difference
        long long diff = s - sum_n;

        // Calculate the repeated number
        long long x = diff / (k - 1);

        cout << x << "\n";
    }

    return 0;
}
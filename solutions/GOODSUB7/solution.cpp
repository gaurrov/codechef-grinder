#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A sequence is "good" if the parity of adjacent elements is different.
 * We want to find the length of the longest subsequence that alternates parity.
 * 
 * Let:
 * - odd_len: length of the longest good subsequence ending in an odd number.
 * - even_len: length of the longest good subsequence ending in an even number.
 * 
 * For each element x in A:
 * - If x is odd, it can extend any good subsequence ending in an even number.
 *   New odd_len = even_len + 1.
 * - If x is even, it can extend any good subsequence ending in an odd number.
 *   New even_len = odd_len + 1.
 * 
 * This DP approach correctly handles all possible starting elements.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int odd_len = 0;
    int even_len = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] % 2 != 0) {
            // Current is odd, can extend a sequence ending in even
            odd_len = even_len + 1;
        } else {
            // Current is even, can extend a sequence ending in odd
            even_len = odd_len + 1;
        }
    }

    cout << max(odd_len, even_len) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
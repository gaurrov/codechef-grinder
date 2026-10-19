#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to turn all 1s into 0s.
 * 1. If there are no 1s, the answer is 0.
 * 2. If there are no adjacent 1s, we can flip all 1s in a single operation.
 *    The answer is 1.
 * 3. If there are adjacent 1s, we need to check if we can do it in 2 operations.
 *    Can we always do it in 2? Yes.
 *    In the first operation, we can pick all 1s at odd positions (relative to the string).
 *    In the second operation, we can pick all 1s at even positions.
 *    Since no two adjacent 1s exist in the same set, this is valid.
 *    The only case where we might need more than 2 is if we have adjacent 1s,
 *    but the problem allows us to pick any non-adjacent set.
 *    Actually, if we have adjacent 1s, we can split the 1s into two sets:
 *    Set 1: All 1s at indices i such that i is odd.
 *    Set 2: All 1s at indices i such that i is even.
 *    Since no two adjacent indices have the same parity, both sets are valid.
 *    Thus, the answer is at most 2.
 *    The only condition for 2 is if there exists at least one pair of adjacent 1s.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool has_one = false;
    bool has_adjacent_ones = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            has_one = true;
            if (i + 1 < N && S[i + 1] == '1') {
                has_adjacent_ones = true;
            }
        }
    }

    if (!has_one) {
        cout << 0 << "\n";
    } else if (has_adjacent_ones) {
        cout << 2 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
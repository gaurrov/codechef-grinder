#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array X and a target array Y.
 * We need to find an index i (1-based) such that if we set P = X[i-1],
 * and generate a sequence Y' by sorting pairs (|X[j] - P|, X[j]),
 * then Y' must be exactly equal to Y.
 * 
 * Constraints: N <= 100.
 * This allows an O(N^2 log N) approach, which is well within the 1s time limit.
 * For each possible pivot index i from 1 to N:
 * 1. Calculate P = X[i-1].
 * 2. Create a list of pairs (abs(X[j] - P), X[j]).
 * 3. Sort the list based on the defined criteria.
 * 4. Extract the second elements and compare with Y.
 * 5. If they match, return i.
 * 6. If no index works, return -1.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i) cin >> X[i];
    for (int i = 0; i < N; ++i) cin >> Y[i];

    for (int i = 0; i < N; ++i) {
        int P = X[i];
        vector<pair<int, int>> L(N);
        for (int j = 0; j < N; ++j) {
            L[j] = {abs(X[j] - P), X[j]};
        }

        // Sort based on distance, then value
        sort(L.begin(), L.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        bool match = true;
        for (int k = 0; k < N; ++k) {
            if (L[k].second != Y[k]) {
                match = false;
                break;
            }
        }

        if (match) {
            cout << (i + 1) << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
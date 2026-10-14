#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence of 0s and 1s representing a queue.
 * A person is at index i if A[i] == 1.
 * Social distancing is followed if for any two people at indices i and j (i < j),
 * the distance (j - i) is at least 6.
 * 
 * Algorithm:
 * Keep track of the index of the last person seen.
 * Iterate through the array. If we find a person at index 'i' and we have seen
 * a person before at 'last_pos', check if (i - last_pos) < 6.
 * If it is, social distancing is violated.
 * Update 'last_pos' to 'i' whenever a new person is found.
 * 
 * Complexity:
 * Time: O(N) per test case, where N is the number of spots.
 * Space: O(1) auxiliary space (excluding input storage).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int last_pos = -10; // Initialize with a value that ensures no false violation
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            if (i - last_pos < 6) {
                possible = false;
                // We don't break immediately to consume the rest of the input,
                // but we could break if we read the whole array first.
            }
            last_pos = i;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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
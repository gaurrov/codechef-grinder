#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want all black cells (1s) to form a contiguous block.
 * We can only change white (0) to black (1).
 * 
 * If there are no 1s, the condition is already satisfied (0 changes).
 * If there are 1s, let the first 1 be at index 'first' and the last 1 be at index 'last'.
 * To make all 1s contiguous, every cell between 'first' and 'last' must be 1.
 * Since we can only change 0 to 1, we must change every 0 in the range [first, last] to 1.
 * 
 * The number of changes required is simply the count of 0s in the range [first, last].
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int first = -1;
    int last = -1;

    // Find the indices of the first and last '1'
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    // If no '1's exist, 0 changes are needed
    if (first == -1) {
        cout << 0 << "\n";
        return;
    }

    // Count the number of '0's between the first and last '1'
    int changes = 0;
    for (int i = first; i <= last; ++i) {
        if (S[i] == '0') {
            changes++;
        }
    }

    cout << changes << "\n";
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
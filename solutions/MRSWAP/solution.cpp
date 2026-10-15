#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array A of size 2N.
 * We can swap A[i] with A[2N + 1 - i] (1-indexed).
 * This means for each pair (A[i], A[2N + 1 - i]), we can choose which one 
 * goes into the first half and which one goes into the second half.
 * To maximize the sum of the first half (A[1]...A[N]), for each pair 
 * (A[i], A[2N + 1 - i]), we should pick the maximum of the two values 
 * to be in the first half.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the array.
 */

void solve() {
    int N;
    cin >> N;
    int size = 2 * N;
    vector<int> A(size);
    for (int i = 0; i < size; ++i) {
        cin >> A[i];
    }

    long long max_sum = 0;
    // We iterate from 0 to N-1.
    // The mirror element of A[i] is A[2N - 1 - i].
    for (int i = 0; i < N; ++i) {
        int val1 = A[i];
        int val2 = A[2 * N - 1 - i];
        max_sum += max(val1, val2);
    }

    cout << max_sum << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
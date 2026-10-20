#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sorted list A of size N.
 * For each A[i], we need to find the count of elements strictly greater than A[i].
 * Since the array is sorted, all elements strictly greater than A[i] will appear 
 * after the last occurrence of A[i].
 * 
 * Let the last index where A[i] occurs be 'last_idx'.
 * The number of elements strictly greater than A[i] is simply (N - 1 - last_idx).
 * 
 * Algorithm:
 * 1. For each test case, read N and the array A.
 * 2. Since the array is sorted, we can find the last occurrence of each value.
 * 3. Alternatively, for each A[i], we can use upper_bound to find the first element 
 *    strictly greater than A[i]. The number of elements strictly greater is 
 *    (A.end() - upper_bound(A.begin(), A.end(), A[i])).
 * 4. This approach is O(N log N) per test case, which is well within the limits 
 *    given N <= 100 and T <= 100.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        // upper_bound returns an iterator to the first element > A[i]
        auto it = upper_bound(A.begin(), A.end(), A[i]);
        // The number of elements strictly greater is the distance from it to the end
        int count = distance(it, A.end());
        cout << count << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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
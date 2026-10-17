#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N and we want to transform it into a permutation
 * of {1, 2, ..., N} using only increment operations.
 * 
 * 1. Since we can only increase elements, if an element A[i] is already greater 
 *    than N, it is impossible to make it part of a permutation of size N.
 * 2. To minimize the total number of operations, we should sort the array A first.
 *    Let the sorted array be A'.
 * 3. After sorting, we want to map each A'[i] to a unique value in {1, 2, ..., N}.
 *    The optimal strategy is to map the smallest elements of A' to the smallest 
 *    available values in the permutation.
 * 4. Specifically, if A'[i] > (i + 1), it is impossible to reach the value (i + 1)
 *    because we can only increase values. If A'[i] <= (i + 1), the cost to 
 *    transform A'[i] to (i + 1) is (i + 1) - A'[i].
 * 
 * Algorithm:
 * 1. Sort the array A.
 * 2. Iterate from i = 0 to N-1:
 *    - If A[i] > i + 1, return -1.
 *    - Otherwise, add (i + 1 - A[i]) to the total operations count.
 * 3. Print the total count.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long operations = 0;
    for (int i = 0; i < N; ++i) {
        // The target value for the i-th smallest element is (i + 1)
        if (A[i] > (i + 1)) {
            cout << -1 << "\n";
            return;
        }
        operations += ((i + 1) - A[i]);
    }

    cout << operations << "\n";
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
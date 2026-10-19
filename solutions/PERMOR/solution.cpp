#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We need A[i] != (A[i-1] | A[i-2]).
 * If we output the permutation in descending order: N, N-1, ..., 1.
 * For any i >= 3:
 * A[i-1] > A[i] and A[i-2] > A[i].
 * The bitwise OR of two numbers is always greater than or equal to the maximum of the two numbers.
 * Therefore, (A[i-1] | A[i-2]) >= max(A[i-1], A[i-2]) > A[i].
 * Thus, A[i] can never equal (A[i-1] | A[i-2]).
 */

void solve() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; --i) {
        cout << i << (i == 1 ? "" : " ");
    }
    cout << "\n";
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
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We can swap any two elements A[i] and A[j] if |i - j| > 1.
 * 
 * Case N = 1: Always sorted. YES.
 * Case N = 2: If A[1] <= A[2], YES. If A[1] > A[2], we cannot swap (distance is 1), so NO.
 * Case N = 3: We can swap (1, 3). This allows us to reach any permutation of the array 
 * because we can swap (1, 3), then (1, 2) is not possible, but we can swap (1, 3) 
 * and (2, 3) is not possible. Wait, let's re-evaluate.
 * 
 * For N >= 4:
 * We can swap (i, j) if |i - j| >= 2.
 * With N >= 4, we can move any element to any position.
 * For example, to swap adjacent elements A[i] and A[i+1]:
 * If we have an element at index k where |k-i| >= 2 and |k-(i+1)| >= 2, we can use it as a buffer.
 * With N >= 4, such a k always exists.
 * Thus, for N >= 4, we can perform any permutation, so the answer is always YES.
 * 
 * Case N = 3:
 * We can swap (1, 3). We cannot swap (1, 2) or (2, 3).
 * This means we can reach permutations: (1,2,3), (3,2,1).
 * If the array is already sorted, YES.
 * If we swap (1, 3), we get (A[3], A[2], A[1]). If this is sorted, YES.
 * Otherwise, NO.
 * 
 * Summary:
 * N=1: YES
 * N=2: YES if A[0] <= A[1], else NO
 * N=3: YES if sorted or if swapping ends results in sorted
 * N>=4: YES
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    if (N == 1) {
        cout << "YES" << "\n";
    } else if (N == 2) {
        if (A[0] <= A[1]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else if (N == 3) {
        // Check if already sorted
        bool sorted = true;
        for (int i = 0; i < N - 1; ++i) if (A[i] > A[i + 1]) sorted = false;
        if (sorted) {
            cout << "YES" << "\n";
            return;
        }
        // Swap 1st and 3rd
        swap(A[0], A[2]);
        sorted = true;
        for (int i = 0; i < N - 1; ++i) if (A[i] > A[i + 1]) sorted = false;
        if (sorted) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else {
        // For N >= 4, we can always sort the array
        cout << "YES" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * John Jackson (A) wants to have strictly more votes than Jack Johnson (B).
 * To maximize John's total votes with the minimum number of swaps, we should 
 * always swap the smallest pack from John with the largest pack from Jack, 
 * provided the smallest pack from John is smaller than the largest pack from Jack.
 * 
 * Algorithm:
 * 1. Calculate current sums of A and B.
 * 2. If sum(A) > sum(B), return 0 swaps.
 * 3. Sort A in ascending order and B in descending order.
 * 4. Iterate through the sorted arrays, swapping A[i] and B[i] if A[i] < B[i].
 * 5. Update sums and increment swap count.
 * 6. If at any point sum(A) > sum(B), return the current swap count.
 * 7. If we exhaust all possible swaps and sum(A) <= sum(B), return -1.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(M);
    long long sumA = 0, sumB = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sumA += A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
        sumB += B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<long long>());

    int swaps = 0;
    int limit = min(N, M);
    
    for (int i = 0; i <= limit; ++i) {
        if (sumA > sumB) {
            cout << swaps << "\n";
            return;
        }
        
        if (i < limit && A[i] < B[i]) {
            sumA = sumA - A[i] + B[i];
            sumB = sumB - B[i] + A[i];
            swaps++;
        } else {
            break;
        }
    }

    cout << -1 << "\n";
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
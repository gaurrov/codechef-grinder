#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cups with amounts A_i.
 * In one operation, we move all water from cup i to cup j.
 * We must perform exactly K operations.
 * To maximize the water in one cup, we want to aggregate as much water as possible into one cup.
 * 
 * Each operation reduces the number of non-empty cups by 1 (unless we move from an empty cup, 
 * but that would be suboptimal).
 * With K operations, we can merge at most K+1 cups into one.
 * 
 * If K >= N-1, we can merge all N cups into one single cup. The result is the sum of all A_i.
 * If K < N-1, we can pick the K+1 largest values from the array and sum them up.
 * 
 * Why?
 * Each operation allows us to add the contents of one cup to another.
 * After K operations, we have effectively combined K+1 initial cups into one.
 * To maximize the result, we should pick the K+1 largest values from the initial array.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort in descending order to easily pick the largest values
    sort(A.rbegin(), A.rend());

    // We can merge at most K+1 cups.
    // If K >= N-1, we can merge all N cups.
    int num_to_merge = min((long long)N, (long long)K + 1);

    long long max_water = 0;
    for (int i = 0; i < num_to_merge; ++i) {
        max_water += A[i];
    }

    cout << max_water << "\n";
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
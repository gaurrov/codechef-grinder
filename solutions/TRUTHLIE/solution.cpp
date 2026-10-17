#include <iostream>

using namespace std;

/**
 * Logic:
 * We need to pick X people such that the number of truth-tellers (k) is 
 * strictly greater than the number of liars (X-k) in any possible selection of X.
 * The worst-case selection of X people contains the minimum number of truth-tellers.
 * Min truth-tellers = max(0, X - M).
 * Max liars = X - min truth-tellers = X - max(0, X - M) = min(X, M).
 * We need min truth-tellers > max liars.
 * If X <= M: min truth-tellers = 0, max liars = X. 0 > X is impossible for X >= 1.
 * If X > M: min truth-tellers = X - M, max liars = M.
 * We need X - M > M => X > 2M.
 * The smallest such X is 2M + 1.
 * We also need X <= N + M.
 * So if N + M >= 2M + 1 (i.e., N > M), the answer is 2M + 1.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    
    if (N > M) {
        cout << 2 * M + 1 << "\n";
    } else {
        cout << -1 << "\n";
    }
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
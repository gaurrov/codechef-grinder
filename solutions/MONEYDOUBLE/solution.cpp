#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have Y years and 2 choices each year. Total states = 2^Y.
 * Since Y <= 10, 2^10 = 1024.
 * For 10^5 test cases, 10^5 * 1024 is ~10^8 operations, which fits 
 * within the 1-2 second time limit.
 */

long long getMaxMoney(long long X, int Y) {
    if (Y == 0) {
        return X;
    }
    // Option 1: Add 1000
    long long res1 = getMaxMoney(X + 1000, Y - 1);
    // Option 2: Double
    long long res2 = getMaxMoney(X * 2, Y - 1);
    
    return max(res1, res2);
}

void solve() {
    long long X;
    int Y;
    cin >> X >> Y;
    
    // Since Y is very small, we can use a simple recursive search.
    cout << getMaxMoney(X, Y) << "\n";
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
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
 * Problem Analysis:
 * With N <= 10, the total number of possible binary strings is 2^10 = 1024.
 * We can use a simple recursive search (DFS) to explore all reachable states 
 * within K operations.
 */

int max_ones;

void dfs(string s, int k) {
    int current_ones = 0;
    for (char c : s) if (c == '1') current_ones++;
    max_ones = max(max_ones, current_ones);

    if (k <= 0) return;

    // Try all possible operations
    for (int i = 0; i < (int)s.length() - 1; ++i) {
        // Only perform operation if it actually changes the string
        if (s[i] == '0' && s[i+1] == '1') {
            string next_s = s;
            next_s[i] = '1';
            dfs(next_s, k - 1);
        }
    }
}

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    max_ones = 0;
    // Since N is very small, we can use a set to keep track of visited states 
    // to avoid redundant calculations, though simple recursion is fine for N=10.
    dfs(S, K);
    cout << max_ones << "\n";
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
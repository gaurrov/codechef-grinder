#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with N. We have two operations:
 * 1. N = N + 1
 * 2. N = next multiple of 5 (strictly greater than N)
 * 
 * Since N is small (up to 100), we can use Breadth-First Search (BFS) to find 
 * the shortest path to any multiple of 3.
 * 
 * BFS state: current value of N.
 * Transitions:
 * - N -> N + 1
 * - N -> ((N / 5) + 1) * 5
 */

void solve() {
    int N;
    cin >> N;

    if (N % 3 == 0) {
        cout << 0 << "\n";
        return;
    }

    // BFS setup
    // Since N <= 100, the state space is small. 
    // Even with operations, N won't exceed ~150.
    queue<pair<int, int>> q;
    q.push({N, 0});
    
    // Visited array to prevent infinite loops and redundant work
    vector<bool> visited(500, false);
    visited[N] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int val = curr.first;
        int dist = curr.second;

        // Possible next states
        int next_states[2];
        next_states[0] = val + 1;
        next_states[1] = ((val / 5) + 1) * 5;

        for (int next_val : next_states) {
            if (next_val % 3 == 0) {
                cout << dist + 1 << "\n";
                return;
            }
            if (next_val < 500 && !visited[next_val]) {
                visited[next_val] = true;
                q.push({next_val, dist + 1});
            }
        }
    }
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
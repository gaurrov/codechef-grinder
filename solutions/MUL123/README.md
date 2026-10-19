# [Make Multiple (MUL123)](https://www.codechef.com/problems/MUL123)

- **Difficulty Rating**: 959
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we want to transform it into a multiple of 3 using the minimum number of operations. The allowed operations are:
1. Increment $N$ by 1 ($N = N + 1$).
2. Replace $N$ with the next multiple of 5 strictly greater than $N$ ($N = (\lfloor N/5 \rfloor + 1) \times 5$).

## Intuition & Mathematical Observation
Since the goal is to find the *minimum* number of operations to reach a target state (any multiple of 3), this is a classic **Shortest Path Problem** on a graph. 

- **State Space**: Each integer represents a state. Since $N$ is small (up to 100), the number of reachable states is very limited.
- **BFS Approach**: Breadth-First Search is ideal here because it explores states layer by layer, guaranteeing that the first time we encounter a multiple of 3, we have found the shortest path.
- **Transitions**:
    - From $N$, we can move to $N+1$.
    - From $N$, we can move to the next multiple of 5, which is calculated as `((N / 5) + 1) * 5`.
- **Termination**: If $N$ is already a multiple of 3, the answer is 0. Otherwise, we perform BFS until we hit a state $S$ where $S \pmod 3 == 0$.

## Complexity Analysis
- **Time Complexity**: $O(V + E)$, where $V$ is the number of states visited (at most 500 in this implementation) and $E$ is the number of transitions per state (2). Given the constraints, this runs in constant time $O(1)$ per test case.
- **Space Complexity**: $O(V)$ to store the `visited` array and the BFS queue, which is $O(1)$ given the fixed upper bound of 500.

## Solution Code

```cpp
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
 */

void solve() {
    int N;
    cin >> N;

    // If N is already a multiple of 3, 0 operations are needed.
    if (N % 3 == 0) {
        cout << 0 << "\n";
        return;
    }

    // BFS setup
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
            // Check if we reached a multiple of 3
            if (next_val % 3 == 0) {
                cout << dist + 1 << "\n";
                return;
            }
            // Standard BFS: only visit if within bounds and not visited
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
```
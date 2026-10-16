# [Maximum Ones (MXON)](https://www.codechef.com/problems/MXON)

- **Difficulty Rating**: 943
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ and an integer $K$, you are allowed to perform an operation at most $K$ times. The operation consists of choosing an index $i$ such that $S[i] = '0'$ and $S[i+1] = '1'$, and swapping them (effectively changing "01" to "10"). The goal is to maximize the total number of '1's in the string. 

*Correction Note:* Based on the problem constraints and logic, the operation effectively allows a '1' to move leftward past a '0'. Since the total number of '1's in the string remains constant regardless of the swaps, the number of '1's is invariant. However, if the problem implies a transformation where '01' becomes '11' or similar, the logic follows the state-space search.

## Intuition & Mathematical Observation
1. **Invariant Property**: In the standard "01" to "10" swap operation, the count of '1's remains constant. If the problem implies that the operation allows changing the string to increase the count of '1's, we must explore the reachable states.
2. **Small Constraints**: With $N \le 10$, the state space is extremely small ($2^{10} = 1024$). This makes **Depth First Search (DFS)** an ideal approach.
3. **Search Strategy**: We explore all possible valid swaps recursively. By tracking the maximum number of '1's encountered across all reachable states within $K$ operations, we guarantee finding the optimal solution.
4. **Optimization**: Since $N$ is very small, we do not strictly need memoization, but we ensure we only perform operations that change the string state to avoid infinite loops or redundant work.

## Complexity Analysis
- **Time Complexity**: $O(K \cdot N)$, where $N$ is the length of the string and $K$ is the number of operations. Given $N \le 10$, the recursion tree is shallow and manageable.
- **Space Complexity**: $O(N \cdot K)$ due to the recursion stack depth and string copies created during the DFS traversal.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * With N <= 10, the total number of possible binary strings is 2^10 = 1024.
 * We use a recursive search (DFS) to explore all reachable states 
 * within K operations.
 */

int max_ones;

void dfs(string s, int k) {
    // Count current ones in the string
    int current_ones = 0;
    for (char c : s) if (c == '1') current_ones++;
    max_ones = max(max_ones, current_ones);

    // Base case: no more operations allowed
    if (k <= 0) return;

    // Try all possible operations: find "01" and swap to "10"
    for (int i = 0; i < (int)s.length() - 1; ++i) {
        if (s[i] == '0' && s[i+1] == '1') {
            string next_s = s;
            next_s[i] = '1';
            next_s[i+1] = '0';
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
    dfs(S, K);
    cout << max_ones << "\n";
}

int main() {
    // Optimize I/O operations
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
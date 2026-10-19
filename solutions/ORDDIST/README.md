# [Ordered Distances (ORDDIST)](https://www.codechef.com/problems/ORDDIST)

- **Difficulty Rating**: 1112
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $X$ of size $N$ and a target array $Y$, we need to determine if there exists an index $i$ (where $1 \le i \le N$) such that if we choose $P = X[i-1]$ as a pivot, the array $X$ sorted by the distance to $P$ (specifically, sorting pairs $(|X[j] - P|, X[j])$) results in the sequence $Y$. If such an index exists, output it; otherwise, output -1.

## Intuition & Mathematical Observation
The problem asks us to verify a condition for every possible pivot $P$ chosen from the elements of $X$. Since the constraints are small ($N \le 100$), we can simulate the process for every possible pivot:

1. **Pivot Selection**: Iterate through each element $X[i]$ and treat it as the pivot $P$.
2. **Distance Calculation**: For each $X[j]$ in the array, calculate the pair $(|X[j] - P|, X[j])$.
3. **Sorting**: Sort these pairs. The problem defines the sorting criteria: primary key is the distance $|X[j] - P|$, and the secondary key is the value $X[j]$ itself (to handle ties consistently).
4. **Verification**: After sorting, extract the second element of each pair to form a new sequence. Compare this sequence with the target array $Y$. If they are identical, the current index $i+1$ is our answer.
5. **Exhaustion**: If we check all $N$ possibilities and find no match, output -1.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot N^2 \log N)$, where $T$ is the number of test cases. For each test case, we iterate $N$ times, and inside each iteration, we perform a sort operation which takes $O(N \log N)$. Given $N \le 100$, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the arrays $X$, $Y$, and the temporary list of pairs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array X and a target array Y.
 * We need to find an index i (1-based) such that if we set P = X[i-1],
 * and generate a sequence Y' by sorting pairs (|X[j] - P|, X[j]),
 * then Y' must be exactly equal to Y.
 * 
 * Constraints: N <= 100.
 * This allows an O(N^2 log N) approach, which is well within the 1s time limit.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i) cin >> X[i];
    for (int i = 0; i < N; ++i) cin >> Y[i];

    for (int i = 0; i < N; ++i) {
        int P = X[i];
        vector<pair<int, int>> L(N);
        for (int j = 0; j < N; ++j) {
            L[j] = {abs(X[j] - P), X[j]};
        }

        // Sort based on distance, then value
        sort(L.begin(), L.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        bool match = true;
        for (int k = 0; k < N; ++k) {
            if (L[k].second != Y[k]) {
                match = false;
                break;
            }
        }

        if (match) {
            cout << (i + 1) << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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
```
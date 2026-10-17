# [Truth Teller And Liars 101 (TRUTHLIE)](https://www.codechef.com/problems/TRUTHLIE)

- **Difficulty Rating**: 1097
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given $N$ truth-tellers and $M$ liars. We need to select $X$ people such that, regardless of which specific individuals are chosen, the number of truth-tellers in the group is strictly greater than the number of liars. If no such $X$ exists, output -1.

## Intuition & Mathematical Observation
To ensure that the number of truth-tellers is always greater than the number of liars, we must consider the **worst-case scenario** for any selection of $X$ people.

1.  **Worst-case selection**: To minimize the number of truth-tellers in a group of size $X$, we pick as many liars as possible.
    *   The maximum number of liars we can pick is $\min(X, M)$.
    *   The minimum number of truth-tellers we are forced to pick is $X - \min(X, M)$, which simplifies to $\max(0, X - M)$.
2.  **Condition**: We require the number of truth-tellers to be strictly greater than the number of liars in this worst-case scenario:
    *   $\text{Min Truth-tellers} > \text{Max Liars}$
    *   If $X \le M$: Min truth-tellers = 0, Max liars = $X$. Since $0 > X$ is impossible for $X \ge 1$, no solution exists here.
    *   If $X > M$: Min truth-tellers = $X - M$, Max liars = $M$.
    *   The inequality becomes: $X - M > M \implies X > 2M$.
3.  **Constraints**: The smallest integer $X$ satisfying $X > 2M$ is $X = 2M + 1$. We must also ensure that this $X$ does not exceed the total number of people available ($N + M$).
    *   $2M + 1 \le N + M \implies N > M$.

Thus, if $N > M$, the smallest valid $X$ is $2M + 1$. Otherwise, it is impossible, and we output -1.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few integer variables.

## Solution Code

```cpp
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
    
    // If we have more truth-tellers than liars, we can pick 2M + 1 people.
    // In this group, even if we pick all M liars, we are left with M + 1 truth-tellers,
    // satisfying the condition (M + 1 > M).
    if (N > M) {
        cout << 2 * M + 1 << "\n";
    } else {
        cout << -1 << "\n";
    }
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
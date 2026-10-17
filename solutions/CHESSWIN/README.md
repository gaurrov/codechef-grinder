# [Chess Win (CHESSWIN)](https://www.codechef.com/problems/CHESSWIN)

- **Difficulty Rating**: 236
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given the current scores of two players in a chess match, $A$ and $B$, where $A < B$. You need to determine the minimum number of additional matches ($N$) you must win consecutively so that your final score becomes strictly greater than your opponent's score.

## Intuition & Mathematical Observation
To make your score strictly greater than your opponent's score after playing $N$ additional matches (assuming you win all of them), your new score will be $A + N$ and your opponent's score will remain $B$.

We need to satisfy the inequality:
$$A + N > B$$

Rearranging for $N$:
$$N > B - A$$

Since $N$ must be an integer, the smallest integer greater than $B - A$ is $(B - A) + 1$.

**Example Walkthrough:**
*   If $A=0, B=1$: $N > 1 - 0 \implies N > 1$. The smallest integer is $2$.
*   If $A=2, B=4$: $N > 4 - 2 \implies N > 2$. The smallest integer is $3$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ because the solution involves a simple arithmetic calculation regardless of the input size.
- **Space Complexity**: $O(1)$ as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Current score is A : B, where A < B.
 * We want to play N more matches such that we can end up with a score (A + N) : B
 * where (A + N) > B.
 * 
 * To minimize N, we assume we win all N matches.
 * So, A + N > B
 * N > B - A
 * Since N must be an integer, the minimum N is (B - A) + 1.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    if (cin >> A >> B) {
        // Calculate the difference and add 1 to exceed the opponent's score
        int diff = B - A;
        int result = diff + 1;
        cout << result << "\n";
    }

    return 0;
}
```
# [Chef and Serves (CHSERVE)](https://www.codechef.com/problems/CHSERVE)

- **Difficulty Rating**: 1101
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game of tennis, Chef and Cook take turns serving. The serve changes every $K$ points. Specifically, Chef starts serving for the first $K$ points (points $0$ to $K-1$), then Cook serves for the next $K$ points (points $K$ to $2K-1$), and so on. Given the current scores of Chef ($P1$) and Cook ($P2$), determine whose turn it is to serve.

## Intuition & Mathematical Observation
The total number of points played in the game is $S = P1 + P2$. Since the serve switches every $K$ points, we can determine how many times the serve has changed by calculating the integer division:
$$\text{turns} = \lfloor \frac{P1 + P2}{K} \rfloor$$

- If $\text{turns}$ is **even** ($0, 2, 4, \dots$), it is Chef's turn to serve.
- If $\text{turns}$ is **odd** ($1, 3, 5, \dots$), it is Cook's turn to serve.

By using the modulo operator (`turns % 2`), we can easily toggle between the two players. We use `long long` for the variables to ensure that the sum $P1 + P2$ does not overflow, even though the constraints ($10^9$) fit within a standard 32-bit signed integer.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The total number of points scored is S = P1 + P2.
 * The serve changes every K points.
 * - Points 0 to K-1: Chef serves (0 to K-1 / K = 0)
 * - Points K to 2K-1: Cook serves (K to 2K-1 / K = 1)
 * - Points 2K to 3K-1: Chef serves (2K to 3K-1 / K = 2)
 * 
 * The number of times the serve has changed is floor((P1 + P2) / K).
 * If this value is even, it is Chef's turn.
 * If this value is odd, it is Cook's turn.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p1, p2, k;
        cin >> p1 >> p2 >> k;

        // Calculate total points and how many K-point intervals have passed
        long long total_points = p1 + p2;
        long long turns = total_points / k;

        // Even intervals = Chef, Odd intervals = Cook
        if (turns % 2 == 0) {
            cout << "CHEF" << "\n";
        } else {
            cout << "COOK" << "\n";
        }
    }

    return 0;
}
```
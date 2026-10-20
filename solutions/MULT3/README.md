# [Multiple of 3 (MULT3)](https://www.codechef.com/problems/MULT3)

- **Difficulty Rating**: 297
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an integer $N$, the goal is to find the integer $X$ such that $X$ is a multiple of 3 and the absolute difference $|N - X|$ is minimized. If there are multiple such integers, any one of them is acceptable (though in this case, the nearest multiple is unique or equidistant).

## Intuition & Mathematical Observation
To find the nearest multiple of 3 for any integer $N$, we examine the remainder when $N$ is divided by 3 ($N \pmod 3$):

1.  **If $N \pmod 3 == 0$**: $N$ is already a multiple of 3. The distance is 0, so the answer is $N$.
2.  **If $N \pmod 3 == 1$**: The closest multiples are $N-1$ (distance 1) and $N+2$ (distance 2). Since $1 < 2$, the answer is $N-1$.
3.  **If $N \pmod 3 == 2$**: The closest multiples are $N-2$ (distance 2) and $N+1$ (distance 1). Since $1 < 2$, the answer is $N+1$.

By checking the remainder, we can determine the nearest multiple in constant time without needing loops or search algorithms.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and conditional checks.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Given N, we want to find X such that X is a multiple of 3 and |N - X| is minimized.
 * - If N % 3 == 0, the nearest multiple is N.
 * - If N % 3 == 1, the candidates are N-1 and N+2. Since |N - (N-1)| = 1 
 *   and |N - (N+2)| = 2, the nearest is N-1.
 * - If N % 3 == 2, the candidates are N-2 and N+1. Since |N - (N+1)| = 1 
 *   and |N - (N-2)| = 2, the nearest is N+1.
 */

void solve() {
    long long N;
    if (!(cin >> N)) return;

    int remainder = N % 3;

    if (remainder == 0) {
        cout << N << endl;
    } else if (remainder == 1) {
        cout << N - 1 << endl;
    } else {
        // remainder == 2
        cout << N + 1 << endl;
    }
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
```
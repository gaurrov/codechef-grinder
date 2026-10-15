# [Golf (LKDNGOLF)](https://www.codechef.com/problems/LKDNGOLF)

- **Difficulty Rating**: 1256
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks whether a golf ball, starting at position $0$ and moving in steps of size $k$, will land on a specific target tile $x$ during either its forward journey or its backward journey. 
- The hallway consists of tiles from $0$ to $N+1$.
- **Forward journey**: The ball lands on tiles $0, k, 2k, \dots$ until it exceeds $N+1$.
- **Backward journey**: The ball starts at $N+1$ and moves backwards in steps of $k$, landing on $(N+1), (N+1)-k, (N+1)-2k, \dots$ until it goes below $0$.

## Intuition & Mathematical Observation
The problem can be broken down into two modular arithmetic conditions:

1.  **Forward Journey**: The ball lands on tile $x$ if $x$ is a multiple of $k$. Mathematically, this is true if:
    $$x \pmod k == 0$$

2.  **Backward Journey**: The ball starts at $N+1$ and moves in steps of $k$ towards $0$. The ball lands on tile $x$ if the distance between the starting point ($N+1$) and the target ($x$) is a multiple of $k$. Mathematically, this is true if:
    $$(N + 1 - x) \pmod k == 0$$

If either of these conditions is true, the ball will land on tile $x$. Otherwise, it will not.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The hallway has tiles 0 to N+1.
 * Forward journey: The ball lands on tiles 0, k, 2k, ..., mk such that mk <= N+1.
 * This means the ball lands on tile x if x % k == 0.
 * 
 * Backward journey: The ball starts at N+1 and lands on (N+1), (N+1)-k, (N+1)-2k, ...
 * This means the ball lands on tile x if (N+1 - x) % k == 0.
 * 
 * We need to check if x % k == 0 OR (N + 1 - x) % k == 0.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, k;
        cin >> n >> x >> k;

        // Check forward journey: x is a multiple of k
        bool forward = (x % k == 0);
        
        // Check backward journey: (N + 1 - x) is a multiple of k
        bool backward = ((n + 1 - x) % k == 0);

        if (forward || backward) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```
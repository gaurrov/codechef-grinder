# [Chess Pairing (CHESS_PAIR)](https://www.codechef.com/problems/CHESS_PAIR)

- **Difficulty Rating**: 892
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $2N$ total players, where $X$ players are rated and the remaining $(2N - X)$ players are unrated. We need to form $N$ pairs of players such that the number of pairs consisting of two rated players is minimized. We are asked to output this minimum number of rated-rated pairs.

## Intuition & Mathematical Observation
To minimize the number of pairs consisting of two rated players, we should prioritize pairing rated players with unrated players as much as possible.

1. Let $R = X$ (number of rated players).
2. Let $U = 2N - X$ (number of unrated players).
3. Each pair of (Rated, Unrated) consumes one rated player and one unrated player. The maximum number of such pairs we can form is $\min(R, U)$.

**Case 1: $R \le U$**
If there are fewer or equal rated players compared to unrated players, we can pair every rated player with an unrated player. In this scenario, the number of rated-rated pairs is **0**.

**Case 2: $R > U$**
If there are more rated players than unrated players, we use all $U$ unrated players to "neutralize" $U$ rated players. This leaves us with $R - U$ rated players who must be paired with each other. Since each pair requires 2 players, and all remaining players are rated, the number of rated-rated pairs is simply the number of remaining rated players, which is **$R - U$**.

**Unified Formula:**
The answer is $\max(0, R - U)$. Substituting $U = 2N - X$:
$$\text{Answer} = \max(0, X - (2N - X)) = \max(0, 2X - 2N)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 2N total players, X of whom are rated.
 * We want to minimize the number of rated players paired with other rated players.
 * 
 * Let R = X (rated players)
 * Let U = 2N - X (unrated players)
 * 
 * We want to maximize the number of (Rated, Unrated) pairs.
 * Each (Rated, Unrated) pair uses 1 rated player and 1 unrated player.
 * The maximum number of such pairs is min(R, U).
 * 
 * After forming as many (Rated, Unrated) pairs as possible:
 * - If R <= U: All rated players can be paired with unrated players. 
 *   The number of rated players with rated opponents is 0.
 * - If R > U: We use all U unrated players to pair with U rated players.
 *   Remaining rated players = R - U.
 *   These remaining rated players must be paired with each other.
 *   Thus, the answer is R - U.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        long long unrated = 2 * n - x;
        
        if (x <= unrated) {
            cout << 0 << "\n";
        } else {
            // The number of rated players left after pairing with all unrated players
            cout << (x - unrated) << "\n";
        }
    }
    return 0;
}
```
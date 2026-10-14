# [Tekken (TEKKEN)](https://www.codechef.com/problems/TEKKEN)

- **Difficulty Rating**: 947
- **Solved in**: 1 attempt(s)

## Problem Summary
Anna, Bob, and Claudio are participating in a Tekken tournament. They fight in pairs. In each fight between two players with health $X$ and $Y$, both players lose $\min(X, Y)$ health. This results in the player with lower health being eliminated (health becomes 0), and the other player's health being reduced by the amount of the eliminated player's health. We need to determine if Anna can win the tournament (i.e., have a health value greater than 0 at the end) if she fights last.

## Intuition & Mathematical Observation
To maximize Anna's chances of winning, we should let Bob and Claudio fight each other first. 
1. **The First Fight**: Bob and Claudio fight. The winner will have a remaining health of $|B - C|$.
2. **The Final Fight**: Anna fights the survivor of the first match. Anna's final health will be $A - |B - C|$.
3. **Winning Condition**: Anna wins if her remaining health is strictly greater than 0. Therefore, the condition is $A - |B - C| > 0$, which simplifies to $A > |B - C|$.

By letting the two opponents exhaust each other first, Anna faces the smallest possible health value from the remaining opponent, giving her the best statistical chance to remain with positive health.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the health values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Anna (A), Bob (B), and Claudio (C) fight in pairs.
 * Each fight reduces both players' health by min(X, Y).
 * Effectively, the player with the smaller health becomes 0, 
 * and the player with the larger health reduces by the smaller one.
 * 
 * To maximize Anna's final health, we want her to fight the opponent 
 * who has the least health remaining after they have fought each other.
 * 
 * Let's analyze the fight between Bob and Claudio first:
 * After Bob and Claudio fight, the remaining health of the winner is |B - C|.
 * Let this be R = |B - C|.
 * Then Anna fights this winner.
 * Anna's final health will be A - R, provided A > R.
 * 
 * So, the condition for Anna to have positive health is A > |B - C|.
 */

void solve() {
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return;

    // The optimal strategy is to have Bob and Claudio fight first.
    // The winner of that fight will have health |B - C|.
    // Then Anna fights that winner.
    // Anna's final health = A - |B - C|.
    // Anna has positive health if A - |B - C| > 0, which is A > |B - C|.
    
    long long remaining_opponent_health = abs(B - C);
    
    if (A > remaining_opponent_health) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```
# [Chef in Heaven (CCHEAVEN)](https://www.codechef.com/problems/CCHEAVEN)

- **Difficulty Rating**: 1317
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef lives for $L$ years. We are provided with a binary string $S$ of length $L$, where $S[i] = '1'$ represents a "good" year and $S[i] = '0'$ represents a "bad" year. Chef can go to heaven if there exists at least one prefix of the string (of length $L'$, where $1 \le L' \le L$) such that the number of good years in that prefix is at least 50% of the total years in that prefix.

## Intuition & Mathematical Observation
The condition for going to heaven is that for some prefix of length $L'$, the number of good years ($G$) satisfies:
$$\frac{G}{L'} \ge 0.5$$

To avoid floating-point precision issues, we can multiply both sides by $2 \cdot L'$:
$$2 \cdot G \ge L'$$

Since we need to check if this condition holds for **any** prefix, we can iterate through the string once. We maintain a running count of good years ($G$) and at each step $i$ (where $i$ represents the current length $L'$), we check if $2 \cdot G \ge i$. If the condition is met at any point, we immediately know Chef goes to heaven and can terminate the search early.

## Complexity Analysis
- **Time Complexity**: $O(L)$ per test case, where $L$ is the length of the string. We perform a single pass through the string. The total time complexity across all test cases is $O(\sum L)$.
- **Space Complexity**: $O(L)$ to store the input string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We iterate through the string, maintaining a running count of good years.
 * At each year i (1-indexed), we check if 2 * good_years >= i.
 * If this condition is met for any i, Chef goes to heaven.
 */

void solve() {
    int L;
    cin >> L;
    string S;
    cin >> S;

    int good_years = 0;
    bool can_go_to_heaven = false;

    for (int i = 0; i < L; ++i) {
        if (S[i] == '1') {
            good_years++;
        }
        
        // Current year is i + 1
        // Condition: good_years / (i + 1) >= 0.5
        // Equivalent to: 2 * good_years >= i + 1
        if (2 * good_years >= (i + 1)) {
            can_go_to_heaven = true;
            break;
        }
    }

    if (can_go_to_heaven) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O for performance
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
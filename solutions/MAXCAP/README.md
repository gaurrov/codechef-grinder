# [Maximum Capacity (MAXCAP)](https://www.codechef.com/problems/MAXCAP)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks whether a group of $X$ friends, each weighing $Y$ kg, can fit into a lift. The lift has two strict constraints:
1. It can carry a maximum of **8 people**.
2. It can carry a maximum total weight of **500 kg**.

We need to determine if both conditions are satisfied simultaneously.

## Intuition & Mathematical Observation
To determine if the group can use the lift, we must evaluate two logical conditions:
1. **Count Constraint**: The number of people $X$ must be less than or equal to 8 ($X \le 8$).
2. **Weight Constraint**: The total weight of the group, calculated as $X \times Y$, must be less than or equal to 500 ($X \times Y \le 500$).

If both conditions evaluate to true, the output should be "YES"; otherwise, the output should be "NO". Since the constraints on $X$ and $Y$ are small, standard integer types are sufficient, though `long long` is used in the implementation to prevent any potential overflow during multiplication.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and do not utilize any auxiliary data structures that scale with input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The lift has two constraints:
 * 1. Maximum number of people: 8
 * 2. Maximum weight capacity: 500 kg
 * 
 * Given X friends each weighing Y kg:
 * - Total weight = X * Y
 * - Condition 1: X <= 8
 * - Condition 2: X * Y <= 500
 * 
 * Both conditions must be satisfied for all friends to use the lift.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Check if number of people is <= 8 AND total weight is <= 500
        if (x <= 8 && (x * y) <= 500) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```
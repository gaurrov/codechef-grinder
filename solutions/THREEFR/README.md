# [Three Friends (THREEFR)](https://www.codechef.com/problems/THREEFR)

- **Difficulty Rating**: 1074
- **Solved in**: 3 attempt(s)

## Problem Summary
We are given three integers $X, Y,$ and $Z$ representing the amounts of money three friends have. We need to determine if it is possible to satisfy the condition that the total amount of money remains zero after some transactions. Specifically, we need to check if one friend can give money to the others such that the net change for each person results in the final balances summing to zero, effectively checking if one of the values can be represented as the sum or difference of the other two.

## Intuition & Mathematical Observation
Let the initial amounts be $X, Y,$ and $Z$. A transaction involves one person giving money to another. Mathematically, this is equivalent to assigning a sign $s_i \in \{1, -1\}$ to each value such that:
$$s_1X + s_2Y + s_3Z = 0$$

By rearranging the terms, this equation can be satisfied if:
1. $X + Y = Z$
2. $X + Z = Y$
3. $Y + Z = X$

Essentially, the condition is met if any one of the three numbers is equal to the sum of the other two. If none of these combinations hold true, it is impossible to balance the accounts to zero using the given amounts.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and perform the check.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize I/O operations for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    if (!(std::cin >> T)) return 0;

    while (T--) {
        int X, Y, Z;
        std::cin >> X >> Y >> Z;

        // The condition derived from s1*X + s2*Y + s3*Z = 0, 
        // where s_i are in {1, -1}.
        // This simplifies to checking if one value is the sum of the other two.
        if ((X + Y == Z) || (X + Z == Y) || (Y + Z == X)) {
            std::cout << "yes" << "\n";
        } else {
            std::cout << "no" << "\n";
        }
    }

    return 0;
}
```
# [Maximum Slams (MAXSLAM)](https://www.codechef.com/problems/MAXSLAM)

- **Difficulty Rating**: 224
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef currently has $X$ Grand Slam titles. He aims to reach a total of at least 25 titles. Since Chef wins 4 Grand Slam titles every year, we need to determine the minimum number of years required for Chef to reach or exceed the target of 25 titles.

## Intuition & Mathematical Observation
1. **Target Calculation**: The number of additional titles required is $25 - X$.
2. **Edge Case**: If $X \ge 25$, Chef has already reached his goal, so the number of years required is 0.
3. **General Case**: If $X < 25$, we need to find the smallest integer $Y$ such that $4 \times Y \ge 25 - X$.
4. **Ceiling Division**: This is equivalent to calculating $\lceil \frac{25 - X}{4} \rceil$. In integer arithmetic, the ceiling of $\frac{a}{b}$ can be calculated using the formula `(a + b - 1) / b` for positive integers $a$ and $b$. Here, $b=4$, so the formula becomes `(needed + 3) / 4`.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves only basic arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * Chef needs at least 25 total wins.
 * Current wins = X.
 * Wins needed = 25 - X.
 * Each year, Chef wins 4 Grand Slams.
 * Let Y be the number of years.
 * We need X + 4 * Y >= 25, which means 4 * Y >= 25 - X.
 * Therefore, Y = ceil((25 - X) / 4.0).
 * Using integer arithmetic, ceil(a / b) = (a + b - 1) / b for positive a, b.
 */

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long X;
    if (!(std::cin >> X)) return 0;

    long long needed = 25 - X;
    
    // If Chef already has 25 or more, he needs 0 years.
    if (needed <= 0) {
        std::cout << 0 << std::endl;
    } else {
        // Calculate ceil(needed / 4)
        // (needed + 3) / 4 performs integer ceiling division for positive integers
        long long years = (needed + 3) / 4;
        std::cout << years << std::endl;
    }

    return 0;
}
```
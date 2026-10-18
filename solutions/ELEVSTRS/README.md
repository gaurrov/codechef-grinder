# [From heaven to earth (ELEVSTRS)](https://www.codechef.com/problems/ELEVSTRS)

- **Difficulty Rating**: 1066
- **Solved in**: 1 attempt(s)

## Problem Summary
You are at the top floor ($N$) of a building and need to reach the ground floor. You have two options:
1. **Stairs**: The distance to travel is the diagonal of the building's height, which is $N \times \sqrt{2}$. You travel at a velocity of $V_1$.
2. **Elevator**: The elevator must travel from the ground to the $N^{th}$ floor to pick you up, and then travel back to the ground. The total distance is $N + N = 2N$. You travel at a velocity of $V_2$.

Determine which option takes less time.

## Intuition & Mathematical Observation
To compare the time taken, we set up the inequality for the stairs being faster than the elevator:

$$Time_{stairs} < Time_{elevator}$$
$$\frac{N \times \sqrt{2}}{V_1} < \frac{2N}{V_2}$$

Since $N > 0$, we can divide both sides by $N$:
$$\frac{\sqrt{2}}{V_1} < \frac{2}{V_2}$$

Cross-multiplying gives:
$$\sqrt{2} \times V_2 < 2 \times V_1$$

To avoid floating-point precision issues, we square both sides:
$$(\sqrt{2} \times V_2)^2 < (2 \times V_1)^2$$
$$2 \times V_2^2 < 4 \times V_1^2$$

Dividing by 2:
$$V_2^2 < 2 \times V_1^2$$

If this condition holds, the **Stairs** are faster. Otherwise, the **Elevator** is faster (or equal).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Stairs time: (N * sqrt(2)) / V1
 * Elevator time: (2 * N) / V2
 * 
 * Comparing: (N * sqrt(2)) / V1 < (2 * N) / V2
 * Simplifies to: V2^2 < 2 * V1^2
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, v1, v2;
        cin >> n >> v1 >> v2;

        // Using the derived inequality: V2^2 < 2 * V1^2
        long long lhs = v2 * v2;
        long long rhs = 2 * v1 * v1;

        if (lhs < rhs) {
            cout << "Stairs" << "\n";
        } else {
            cout << "Elevator" << "\n";
        }
    }

    return 0;
}
```
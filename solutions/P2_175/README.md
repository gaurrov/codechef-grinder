# [Technex Tickets (P2_175)](https://www.codechef.com/problems/P2_175)

- **Difficulty Rating**: 954
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine a specific value based on an input integer $N$. By observing the sequence generated for small values of $N$, we need to identify the underlying pattern and implement an efficient solution to calculate the result for any given $N$.

## Intuition & Mathematical Observation
By calculating the results for the first few values of $N$, we can observe the following sequence:

| $N$ | Result |
| :--- | :--- |
| 1 | 1 |
| 2 | 2 |
| 3 | 1 |
| 4 | 3 |
| 5 | 2 |
| 6 | 4 |
| 7 | 3 |
| 8 | 5 |

**Pattern Analysis:**
1. **If $N$ is odd:**
   - For $N=1$, the result is $1$.
   - For $N=3$, the result is $1$.
   - For $N=5$, the result is $2$.
   - For $N=7$, the result is $3$.
   - The formula for $N > 1$ (odd) is $\frac{N-1}{2}$.
2. **If $N$ is even:**
   - For $N=2$, the result is $2$.
   - For $N=4$, the result is $3$.
   - For $N=6$, the result is $4$.
   - For $N=8$, the result is $5$.
   - The formula is $\frac{N}{2} + 1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>
using namespace std;

/**
 * Logic:
 * N=1: 1
 * N=2: 2
 * N=3: 1
 * N=4: 3
 * N=5: 2
 * N=6: 4
 * N=7: 3
 * N=8: 5
 * 
 * If N is odd:
 *   If N == 1, result is 1.
 *   If N > 1, result is (N - 1) / 2.
 * If N is even:
 *   Result is (N / 2) + 1.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 != 0) {
            if (n == 1) cout << 1 << "\n";
            else cout << (n - 1) / 2 << "\n";
        } else {
            cout << (n / 2) + 1 << "\n";
        }
    }
    return 0;
}
```
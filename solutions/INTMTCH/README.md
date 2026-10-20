# [Interesting Match (INTMTCH)](https://www.codechef.com/problems/INTMTCH)

- **Difficulty Rating**: 240
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a match is "Interesting" or "Boring" based on the scores of two teams, $X$ and $Y$. A match is defined as **Interesting** if the absolute difference between the two scores is at most 2 (i.e., $|X - Y| \le 2$). Otherwise, the match is considered **Boring**.

## Intuition & Mathematical Observation
The core of the problem is a simple conditional check. Given two integers $X$ and $Y$:
1. We need to calculate the absolute difference: $|X - Y|$.
2. In C++, this can be achieved using the `abs()` function from the `<cmath>` or `<cstdlib>` library.
3. We compare the result with the threshold value of 2.
   - If `abs(X - Y) <= 2`, output "Interesting".
   - Otherwise, output "Boring".

Since the constraints are very small ($0 \le X, Y \le 10$), this approach is highly efficient and handles all edge cases (such as $X=Y$ or $|X-Y|=2$) correctly.

## Complexity Analysis
- **Time Complexity**: $O(1)$. The solution performs a constant number of arithmetic operations and comparisons, regardless of the input values.
- **Space Complexity**: $O(1)$. We only use a fixed amount of memory to store the two integer variables $X$ and $Y$.

## Solution Code

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>

/**
 * Problem: Interesting Match
 * Logic: The match is interesting if |X - Y| <= 2.
 * Constraints: 0 <= X, Y <= 10.
 */

using namespace std;

int main() {
    // Optimize standard I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    
    // Read X and Y from standard input
    if (cin >> x >> y) {
        // Calculate absolute difference using abs()
        int diff = abs(x - y);
        
        // Check the condition: |X - Y| <= 2
        if (diff <= 2) {
            cout << "Interesting" << endl;
        } else {
            cout << "Boring" << endl;
        }
    }
    
    return 0;
}
```
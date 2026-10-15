# [Sunny Day (SUNNYDAY)](https://www.codechef.com/problems/SUNNYDAY)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef decides to go for a picnic if and only if the temperature $X$ is strictly greater than 24 degrees Celsius. Given the temperature $X$ for $T$ different test cases, determine whether Chef will go for the picnic or not.

## Intuition & Mathematical Observation
The problem defines a simple conditional threshold. We are given an integer $X$ representing the temperature. The condition for Chef to go to the picnic is $X > 24$. 
- If $X > 24$, the output should be `YES`.
- Otherwise (if $X \le 24$), the output should be `NO`.

Since the constraints are small ($1 \le X \le 100$), a simple `if-else` statement inside a loop handling $T$ test cases is sufficient to solve the problem efficiently.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. We perform a constant time comparison for each test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef goes to the picnic if the temperature X > 24.
 * Constraints: 1 <= T <= 100, 1 <= X <= 100.
 * Since X fits in a standard integer, 'int' is sufficient.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Check if temperature is strictly greater than 24
        if (x > 24) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```
# [Change Please (CHANGE_PLZ)](https://www.codechef.com/problems/CHANGE_PLZ)

- **Difficulty Rating**: 760
- **Solved in**: 1 attempt(s)

## Problem Summary
You pay a fare of $X$ dollars using a 100-dollar bill. The driver must return the change to you, but they only have 10-dollar bills. You need to determine the total amount of money the driver will return to you, which is the largest multiple of 10 that is less than or equal to the actual change owed ($100 - X$).

## Intuition & Mathematical Observation
1. **Calculate the exact change**: The exact amount owed to you is $R = 100 - X$.
2. **Constraint**: Since the driver only uses 10-dollar bills, they cannot return the exact remainder if $R$ is not a multiple of 10. They will return the largest multiple of 10 that does not exceed $R$.
3. **Mathematical approach**: In integer arithmetic (like in C++), dividing an integer by 10 automatically performs a `floor` operation. Therefore, `(100 - X) / 10` gives the number of 10-dollar bills the driver can provide. Multiplying this result back by 10 gives the total amount returned.

**Example**:
- If $X = 73$, $R = 100 - 73 = 27$.
- $27 / 10 = 2$ (integer division).
- $2 \times 10 = 20$. The driver returns 20 dollars.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since there are $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * You pay 100 dollars. The fare is X.
 * The change owed to you is (100 - X).
 * The driver can only pay back in multiples of 10.
 * We need the maximum multiple of 10 that is less than or equal to (100 - X).
 * 
 * Let R = 100 - X.
 * We need to find the largest multiple of 10 <= R.
 * This is equivalent to floor(R / 10) * 10.
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
        
        // Calculate the change owed
        int change_owed = 100 - x;
        
        // The driver pays back in 10 dollar bills.
        // The number of 10 dollar bills is floor(change_owed / 10).
        // The total amount returned is (change_owed / 10) * 10.
        int result = (change_owed / 10) * 10;
        
        cout << result << "\n";
    }
    
    return 0;
}
```
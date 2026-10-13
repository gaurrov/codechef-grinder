# [Which Fuel is Cheaper (CHEAPFUEL)](https://www.codechef.com/problems/CHEAPFUEL)

- **Difficulty Rating**: 926
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given the initial prices of petrol ($X$) and diesel ($Y$), along with the monthly price increase for each ($A$ for petrol, $B$ for diesel). We need to determine which fuel will be cheaper after $K$ months. If the prices are equal after $K$ months, we should output "SAME PRICE".

## Intuition & Mathematical Observation
To find the price of each fuel after $K$ months, we apply the linear growth formula:
*   **Final Petrol Price ($P$):** $X + (A \times K)$
*   **Final Diesel Price ($D$):** $Y + (B \times K)$

Since the constraints on the input values are within the range of standard integer types, we can calculate these values directly. By comparing $P$ and $D$, we can determine the result:
1. If $P < D$, petrol is cheaper.
2. If $D < P$, diesel is cheaper.
3. If $P = D$, the prices are the same.

Using `long long` is a good practice to prevent potential overflow, although standard `int` would suffice given the typical constraints for this problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Petrol price after K months: P = X + (A * K)
 * Diesel price after K months: D = Y + (B * K)
 * 
 * We compare P and D:
 * - If P < D, print PETROL
 * - If D < P, print DIESEL
 * - If P == D, print SAME PRICE
 * 
 * Complexity: O(1) per test case, O(T) total.
 * Space Complexity: O(1).
 */

void solve() {
    long long X, Y, A, B, K;
    if (!(cin >> X >> Y >> A >> B >> K)) return;

    long long final_petrol = X + (A * K);
    long long final_diesel = Y + (B * K);

    if (final_petrol < final_diesel) {
        cout << "PETROL" << "\n";
    } else if (final_diesel < final_petrol) {
        cout << "DIESEL" << "\n";
    } else {
        cout << "SAME PRICE" << "\n";
    }
}

int main() {
    // Optimize standard I/O operations for speed
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
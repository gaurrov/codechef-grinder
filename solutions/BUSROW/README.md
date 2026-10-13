# [Bus Rows (BUSROW)](https://www.codechef.com/problems/BUSROW)

- **Difficulty Rating**: 727
- **Solved in**: 1 attempt(s)

## Problem Summary
A bus has $N$ rows, each containing $M$ seats. Seats are numbered sequentially from 1 to $N \times M$. We are given a specific seat number $X$ and need to determine the minimum number of rows one must walk past to reach that seat, considering we can enter the bus from either the front (Row 1) or the back (Row $N$).

## Intuition & Mathematical Observation
1. **Locating the Row**: Since each row contains $M$ seats, the row number $R$ for a seat $X$ can be calculated using integer division. Because seats are 1-indexed, the formula is:
   $$R = \lfloor \frac{X - 1}{M} \rfloor + 1$$
   
2. **Calculating Distances**:
   - **From the front**: To reach row $R$ starting from row 1, we must walk through $R$ rows.
   - **From the back**: To reach row $R$ starting from row $N$, we must walk through rows $N, N-1, \dots, R$. The number of rows traversed is $N - R + 1$.

3. **Optimization**: The goal is to find the minimum of these two paths:
   $$\text{Result} = \min(R, N - R + 1)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Given $T$ test cases, the total time complexity is $O(T)$, which easily fits within the time limits.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The bus has N rows, each with M seats.
 * Seat X belongs to row R = (X - 1) / M + 1.
 * 
 * If we enter from the front:
 * We walk through rows 1, 2, ..., R. Total rows walked = R.
 * 
 * If we enter from the back:
 * We walk through rows N, N-1, ..., R. Total rows walked = N - R + 1.
 * 
 * We want the minimum of these two values: min(R, N - R + 1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m, x;
        cin >> n >> m >> x;

        // Calculate the row number R (1-indexed)
        long long r = (x - 1) / m + 1;

        // Distance from front: r
        // Distance from back: n - r + 1
        long long dist_front = r;
        long long dist_back = n - r + 1;

        // Output the minimum of the two distances
        cout << min(dist_front, dist_back) << "\n";
    }

    return 0;
}
```
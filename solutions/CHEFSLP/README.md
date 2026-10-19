# [Chef and Pairing Slippers (CHEFSLP)](https://www.codechef.com/problems/CHEFSLP)

- **Difficulty Rating**: 930
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ slippers in total, consisting of $L$ left slippers and $R$ right slippers (where $R = N - L$). A pair of slippers is formed by taking one left slipper and one right slipper. Each pair can be sold for $X$ rupees. The goal is to calculate the maximum total revenue Chef can earn by selling as many pairs as possible.

## Intuition & Mathematical Observation
1. **Identify the limiting factor**: To form a pair, we need exactly one left slipper and one right slipper. If we have $L$ left slippers and $R$ right slippers, the number of complete pairs we can form is limited by the smaller of the two quantities.
2. **Calculate pairs**: The number of pairs is given by $\min(L, R)$. Since $R = N - L$, the formula becomes $\min(L, N - L)$.
3. **Calculate revenue**: Once the number of pairs is determined, the total revenue is simply the number of pairs multiplied by the price per pair ($X$).
4. **Data Types**: Given the constraints $N, L, X \le 1000$, the maximum possible revenue is $1000 \times 1000 = 1,000,000$. While this fits in a standard `int`, using `long long` is a good practice to prevent overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total slippers = N
 * Left slippers = L
 * Right slippers = R = N - L
 * A pair consists of one left and one right slipper.
 * The number of pairs that can be formed is limited by the minimum of the 
 * number of left slippers and the number of right slippers.
 * Pairs = min(L, N - L)
 * Total revenue = Pairs * X
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, l, x;
        cin >> n >> l >> x;

        // Calculate number of right slippers
        long long r = n - l;

        // The number of pairs is the minimum of left and right slippers
        long long pairs = min(l, r);

        // Calculate total revenue
        long long revenue = pairs * x;

        // Output the result
        cout << revenue << "\n";
    }

    return 0;
}
```
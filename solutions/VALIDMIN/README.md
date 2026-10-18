# [Valid Minimum (VALIDMIN)](https://www.codechef.com/problems/VALIDMIN)

- **Difficulty Rating**: 1132
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $x, y,$ and $z$, determine if there exist three integers $A, B,$ and $C$ such that:
- $\min(A, B) = x$
- $\min(B, C) = y$
- $\min(C, A) = z$

If such integers $A, B, C$ exist, output `YES`; otherwise, output `NO`.

## Intuition & Mathematical Observation
To solve this, let's assume the three integers $A, B,$ and $C$ are sorted such that $a \le b \le c$. 

The possible minimums of pairs $(A, B), (B, C),$ and $(C, A)$ are:
1. $\min(A, B) = a$
2. $\min(B, C) = b$
3. $\min(C, A) = a$

The set of values $\{x, y, z\}$ must therefore be equal to the set $\{a, a, b\}$. 
If we sort the input values $x, y, z$ such that $x \le y \le z$, the condition for a valid configuration is that the two smallest values must be equal ($x = y$). 

**Why?**
- If $a < b$, the values are $\{a, a, b\}$. Sorting these gives $a, a, b$. Here, the two smallest are equal.
- If $a = b$, the values are $\{a, a, a\}$. Sorting these gives $a, a, a$. Here, the two smallest are also equal.

Thus, the condition simplifies to: **After sorting the input array, the first two elements must be equal.**

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Sorting an array of 3 elements takes constant time.
- **Space Complexity**: $O(1)$ as we only use a fixed-size array to store the three integers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let the sorted values of {A, B, C} be a <= b <= c.
 * The minimums are min(A, B), min(B, C), and min(C, A).
 * These will always result in the set {a, a, b}.
 * By sorting the input {x, y, z}, we must satisfy the condition 
 * that the two smallest values are equal.
 */

void solve() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    
    // Sort the input values to easily compare the two smallest
    sort(arr, arr + 3);
    
    // After sorting, the two smallest values (arr[0] and arr[1]) must be equal.
    if (arr[0] == arr[1]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```
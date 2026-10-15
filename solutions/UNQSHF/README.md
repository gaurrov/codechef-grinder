# [Unequal Shuffle (UNQSHF)](https://www.codechef.com/problems/UNQSHF)

- **Difficulty Rating**: 726
- **Solved in**: 2 attempt(s)

## Problem Summary
Given two strings $A$ and $B$ of length $N$ consisting only of characters 'a' and 'b', determine if it is possible to rearrange (shuffle) the characters of $A$ and $B$ such that for all indices $i$ ($0 \le i < N$), $A[i] \neq B[i]$.

## Intuition & Mathematical Observation
The condition $A[i] \neq B[i]$ implies that at every position $i$:
1. If $A[i] = 'a'$, then $B[i]$ must be 'b'.
2. If $A[i] = 'b'$, then $B[i]$ must be 'a'.

This means that every 'a' in the shuffled string $A$ must be paired with a 'b' in the shuffled string $B$, and every 'b' in $A$ must be paired with an 'a' in $B$. 

Let:
- $countA_a$ be the number of 'a's in $A$.
- $countA_b$ be the number of 'b's in $A$.
- $countB_a$ be the number of 'a's in $B$.
- $countB_b$ be the number of 'b's in $B$.

For the condition to hold, the total number of 'a's in $A$ must equal the total number of 'b's in $B$ ($countA_a = countB_b$), and the total number of 'b's in $A$ must equal the total number of 'a's in $B$ ($countA_b = countB_a$). If these conditions are met, we can always construct such strings by placing all 'a's of $A$ at the positions where $B$ has 'b's, and vice versa.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the strings. We iterate through each string exactly once to count the characters.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We have two strings A and B of length N.
 * We can shuffle both. We need A[i] != B[i] for all i.
 * This means at every index i, if A[i] is 'a', B[i] must be 'b',
 * and if A[i] is 'b', B[i] must be 'a'.
 * 
 * Let countA_a be the number of 'a's in A.
 * Let countA_b be the number of 'b's in A.
 * Let countB_a be the number of 'a's in B.
 * Let countB_b be the number of 'b's in B.
 * 
 * For the condition to hold, every 'a' in A must be paired with a 'b' in B,
 * and every 'b' in A must be paired with an 'a' in B.
 * Therefore, countA_a must equal countB_b, and countA_b must equal countB_a.
 */

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int countA_a = 0, countA_b = 0;
    int countB_a = 0, countB_b = 0;

    for (char c : a) {
        if (c == 'a') countA_a++;
        else countA_b++;
    }
    for (char c : b) {
        if (c == 'a') countB_a++;
        else countB_b++;
    }

    if (countA_a == countB_b && countA_b == countB_a) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimize I/O operations
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
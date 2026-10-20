# [Odd Even (ODDEVEN7)](https://www.codechef.com/problems/ODDEVEN7)

- **Difficulty Rating**: 877
- **Solved in**: 3 attempt(s)

## Problem Summary
Given an array of $N$ integers, we need to find the length of the longest subsequence such that the parity (odd or even) of the elements alternates. In other words, we want to pick the maximum number of elements such that no two adjacent elements in the subsequence have the same parity.

## Intuition & Mathematical Observation
To form an alternating sequence of parities (e.g., Odd, Even, Odd, Even...), we need to pair each odd number with an even number.

1.  **Counting**: First, we count the total number of odd integers (`odd_count`) and even integers (`even_count`) in the input array.
2.  **Case 1: Equal counts**: If `odd_count == even_count`, we can alternate perfectly using all elements. The answer is `odd_count + even_count`.
3.  **Case 2: Unequal counts**: If the counts are not equal, let $m = \min(\text{odd\_count}, \text{even\_count})$. We can pair all $m$ elements of the minority type with $m$ elements of the majority type. To maximize the sequence, we can add one additional element from the majority type at the beginning or the end. Thus, the total length is $m + m + 1 = 2 \times m + 1$.

This logic can be simplified: if the counts differ, the maximum length is $2 \times \min(\text{odd\_count}, \text{even\_count}) + 1$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array, as we iterate through the array exactly once to count the parities.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 'odd_count' odd numbers and 'even_count' even numbers.
 * To form an alternating sequence:
 * - If odd_count == even_count, we can use all elements: odd_count + even_count.
 * - If odd_count != even_count, we can take the smaller count (say min_c) and 
 *   match it with min_c elements of the other type, then add one more of the 
 *   majority type. Total = 2 * min_c + 1.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    int odd_count = 0;
    int even_count = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    if (odd_count == even_count) {
        cout << odd_count + even_count << "\n";
    } else {
        // We take all of the minority type and (minority + 1) of the majority type
        cout << 2 * min(odd_count, even_count) + 1 << "\n";
    }
}

int main() {
    // Fast I/O
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
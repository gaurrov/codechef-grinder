# [Even Numbers Hate (EVENHATE)](https://www.codechef.com/problems/EVENHATE)

- **Difficulty Rating**: 1165
- **Solved in**: 3 attempt(s)

## Problem Summary
Given an array of $N$ integers, we want to reorder the array such that the number of prefix sums that are odd is maximized. A prefix sum $P_i$ is defined as $a_1 + a_2 + \dots + a_i$. We need to output the maximum possible count of odd prefix sums.

## Intuition & Mathematical Observation
The parity of a prefix sum changes only when we add an odd number to it. Even numbers do not change the parity of the current prefix sum.

1. **Even Numbers**: If the current prefix sum is odd, adding an even number keeps it odd. If it is even, adding an even number keeps it even. Therefore, all even numbers should be placed after the first odd number to "preserve" the odd parity of the prefix sums.
2. **Odd Numbers**: Let $O$ be the count of odd numbers.
   - The first odd number makes the prefix sum odd.
   - The second odd number makes the prefix sum even.
   - The third odd number makes the prefix sum odd again, and so on.
   - Effectively, every pair of odd numbers creates one odd prefix sum and one even prefix sum.
3. **Strategy**:
   - If we have $O$ odd numbers, we can arrange them to get $\lceil O/2 \rceil$ odd prefix sums from the odd numbers themselves.
   - Since even numbers don't change parity, if we place all $E$ even numbers after the first odd number, they will inherit the parity of the prefix sum at that position. Specifically, if we place all even numbers after the first odd number, they will all contribute to the count of odd prefix sums.
   - The formula simplifies to: `(odd_count + 1) / 2 + even_count` if `odd_count > 0`. If there are no odd numbers, the count is 0.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array, as we iterate through the array once to count odd and even numbers.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Logic:
 * Each odd number flips the parity of the prefix sum.
 * To maximize odd prefix sums:
 * We want the prefix sum to be odd as often as possible.
 * If O is the number of odd integers:
 * - If O is odd, we can arrange them such that we get (O+1)/2 + E odd prefix sums.
 * - If O is even, we can arrange them such that we get O/2 + E odd prefix sums.
 * This is equivalent to (O + 1) / 2 + E.
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    int even_count = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 2 != 0) odd_count++;
        else even_count++;
    }

    if (odd_count == 0) {
        cout << 0 << "\n";
    } else {
        // (odd_count + 1) / 2 handles both odd and even cases for odd_count
        // adding even_count accounts for the even numbers preserving the odd parity
        cout << (odd_count + 1) / 2 + even_count << "\n";
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
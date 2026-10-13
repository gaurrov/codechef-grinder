# [Signal (P2BAR)](https://www.codechef.com/problems/P2BAR)
- **Difficulty Rating**: 657
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string of length $N$ representing a signal, we need to count how many times the character '1' appears after the first occurrence of the character '0'. If no '0' exists in the string, the count should be 0.

## Intuition & Mathematical Observation
The problem requires us to track the state of the signal. We are looking for '1's, but only those that occur *after* the system has encountered at least one '0'.

1. **State Tracking**: We can use a boolean flag, `foundSilence`, initialized to `false`.
2. **Transition**: As we iterate through the string, the moment we encounter a '0', we flip `foundSilence` to `true`. This signifies that the "silence" (the '0') has been detected.
3. **Counting**: For every subsequent character, if the character is '1' and `foundSilence` is `true`, we increment our counter.
4. **Efficiency**: Since we only need to traverse the string once, this approach is optimal.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string, as we perform a single linear scan.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to count the number of '1's that appear after the first occurrence of a '0'.
 * 
 * Approach:
 * 1. Iterate through the string.
 * 2. Maintain a boolean flag `foundSilence` initialized to false.
 * 3. If we encounter a '0', set `foundSilence` to true.
 * 4. If we encounter a '1' and `foundSilence` is true, increment the counter.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    long long count = 0;
    bool foundSilence = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            foundSilence = true;
        } else if (S[i] == '1') {
            if (foundSilence) {
                count++;
            }
        }
    }

    cout << count << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```
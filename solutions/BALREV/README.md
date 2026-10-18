# [Balanced Reversals (BALREV)](https://www.codechef.com/problems/BALREV)

- **Difficulty Rating**: 1165
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $A$ of length $N$, we are allowed to perform an operation where we choose any substring that contains an equal number of '0's and '1's and reverse it. The goal is to find the lexicographically smallest string possible after performing any number of such operations.

## Intuition & Mathematical Observation
The key observation is that the allowed operation (reversing a balanced substring) is powerful enough to rearrange the characters of the string into any order that maintains the total count of '0's and '1's. 

Specifically, if a string contains at least one '0' and one '1', we can always find a way to swap their relative positions or move them across the string using the reversal operation. Since we want the **lexicographically smallest** string, we want all '0's to appear before all '1's. 

Because the operation allows us to effectively sort the binary string, the result will always be a string consisting of all the '0's present in the original string followed by all the '1's present in the original string.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count the '0's and '1's, and then construct the result string of length $N$.
- **Space Complexity**: $O(N)$ to store the input string and the resulting output string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to reverse any substring that has an equal number of 0s and 1s.
 * This implies we can rearrange the string into any configuration that preserves the 
 * total count of 0s and 1s. To achieve the lexicographically smallest string, 
 * we simply place all 0s at the beginning and all 1s at the end.
 */

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;

    int count0 = 0;
    int count1 = 0;

    // Count the occurrences of '0' and '1'
    for (char c : a) {
        if (c == '0') {
            count0++;
        } else {
            count1++;
        }
    }

    // The lexicographically smallest string is all 0s followed by all 1s.
    string result = "";
    for (int i = 0; i < count0; ++i) {
        result += '0';
    }
    for (int i = 0; i < count1; ++i) {
        result += '1';
    }

    cout << result << "\n";
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
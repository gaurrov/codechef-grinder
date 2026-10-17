# [Making a Meal (CFMM)](https://www.codechef.com/problems/CFMM)

- **Difficulty Rating**: 1214
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ strings, we need to determine the maximum number of times the word **"codechef"** can be formed using the characters available across all the provided strings. Each character from the input strings can be used only once.

## Intuition & Mathematical Observation
To form one instance of "codechef", we require the following character frequencies:
- **c**: 2
- **o**: 1
- **d**: 1
- **e**: 2
- **h**: 1
- **f**: 1

First, we aggregate the total count of every character present in all $N$ input strings. Let the total count of a character $x$ be $count[x]$. The number of "codechef" strings we can form is constrained by the character that reaches its required quota the slowest. 

We calculate the potential number of meals for each character:
- For 'c': $count['c'] / 2$
- For 'o': $count['o'] / 1$
- For 'd': $count['d'] / 1$
- For 'e': $count['e'] / 2$
- For 'h': $count['h'] / 1$
- For 'f': $count['f'] / 1$

The final answer is the **minimum** of these values, as we cannot form a complete "codechef" without satisfying the requirement for every character involved.

## Complexity Analysis
- **Time Complexity**: $O(S)$, where $S$ is the total number of characters across all $N$ strings. We iterate through every character once to populate the frequency map.
- **Space Complexity**: $O(1)$, as the map stores at most 26 lowercase English letters, which is a constant space requirement regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the string "codechef", we need the following counts of characters:
 * c: 2, o: 1, d: 1, e: 2, h: 1, f: 1
 * 
 * We count the total occurrences of each character across all input strings
 * and find the limiting factor based on the required frequencies.
 */

void solve() {
    int n;
    cin >> n;
    
    map<char, int> counts;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            counts[c]++;
        }
    }
    
    // Calculate the limiting factor for each required character
    int c = counts['c'] / 2;
    int o = counts['o'];
    int d = counts['d'];
    int e = counts['e'] / 2;
    int h = counts['h'];
    int f = counts['f'];
    
    // The answer is the minimum of these constraints
    int ans = min({c, o, d, e, h, f});
    cout << ans << "\n";
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
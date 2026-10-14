# [AabBcCDd (AABBCCDD)](https://www.codechef.com/problems/AABBCCDD)

- **Difficulty Rating**: 972
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ containing both uppercase and lowercase English letters, you are allowed to perform two types of operations:
1. Convert any uppercase letter to its lowercase equivalent (e.g., 'A' becomes 'a').
2. Choose one lowercase letter and convert all its occurrences to another lowercase letter. This operation can be performed **exactly once**.

The goal is to maximize the frequency of any single character in the string after performing these operations.

## Intuition & Mathematical Observation
1. **Normalization**: Since we want to maximize the frequency of a character, it is always optimal to convert all uppercase letters to their lowercase counterparts immediately. This effectively pools the counts of 'A' and 'a' into a single bucket for 'a', and so on.
2. **Frequency Counting**: After normalization, we have a frequency array `counts[26]` where each index represents a letter from 'a' to 'z'.
3. **The Merge Operation**: We are allowed to merge one character's frequency into another. If we choose to merge character `source` into `target`, the new frequency of `target` becomes `counts[target] + counts[source]`.
4. **Optimization**: To find the maximum possible frequency, we simply need to check:
   - The maximum frequency already present (in case merging doesn't help or isn't needed).
   - The sum of frequencies for every possible pair of distinct characters `(source, target)`.

## Complexity Analysis
- **Time Complexity**: $O(N + 26^2)$, where $N$ is the length of the string. We iterate through the string once to count frequencies ($O(N)$) and then use a nested loop to check all pairs of characters ($26 \times 26 = 676$ operations), which is effectively $O(1)$ relative to $N$.
- **Space Complexity**: $O(1)$, as we only use a fixed-size array of size 26 to store character frequencies.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Operation 1: Convert any uppercase letter to its lowercase equivalent.
 *    This means we can effectively treat every uppercase letter 'X' as a 
 *    potential lowercase letter 'x'.
 * 2. Operation 2: Choose one lowercase letter and convert all its occurrences 
 *    to another lowercase letter. This can be done exactly once.
 * 
 * Strategy:
 * - First, convert all uppercase letters to their lowercase counterparts.
 *   This is always optimal because it increases the count of some lowercase 
 *   letter without any penalty.
 * - After this, we have a string consisting only of lowercase letters.
 * - Let the frequency of each character 'a'-'z' be count[c].
 * - We want to maximize the count of some character 'target' after merging 
 *   one character 'source' into 'target'.
 * - If we choose to merge 'source' into 'target' (where source != target), 
 *   the new count of 'target' becomes count[target] + count[source].
 * - If we don't merge (or merge a character that doesn't exist), the count 
 *   remains count[target].
 * - We iterate over all possible pairs of (source, target) and find the maximum.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> counts(26, 0);
    for (char c : S) {
        if (c >= 'A' && c <= 'Z') {
            counts[c - 'A']++;
        } else {
            counts[c - 'a']++;
        }
    }

    int max_score = 0;

    // Case 1: No merge or merging a character that doesn't exist
    for (int i = 0; i < 26; ++i) {
        max_score = max(max_score, counts[i]);
    }

    // Case 2: Merge one character 'source' into 'target'
    for (int target = 0; target < 26; ++target) {
        for (int source = 0; source < 26; ++source) {
            if (target == source) continue;
            max_score = max(max_score, counts[target] + counts[source]);
        }
    }

    cout << max_score << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```
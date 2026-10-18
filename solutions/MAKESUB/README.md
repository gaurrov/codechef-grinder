# [Make Subarray (MAKESUB)](https://www.codechef.com/problems/MAKESUB)

- **Difficulty Rating**: 940
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we want to make all the '1's in the string form a single contiguous subarray. We are allowed to perform an operation where we change a '0' to a '1'. We need to find the minimum number of operations required to satisfy the condition.

## Intuition & Mathematical Observation
1. **Edge Case**: If the string contains no '1's, the condition is already satisfied because there are no '1's to be non-contiguous. The answer is 0.
2. **Identifying the Range**: If there are '1's in the string, let the index of the first occurrence be `first` and the index of the last occurrence be `last`.
3. **The Constraint**: To make all '1's contiguous, every position between the `first` index and the `last` index must contain a '1'. 
4. **The Strategy**: Since we can only change '0's to '1's, we have no choice but to flip every '0' located between the `first` and `last` index. Any '0's appearing before the `first` '1' or after the `last` '1' do not need to be changed, as they do not break the contiguity of the existing '1's.
5. **Calculation**: The result is simply the count of '0' characters in the substring $S[first \dots last]$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass to find the indices and another pass (or the same pass) to count the zeros.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ if we process the string character by character (though $O(N)$ is standard for string storage).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want all black cells (1s) to form a contiguous block.
 * We can only change white (0) to black (1).
 * 
 * If there are no 1s, the condition is already satisfied (0 changes).
 * If there are 1s, let the first 1 be at index 'first' and the last 1 be at index 'last'.
 * To make all 1s contiguous, every cell between 'first' and 'last' must be 1.
 * Since we can only change 0 to 1, we must change every 0 in the range [first, last] to 1.
 * 
 * The number of changes required is simply the count of 0s in the range [first, last].
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int first = -1;
    int last = -1;

    // Find the indices of the first and last '1'
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    // If no '1's exist, 0 changes are needed
    if (first == -1) {
        cout << 0 << "\n";
        return;
    }

    // Count the number of '0's between the first and last '1'
    int changes = 0;
    for (int i = first; i <= last; ++i) {
        if (S[i] == '0') {
            changes++;
        }
    }

    cout << changes << "\n";
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
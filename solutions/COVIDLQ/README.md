# [COVID Pandemic and Long Queue (COVIDLQ)](https://www.codechef.com/problems/COVIDLQ)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a queue represented by an array of size $N$ containing only $0$s and $1$s. A $1$ represents a person, and a $0$ represents an empty spot. The rule for social distancing is that any two people must be separated by at least 5 empty spots. In terms of indices, if two people are at indices $i$ and $j$ (where $i < j$), the condition is satisfied if $j - i \ge 6$. We need to determine if the given queue configuration follows this rule.

## Intuition & Mathematical Observation
The problem requires us to ensure that no two people are "too close." 
- If we encounter a person at index $i$, we need to check the position of the previously encountered person, let's call it `last_pos`.
- If `last_pos` exists (i.e., we have seen at least one person before), we check the distance: $i - last\_pos$.
- If $i - last\_pos < 6$, the social distancing rule is violated, and we can immediately conclude the answer is "NO".
- If we iterate through the entire array without violating this condition, the answer is "YES".
- To handle the first person encountered, we can initialize `last_pos` to a sufficiently small negative number (e.g., $-10$) so that the condition $i - (-10) < 6$ is never triggered for the first person.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of spots in the queue. We perform a single linear scan through the array.
- **Space Complexity**: $O(N)$ to store the input array, or $O(1)$ if we process the input elements on the fly without storing them in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence of 0s and 1s representing a queue.
 * A person is at index i if A[i] == 1.
 * Social distancing is followed if for any two people at indices i and j (i < j),
 * the distance (j - i) is at least 6.
 * 
 * Algorithm:
 * Keep track of the index of the last person seen.
 * Iterate through the array. If we find a person at index 'i' and we have seen
 * a person before at 'last_pos', check if (i - last_pos) < 6.
 * If it is, social distancing is violated.
 * Update 'last_pos' to 'i' whenever a new person is found.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int last_pos = -10; // Initialize with a value that ensures no false violation
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            if (i - last_pos < 6) {
                possible = false;
            }
            last_pos = i;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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
# [Cool Subsequences (COOLSUB)](https://www.codechef.com/problems/COOLSUB)

- **Difficulty Rating**: 1239
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find a "cool" subsequence of a given array $A$. A subsequence is defined as "cool" if the average of every non-empty subsequence of it is present in the complement of the original subsequence (the elements of $A$ not included in the chosen subsequence). If no such subsequence exists, we should output -1.

## Intuition & Mathematical Observation
The definition of a "cool" subsequence requires that for any non-empty subsequence $S'$ of our chosen subsequence $S$, the average of $S'$ must exist in the complement $A \setminus S$.

Let's test the simplest possible case: a subsequence of length 1, $S = \{x\}$.
1. The only non-empty subsequence of $S$ is $\{x\}$ itself.
2. The average of $\{x\}$ is $x$.
3. The condition states that $x$ must be present in the complement $A \setminus \{x\}$.
4. This is only possible if there is at least one other instance of $x$ in the original array $A$.

**Conclusion:** If the array contains any duplicate elements, we can simply pick a subsequence of length 1 consisting of that duplicate value. The complement will contain the other instance of that value, satisfying the condition. If all elements in the array are distinct, it is impossible to satisfy the condition for a single element, and it can be shown that no larger subsequence will satisfy the condition either. Thus, the problem reduces to finding if any element appears at least twice.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the implementation of the frequency map. Using `std::map` results in $O(N \log N)$, while `std::unordered_map` or a frequency array (if constraints allow) would result in $O(N)$. Given the constraints, $O(N \log N)$ is well within the time limit.
- **Space Complexity**: $O(N)$ to store the frequency of elements in the map.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * If there exists any value x that appears at least twice in the array A,
 * we can pick one instance of x as our subsequence. The complement will contain at 
 * least one other instance of x. Thus, the average of {x} (which is x) is present 
 * in the complement.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> counts;
    int duplicate_val = -1;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        counts[A[i]]++;
        // If we find a duplicate, we store it and can stop looking
        if (counts[A[i]] >= 2) {
            duplicate_val = A[i];
        }
    }
    
    if (duplicate_val != -1) {
        // Output length 1 and the duplicate value
        cout << 1 << "\n";
        cout << duplicate_val << "\n";
    } else {
        // If all elements are distinct, no cool subsequence exists
        cout << -1 << "\n";
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
# [Copy-Paste (RRCOPY)](https://www.codechef.com/problems/RRCOPY)

- **Difficulty Rating**: 1280
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to find the minimum size of an initial array such that we can generate $A$ using only the "Copy-Paste" operation. A "Copy-Paste" operation allows us to select any contiguous subsequence of the current array and append it anywhere in the array.

## Intuition & Mathematical Observation
The core of the problem lies in realizing that any element present in the final array $A$ must have originated from the initial array. 

If we have an initial array containing all the **distinct** elements present in $A$, we can always construct $A$ by copying the necessary elements one by one (or in groups) to their required positions. Conversely, if our initial array is missing any element that appears in $A$, it is impossible to generate that element because the "Copy-Paste" operation only replicates existing elements; it cannot create new values.

Therefore, the minimal size of the initial array is exactly the number of unique elements present in $A$. We can efficiently count these using a hash set or a frequency/boolean array.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the array. We iterate through the input array exactly once, and each lookup/insertion into our boolean array takes $O(1)$ time.
- **Space Complexity**: $O(K)$, where $K$ is the range of values in the array (in this case, $10^5$). This is used to store the `seen` status of each possible integer value.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The "Copy-Paste" operation allows us to take any contiguous subsequence and 
 * replicate it anywhere in the array. This means if we have a set of unique 
 * elements present in the final array A, we can always start with an initial 
 * array containing exactly those unique elements in any order. 
 * 
 * Since we want the minimal size of the initial array, and we must be able to 
 * form every element present in A, the smallest possible initial array 
 * must contain each unique element of A at least once. Thus, the minimal 
 * size is simply the count of distinct elements in A.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Using a boolean array to track seen elements.
    // Given constraints: Ai <= 10^5, N <= 10^5.
    vector<bool> seen(100001, false);
    int distinct_count = 0;
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (!seen[val]) {
            seen[val] = true;
            distinct_count++;
        }
    }
    
    cout << distinct_count << "\n";
}

int main() {
    // Fast I/O for performance
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
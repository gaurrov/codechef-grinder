# [Streak Star (STKSTR)](https://www.codechef.com/problems/STKSTR)

- **Difficulty Rating**: 1129
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, you are allowed to choose exactly one index $i$ ($0 \le i < N$) and multiply $A[i]$ by a given integer $X$. The goal is to maximize the length of the longest non-decreasing subarray after performing this operation.

## Intuition & Mathematical Observation
The problem asks us to find the maximum possible length of a non-decreasing subarray after a single modification. 

1. **Brute Force Approach**: Since the sum of $N$ over all test cases is small ($\le 1000$), an $O(N^2)$ approach is perfectly acceptable.
2. **Strategy**: 
   - First, calculate the longest non-decreasing subarray without any modifications.
   - Then, iterate through every index $i$ from $0$ to $N-1$.
   - Temporarily update $A[i]$ to $A[i] \times X$.
   - Calculate the length of the longest non-decreasing subarray for this modified array.
   - Keep track of the maximum length found across all possible modifications.
   - Restore $A[i]$ to its original value (backtracking) before moving to the next index.

This approach covers all possible scenarios, ensuring we find the global maximum.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case. We iterate through $N$ possible indices to modify, and for each modification, we perform a linear scan ($O(N)$) to find the longest non-decreasing subarray. Given $\sum N \le 1000$, the total operations are well within the time limit.
- **Space Complexity**: $O(N)$ to store the array $A$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array A of length N. We can multiply one element A[i] by X.
 * We want to maximize the length of the longest non-decreasing subarray.
 * Since N is small (sum of N <= 1000), we can iterate through every possible index i
 * that we might modify, perform the modification, and calculate the streak value.
 */

int get_streak(const vector<long long>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    int max_streak = 1;
    int current_streak = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] >= arr[i - 1]) {
            current_streak++;
        } else {
            max_streak = max(max_streak, current_streak);
            current_streak = 1;
        }
    }
    max_streak = max(max_streak, current_streak);
    return max_streak;
}

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Case 1: No modification
    int max_val = get_streak(A);

    // Case 2: Try modifying each index i
    for (int i = 0; i < N; ++i) {
        long long original = A[i];
        A[i] *= X;
        max_val = max(max_val, get_streak(A));
        A[i] = original; // Backtrack
    }

    cout << max_val << "\n";
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
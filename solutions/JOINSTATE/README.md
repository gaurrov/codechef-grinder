# [Join States (JOINSTATE)](https://www.codechef.com/problems/JOINSTATE)

- **Difficulty Rating**: 1043
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers and a threshold value $M$, we need to partition the array into the maximum number of contiguous subarrays such that the sum of elements in each subarray is at least $M$.

## Intuition & Mathematical Observation
To maximize the number of subarrays (states), we should aim to "close" a subarray as soon as its sum reaches or exceeds $M$. This is a classic **Greedy** approach:

1.  Maintain a `current_sum` variable initialized to 0.
2.  Iterate through the array, adding each element to `current_sum`.
3.  Whenever `current_sum` becomes $\ge M$, we have successfully formed a valid state. We increment our counter and reset `current_sum` to 0 to begin forming the next state.
4.  By resetting immediately after reaching $M$, we ensure that we don't "waste" elements that could potentially contribute to a future state, thereby maximizing the total count.

Since the problem asks for the maximum number of such partitions, this greedy strategy is optimal because delaying the closure of a state would only consume elements that could have been used to start a new state earlier.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We perform a single pass through the array.
- **Space Complexity**: $O(N)$ to store the input array. This can be optimized to $O(1)$ if we process the input elements on the fly without storing them in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N and a threshold M.
 * We need to partition the array into the maximum number of contiguous subarrays
 * such that the sum of each subarray is at least M.
 * 
 * Greedy Approach:
 * Iterate through the array and maintain a running sum.
 * As soon as the running sum reaches or exceeds M, we have formed a valid state.
 * Increment the count of states and reset the running sum to 0.
 */

void solve() {
    int N;
    long long M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int state_count = 0;
    long long current_sum = 0;
    
    for (int i = 0; i < N; ++i) {
        current_sum += A[i];
        if (current_sum >= M) {
            state_count++;
            current_sum = 0;
        }
    }
    
    cout << state_count << "\n";
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
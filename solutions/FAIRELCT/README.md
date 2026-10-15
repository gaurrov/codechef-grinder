# [Fair Elections (FAIRELCT)](https://www.codechef.com/problems/FAIRELCT)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
John Jackson and Jack Johnson are competing in an election. John has $N$ packs of votes, and Jack has $M$ packs of votes. John wants to have strictly more total votes than Jack. He is allowed to swap any of his vote packs with any of Jack's vote packs. The goal is to find the minimum number of swaps required to make John's total votes strictly greater than Jack's, or determine if it is impossible.

## Intuition & Mathematical Observation
To maximize John's total votes while minimizing the number of swaps, we should adopt a greedy strategy:
1. **Identify the bottleneck**: John needs to increase his sum while decreasing Jack's sum. This is best achieved by swapping John's smallest vote packs with Jack's largest vote packs.
2. **Sorting**: By sorting John's packs in ascending order and Jack's packs in descending order, we ensure that at each step $i$, we are comparing the smallest available pack from John ($A[i]$) with the largest available pack from Jack ($B[i]$).
3. **Greedy Condition**: We only perform a swap if $A[i] < B[i]$. If $A[i] \ge B[i]$, swapping will not increase John's total sum (or will decrease it), so no further swaps will help.
4. **Termination**: We check the condition `sumA > sumB` before every potential swap. If the condition is met, we return the current swap count. If we exhaust all possible beneficial swaps and the condition is still not met, it is impossible to win.

## Complexity Analysis
- **Time Complexity**: $O(T \times (N \log N + M \log M))$, where $T$ is the number of test cases. The dominant operations are sorting the two arrays of sizes $N$ and $M$. The subsequent linear scan takes $O(\min(N, M))$.
- **Space Complexity**: $O(N + M)$ to store the vote packs for both candidates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * John Jackson (A) wants to have strictly more votes than Jack Johnson (B).
 * To maximize John's total votes with the minimum number of swaps, we should 
 * always swap the smallest pack from John with the largest pack from Jack, 
 * provided the smallest pack from John is smaller than the largest pack from Jack.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(M);
    long long sumA = 0, sumB = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sumA += A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
        sumB += B[i];
    }

    // Sort A ascending and B descending to greedily pick best swaps
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<long long>());

    int swaps = 0;
    int limit = min(N, M);
    
    for (int i = 0; i <= limit; ++i) {
        // Check if John already has more votes
        if (sumA > sumB) {
            cout << swaps << "\n";
            return;
        }
        
        // If we can still swap and the swap is beneficial
        if (i < limit && A[i] < B[i]) {
            sumA = sumA - A[i] + B[i];
            sumB = sumB - B[i] + A[i];
            swaps++;
        } else {
            // No more beneficial swaps possible
            break;
        }
    }

    cout << -1 << "\n";
}

int main() {
    // Optimize I/O operations
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
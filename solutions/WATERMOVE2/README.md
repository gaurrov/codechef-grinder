# [Water Moving (Max) (WATERMOVE2)](https://www.codechef.com/problems/WATERMOVE2)

- **Difficulty Rating**: 934
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ cups, each containing a certain amount of water $A_i$. In one operation, we can choose any two cups $i$ and $j$ and move all the water from cup $i$ into cup $j$. We are required to perform exactly $K$ operations. The goal is to maximize the amount of water in a single cup after these $K$ operations.

## Intuition & Mathematical Observation
- Each operation allows us to combine the contents of one cup into another. Effectively, one operation reduces the total number of non-empty cups by 1.
- Starting with $N$ cups, after $K$ operations, we will have combined $K+1$ cups into one (assuming we always move water from a non-empty cup to another).
- To maximize the water in a single cup, we should greedily select the $K+1$ largest values from the initial array $A$ and sum them together.
- **Edge Case**: If $K \ge N-1$, we have enough operations to merge all $N$ cups into a single cup. In this case, the answer is simply the sum of all elements in the array.
- Therefore, the strategy is to sort the array in descending order and sum the first $\min(N, K+1)$ elements.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent summation takes $O(K)$, which is bounded by $O(N)$. Thus, the overall complexity is $O(N \log N)$ per test case.
- **Space Complexity**: $O(N)$ to store the amounts of water in the $N$ cups.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cups with amounts A_i.
 * In one operation, we move all water from cup i to cup j.
 * We must perform exactly K operations.
 * To maximize the water in one cup, we want to aggregate as much water as possible into one cup.
 * 
 * Each operation reduces the number of non-empty cups by 1.
 * With K operations, we can merge at most K+1 cups into one.
 * 
 * If K >= N-1, we can merge all N cups into one single cup. The result is the sum of all A_i.
 * If K < N-1, we can pick the K+1 largest values from the array and sum them up.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort in descending order to easily pick the largest values
    sort(A.rbegin(), A.rend());

    // We can merge at most K+1 cups.
    // If K >= N-1, we can merge all N cups.
    int num_to_merge = min((long long)N, K + 1);

    long long max_water = 0;
    for (int i = 0; i < num_to_merge; ++i) {
        max_water += A[i];
    }

    cout << max_water << "\n";
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
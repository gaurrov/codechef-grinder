# [Ada School (ADASCOOL)](https://www.codechef.com/problems/ADASCOOL)

- **Difficulty Rating**: 1004
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an $N \times M$ grid representing a classroom. We need to determine if it is possible for every student in the grid to move to an adjacent cell (up, down, left, or right) such that every student ends up in a unique cell that was previously occupied by another student. Essentially, we need to determine if the grid graph allows for a **perfect matching**.

## Intuition & Mathematical Observation
The problem asks whether we can pair up every cell in an $N \times M$ grid with an adjacent neighbor. 

1. **Bipartite Property**: A grid graph is a bipartite graph (like a checkerboard). In any bipartite graph, a perfect matching can only exist if the total number of vertices is even.
2. **Parity Check**: 
   - If the total number of cells ($N \times M$) is odd, it is impossible to pair every cell, as there will always be one cell left over.
   - If the total number of cells ($N \times M$) is even, at least one of the dimensions ($N$ or $M$) must be even. 
3. **Construction**: If at least one dimension is even, we can easily tile the grid with $1 \times 2$ or $2 \times 1$ dominoes. Since each domino covers two adjacent cells, a perfect matching is guaranteed.

Therefore, the condition simplifies to: **YES** if $(N \times M)$ is even, and **NO** if $(N \times M)$ is odd.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input dimensions.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an N x M grid. Each student must move to an adjacent cell (up, down, left, or right).
 * This is equivalent to finding a perfect matching in the grid graph where each cell is 
 * connected to its neighbors.
 * 
 * A grid graph is a bipartite graph. A perfect matching exists if and only if the total 
 * number of vertices is even.
 * 
 * If N * M is even, it means at least one of N or M must be even.
 * If both N and M are odd, N * M is odd, and a perfect matching is impossible.
 * 
 * Therefore, the condition is: YES if (N * M) % 2 == 0, otherwise NO.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // If the total number of cells is even, a perfect matching exists.
        // This happens if at least one dimension is even.
        if ((n * m) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```
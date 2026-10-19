# [Even Matrix (EVENM)](https://www.codechef.com/problems/EVENM)

- **Difficulty Rating**: 1376
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an integer $N$, construct an $N \times N$ matrix containing all integers from $1$ to $N^2$ exactly once, such that for every square submatrix, the sum of its four corners is even.

## Intuition & Mathematical Observation
The condition that the sum of the four corners of any square submatrix must be even implies a specific parity pattern. Let the corners of a square be $(r, c), (r, c+k), (r+k, c),$ and $(r+k, c+k)$. For the sum to be even, the parities of these four cells must satisfy:
$M[r, c] + M[r, c+k] + M[r+k, c] + M[r+k, c+k] \equiv 0 \pmod 2$.

This condition is satisfied if the parity of $M[i, j]$ depends solely on the parity of $(i+j)$. Specifically, if we arrange the numbers such that the parity of the cells follows a "checkerboard" pattern, the sum of any two cells separated by an even distance will have the same parity, and the sum of any two cells separated by an odd distance will have opposite parity.

A simple way to achieve this is to fill the matrix sequentially from $1$ to $N^2$ while alternating the direction of filling for each row:
1. Fill the first row from left to right.
2. Fill the second row from right to left.
3. Repeat this pattern for all subsequent rows.

This ensures that the parity of the numbers placed in the grid alternates correctly, satisfying the corner-sum condition for all possible square submatrices.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$, as we iterate through each cell of the $N \times N$ matrix exactly once to fill and print it.
- **Space Complexity**: $O(N)$ to store a single row before printing, or $O(1)$ if printing directly.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * We need to construct an N x N matrix with numbers 1 to N^2 such that
 * for any square submatrix, the sum of the corners is even.
 * 
 * Parity condition:
 * M[r,c] + M[r+a, c+a] is even => M[r,c] and M[r+a, c+a] have the same parity.
 * M[r,c+a] + M[r+a, c] is even => M[r,c+a] and M[r+a, c] have the same parity.
 * 
 * This is satisfied if the parity of M[i,j] depends only on (i+j) mod 2.
 * A simple construction:
 * Fill row i with numbers such that parity alternates.
 */

void solve() {
    int N;
    cin >> N;
    int current = 1;
    for (int i = 0; i < N; ++i) {
        vector<int> row(N);
        if (i % 2 == 0) {
            // Fill left to right
            for (int j = 0; j < N; ++j) {
                row[j] = current++;
            }
        } else {
            // Fill right to left
            for (int j = N - 1; j >= 0; --j) {
                row[j] = current++;
            }
        }
        for (int j = 0; j < N; ++j) {
            cout << row[j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```
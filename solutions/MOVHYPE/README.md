# [Movie Hype (MOVHYPE)](https://www.codechef.com/problems/MOVHYPE)

- **Difficulty Rating**: 921
- **Solved in**: 1 attempt(s)

## Problem Summary
In a theater with $2N+1$ seats, people are sitting in all odd-numbered seats ($1, 3, 5, \dots, 2N+1$). Each person has a specific "hype level." The empty seats are located at even positions ($2, 4, \dots, 2N$). The "loudness" of an empty seat is defined as the maximum hype level of the two people sitting immediately adjacent to it. We need to find the minimum possible loudness among all $N$ empty seats.

## Intuition & Mathematical Observation
- The people are sitting at indices $1, 3, 5, \dots, 2N+1$. Let's store their hype levels in an array $A$ of size $N+1$, where $A[0]$ corresponds to seat 1, $A[1]$ to seat 3, and so on, up to $A[N]$ for seat $2N+1$.
- An empty seat at position $2i$ (where $i$ ranges from $1$ to $N$) is adjacent to the person at seat $2i-1$ and the person at seat $2i+1$.
- In our 0-indexed array $A$, the person at seat $2i-1$ is at index $i-1$ and the person at seat $2i+1$ is at index $i$.
- Therefore, the loudness of the $i$-th empty seat is simply $\max(A[i-1], A[i])$.
- To solve the problem, we iterate through all adjacent pairs in the input array, calculate the maximum of each pair, and track the minimum value found across all pairs.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a single pass through the array of $N+1$ elements.
- **Space Complexity**: $O(N)$ to store the hype levels of the $N+1$ people.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The theater has 2N+1 seats.
 * Occupied seats are 1, 3, 5, ..., 2N+1.
 * Empty seats are 2, 4, 6, ..., 2N.
 * 
 * Let A_0, A_1, ..., A_N be the hype levels of people in seats 1, 3, 5, ..., 2N+1.
 * Seat 2 is between seat 1 and 3. Loudness = max(A_0, A_1).
 * Seat 4 is between seat 3 and 5. Loudness = max(A_1, A_2).
 * Seat 2i is between seat 2i-1 and 2i+1. Loudness = max(A_{i-1}, A_i).
 * 
 * We need to find the minimum loudness among all possible empty seats.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N + 1);
    for (int i = 0; i <= N; ++i) {
        cin >> A[i];
    }
    
    // Initialize min_loudness with a value larger than any possible hype level
    long long min_loudness = 200; 
    
    // There are N empty seats.
    // Corresponding to pairs (A_0, A_1), (A_1, A_2), ..., (A_{N-1}, A_N)
    for (int i = 0; i < N; ++i) {
        long long current_loudness = max(A[i], A[i + 1]);
        if (current_loudness < min_loudness) {
            min_loudness = current_loudness;
        }
    }
    
    cout << min_loudness << "\n";
}

int main() {
    // Fast I/O
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
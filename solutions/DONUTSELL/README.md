# [Selling Donuts (DONUTSELL)](https://www.codechef.com/problems/DONUTSELL)

- **Difficulty Rating**: 754
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ types of donuts, each with a specific initial quantity stored in an array $A$. A sequence of $M$ customers arrives, where each customer requests a specific type of donut ($B_i$). If the requested donut type is available (quantity $> 0$), we decrement the count for that type. If the quantity is $0$, the customer is considered "sad." The goal is to calculate the total number of sad customers after all $M$ requests have been processed.

## Intuition & Mathematical Observation
The problem can be solved using a direct simulation approach. Since the constraints are small ($N, M \le 100$), we do not need any complex data structures. 

1. **State Tracking**: We maintain the current inventory of donuts in an array.
2. **Processing**: For each customer request, we check the current inventory for the requested type:
   - If `A[type] > 0`: The request is fulfilled, and we decrement the inventory count.
   - If `A[type] == 0`: The request cannot be fulfilled, so we increment our counter for sad customers.
3. **Efficiency**: Because we process each customer exactly once and perform constant-time operations (array access and decrement) for each, the simulation is highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(M)$ per test case, where $M$ is the number of customers. We iterate through the list of requests exactly once.
- **Space Complexity**: $O(N)$, where $N$ is the number of donut types, to store the inventory counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N types of donuts with initial counts A_i.
 * M customers arrive sequentially, each requesting one donut of type B_i.
 * If A[B_i] > 0, we decrement A[B_i] and the customer is satisfied.
 * If A[B_i] == 0, the customer is sad.
 * We need to count the total number of sad customers.
 * 
 * Constraints: N, M, A_i <= 100.
 * A simple simulation is O(M) per test case, which is well within the time limit.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    // Using 1-based indexing for convenience, so size N+1
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int sad_customers = 0;
    for (int i = 0; i < M; ++i) {
        int type;
        cin >> type;
        
        // Check if the requested donut type is available
        if (A[type] > 0) {
            A[type]--;
        } else {
            // No donuts left of this type, customer is sad
            sad_customers++;
        }
    }

    cout << sad_customers << "\n";
}

int main() {
    // Fast I/O setup
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
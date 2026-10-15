# [Bus Seating (BUSSEAT)](https://www.codechef.com/problems/BUSSEAT)

- **Difficulty Rating**: 640
- **Solved in**: 1 attempt(s)

## Problem Summary
In a bus with $N$ rows, each containing 2 seats, passengers board one by one. The seating strategy is as follows:
1. Passengers prefer to sit in an empty row (one person per row).
2. If no empty row is available, they sit in a row that already has one person.

We need to calculate the total number of people who are sitting next to someone after $K$ passengers have boarded.

## Intuition & Mathematical Observation
The problem can be broken down into two phases based on the number of passengers $K$ relative to the number of rows $N$:

1. **Phase 1 ($K \le N$):**
   - Every passenger can choose an empty row. Since each row has 2 seats and only 1 person sits in each row, no one will have a neighbor.
   - **Result:** 0 people are sitting next to someone.

2. **Phase 2 ($K > N$):**
   - The first $N$ passengers occupy one seat in each of the $N$ rows.
   - The remaining $(K - N)$ passengers must sit in rows that already contain one person.
   - When a new passenger enters a row that already has one person, both the person already seated and the new passenger now have a neighbor.
   - Therefore, each of the $(K - N)$ new passengers creates a pair of people sitting next to each other.
   - **Result:** $(K - N) \times 2$ people are sitting next to someone.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N rows, each with 2 seats. Total seats = 2N.
 * People enter one by one.
 * Strategy:
 * 1. People prefer to sit in an empty row.
 * 2. If no empty row is available, they sit next to someone.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k <= n) {
            // Everyone gets their own row, no one has a neighbor.
            cout << 0 << "\n";
        } else {
            // (K - N) people join rows that already have 1 person.
            // Each such action makes 2 people have a neighbor.
            cout << (k - n) * 2 << "\n";
        }
    }

    return 0;
}
```
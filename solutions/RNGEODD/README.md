# [Range Odd (RNGEODD)](https://www.codechef.com/problems/RNGEODD)

- **Difficulty Rating**: -1
- **Solved in**: 2 attempt(s)

## Problem Summary
Given two integers $L$ and $R$, the task is to output all odd integers present in the inclusive range $[L, R]$ in increasing order.

## Intuition & Mathematical Observation
To solve this efficiently, we don't need to check every number in the range. Instead, we can identify the first odd number within the range and then iterate by adding 2 until we exceed $R$.

1. **Finding the Start**: If $L$ is odd, our starting point is $L$. If $L$ is even, the first odd number is $L + 1$. This can be expressed as:
   `start = (L % 2 != 0) ? L : L + 1;`
2. **Iteration**: Once the starting odd number is found, every subsequent odd number is obtained by adding 2 to the previous one. We continue this process as long as the current number is less than or equal to $R$.
3. **Efficiency**: This approach ensures we only visit the numbers we intend to print, making the loop run exactly $N/2$ times (where $N$ is the number of elements in the range).

## Complexity Analysis
- **Time Complexity**: $O(K)$, where $K$ is the number of odd integers in the range $[L, R]$. In the worst case, this is $O(R - L)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the range boundaries and the current iterator.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * Given L and R, we need to print all odd numbers in the range [L, R] inclusive.
 * 
 * Approach:
 * 1. Start from L.
 * 2. If L is even, increment to L+1 to get the first odd number.
 * 3. Iterate from that starting point up to R, incrementing by 2 in each step.
 * 4. Print each number followed by a space.
 */

int main() {
    // Optimize I/O operations for faster execution
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L, R;
    if (!(std::cin >> L >> R)) return 0;

    // Find the first odd number >= L
    int start = (L % 2 != 0) ? L : L + 1;

    // Print all odd numbers up to R
    bool first = true;
    for (int i = start; i <= R; i += 2) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << i;
        first = false;
    }
    std::cout << std::endl;

    return 0;
}
```
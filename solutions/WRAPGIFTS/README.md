# [Christmas Gifts (WRAPGIFTS)](https://www.codechef.com/problems/WRAPGIFTS)

- **Difficulty Rating**: 574
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has 1000 square centimeters of wrapping paper. Given the dimensions (Height $H$, Length $L$, and Width $W$) of a rectangular gift box, calculate the maximum number of such gifts that can be fully wrapped using the available paper.

## Intuition & Mathematical Observation
The surface area of a rectangular prism (box) is calculated using the formula:
$$\text{Surface Area} = 2 \times (H \times L + L \times W + W \times H)$$

Since we have a fixed amount of paper (1000 units), the number of gifts we can wrap is determined by how many times the surface area of one gift fits into the total paper. This is a simple division problem where we take the floor of the result:
$$\text{Number of Gifts} = \lfloor \frac{1000}{\text{Surface Area}} \rfloor$$

Given the constraints ($H, L, W \le 10$), the surface area will range between 6 and 600, which easily fits within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the dimensions and the calculated area.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The surface area of a rectangular box with dimensions H, L, and W is given by:
 * Surface Area = 2 * (H*L + L*W + W*H)
 * 
 * Chef has a total of 1000 square centimeters of wrapping paper.
 * The number of gifts that can be wrapped is the floor of (Total Area / Surface Area of one gift).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long h, l, w;
        cin >> h >> l >> w;

        // Calculate surface area of one gift
        long long surface_area = 2 * (h * l + l * w + w * h);

        // Total available paper
        long long total_paper = 1000;

        // Calculate maximum number of complete gifts using integer division
        long long max_gifts = total_paper / surface_area;

        cout << max_gifts << "\n";
    }

    return 0;
}
```
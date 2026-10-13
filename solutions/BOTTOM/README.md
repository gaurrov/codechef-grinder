# [Guess the bottom face (BOTTOM)](https://www.codechef.com/problems/BOTTOM)

- **Difficulty Rating**: 815
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the value of the top face of a standard six-sided die, determine the value of the face on the bottom. A standard die is defined by the property that the sum of the numbers on any two opposite faces is always 7.

## Intuition & Mathematical Observation
In a standard die, the faces are numbered from 1 to 6. The pairs of opposite faces are (1, 6), (2, 5), and (3, 4). 

If the top face is $X$, and the bottom face is $Y$, the problem states that:
$$X + Y = 7$$

By rearranging this equation, we can find the bottom face $Y$ for any given top face $X$:
$$Y = 7 - X$$

Since the input $X$ is guaranteed to be between 1 and 6, this simple subtraction will always yield the correct opposite face.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time $O(1)$ arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * In a standard die, the sum of opposite faces is always 7.
 * Given the top face value X, the bottom face value Y must satisfy:
 * X + Y = 7
 * Therefore, Y = 7 - X.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the bottom face
        int bottom = 7 - x;
        
        // Output the result
        cout << bottom << "\n";
    }

    return 0;
}
```
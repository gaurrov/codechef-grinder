# [Maximum Score (MAXSCORE7)](https://www.codechef.com/problems/MAXSCORE7)

- **Difficulty Rating**: 1202
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an array $A$ of size $N$ consisting only of $0$s and $1$s. You perform an operation repeatedly until the array is empty: pick two adjacent elements $A[i]$ and $A[i+1]$, add $|A[i] - A[i+1]|$ to your total score, and remove those two elements from the array. The goal is to maximize the total score obtained.

## Intuition & Mathematical Observation
1. **Operation Analysis**: The value added to the score is $|A[i] - A[i+1]|$.
   - If the pair is $(0, 0)$ or $(1, 1)$, the score added is $|0-0|=0$ or $|1-1|=0$.
   - If the pair is $(0, 1)$ or $(1, 0)$, the score added is $|0-1|=1$ or $|1-0|=1$.
2. **Goal**: To maximize the score, we want to form as many $(0, 1)$ or $(1, 0)$ pairs as possible.
3. **Constraint**: Each operation removes two elements. If we have $c_0$ zeros and $c_1$ ones, every time we pick a pair with a difference of $1$, we consume exactly one $0$ and one $1$.
4. **Conclusion**: Since we want to maximize the number of pairs with different values, and each such pair consumes one $0$ and one $1$, the maximum number of such pairs we can form is limited by the count of the minority element. Thus, the maximum score is simply $\min(c_0, c_1)$. Because the array is reduced by 2 elements at a time, we can always arrange the removals to pair up the minority elements with the majority elements until one type is exhausted.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array, as we iterate through the array once to count the $0$s and $1$s.
- **Space Complexity**: $O(1)$, as we only store the counts of $0$s and $1$s regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A consists only of 0s and 1s.
 * The operation is to pick adjacent elements A[i], A[i+1], add |A[i] - A[i+1]| to the score,
 * and remove them.
 * 
 * Note that |A[i] - A[i+1]| is 1 if the pair is (0, 1) or (1, 0), and 0 if the pair is (0, 0) or (1, 1).
 * We want to maximize the number of (0, 1) or (1, 0) pairs we can form.
 * 
 * Let c0 be the total count of 0s and c1 be the total count of 1s in the array.
 * Each operation removes one 0 and one 1 (if we pick a pair with difference 1)
 * or two 0s or two 1s (if we pick a pair with difference 0).
 * 
 * Since we want to maximize the score, we want to pair as many 0s with 1s as possible.
 * Each such pair contributes 1 to the score.
 * If we have c0 zeros and c1 ones, we can form at most min(c0, c1) pairs of (0, 1).
 */

void solve() {
    int N;
    cin >> N;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == 0) {
            c0++;
        } else {
            c1++;
        }
    }
    
    // The maximum score is simply the number of pairs of (0, 1) we can form.
    // Each pair (0, 1) or (1, 0) adds 1 to the score.
    // We can form min(c0, c1) such pairs.
    cout << min(c0, c1) << "\n";
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
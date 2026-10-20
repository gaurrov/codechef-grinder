# [Vaccine Production (VACCINE1)](https://www.codechef.com/problems/VACCINE1)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the starting day ($D_1, D_2$) and the daily production capacity ($V_1, V_2$) for two vaccine manufacturing companies. We need to determine the minimum number of days required to produce a total of at least $P$ vaccines. Company A starts production on day $D_1$ and Company B starts on day $D_2$.

## Intuition & Mathematical Observation
The problem asks for the smallest day $d$ such that the cumulative production of both companies meets or exceeds $P$. 

Since the constraints are small ($P \le 1000$ and $D, V \le 100$), a **simulation approach** is highly efficient. We can iterate through each day starting from day 1, incrementing a counter and adding the daily production of each company to a running total if the current day is greater than or equal to their respective start dates. 

The loop terminates as soon as the `current_vaccines` total reaches or exceeds $P$. The current day at that moment is our answer.

## Complexity Analysis
- **Time Complexity**: $O(d)$, where $d$ is the number of days required to reach $P$. Given the constraints, $d$ will be relatively small, making this approach well within the time limits.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to track the state of production.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the smallest day 'd' such that the total vaccines produced
 * by Company A and Company B is at least P.
 * 
 * Company A starts on day D1 and produces V1 per day.
 * Company B starts on day D2 and produces V2 per day.
 * 
 * Total vaccines at the end of day 'd':
 * If d < D1, A produces 0.
 * If d >= D1, A produces (d - D1 + 1) * V1.
 * If d < D2, B produces 0.
 * If d >= D2, B produces (d - D2 + 1) * V2.
 * 
 * Since the constraints are very small (P <= 1000, D, V <= 100),
 * we can simply iterate through days starting from 1 until the total
 * production reaches P.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D1, V1, D2, V2, P;
    if (!(cin >> D1 >> V1 >> D2 >> V2 >> P)) return 0;

    int current_vaccines = 0;
    int day = 0;

    // Simulate day by day
    while (current_vaccines < P) {
        day++;
        if (day >= D1) {
            current_vaccines += V1;
        }
        if (day >= D2) {
            current_vaccines += V2;
        }
    }

    cout << day << "\n";

    return 0;
}
```
# [Three Way Communications (COMM3)](https://www.codechef.com/problems/COMM3)

- **Difficulty Rating**: 1083
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the coordinates of three stations: the Chef, the Head Server, and the Sous-Chef. Each station has a maximum communication range $R$. Two stations can communicate if the Euclidean distance between them is less than or equal to $R$. We need to determine if all three stations can communicate with each other, either directly or indirectly (i.e., the graph formed by these three nodes must be connected).

## Intuition & Mathematical Observation
1. **Distance Calculation**: The Euclidean distance between two points $(x_1, y_1)$ and $(x_2, y_2)$ is $\sqrt{(x_1-x_2)^2 + (y_1-y_2)^2}$. To avoid floating-point precision issues, we compare the squared distance $(x_1-x_2)^2 + (y_1-y_2)^2$ with $R^2$.
2. **Connectivity Logic**: With three points (let's call them $A, B, C$), the graph is connected if there is a path between any two nodes. 
   - If we have at least two connections (e.g., $A-B$ and $B-C$), then $A$ can communicate with $C$ via $B$.
   - If we have three connections, it is definitely connected.
   - If we have fewer than two connections, at least one station will be isolated, making full communication impossible.
3. **Conclusion**: The condition for "yes" is that at least two of the three possible pairs must have a distance $\le R$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since there are always exactly three points, the number of operations (calculating three distances and comparing them) is constant.
- **Space Complexity**: $O(1)$, as we only store the coordinates of three points and a few variables for distances.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three points (Chef, Head Server, Sous-Chef).
 * Let the points be P1, P2, P3.
 * Two points can communicate if the Euclidean distance between them is <= R.
 * This is equivalent to distance squared <= R^2.
 * We need to check if the graph formed by these 3 nodes is connected.
 * Since there are only 3 nodes, the graph is connected if at least two pairs 
 * are connected, allowing for indirect communication.
 */

typedef long long ll;

ll distSq(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve() {
    ll R;
    cin >> R;
    ll R2 = R * R;
    
    ll x[3], y[3];
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }
    
    // Calculate distances squared between all pairs
    ll d12 = distSq(x[0], y[0], x[1], y[1]);
    ll d23 = distSq(x[1], y[1], x[2], y[2]);
    ll d13 = distSq(x[0], y[0], x[2], y[2]);
    
    bool c12 = (d12 <= R2);
    bool c23 = (d23 <= R2);
    bool c13 = (d13 <= R2);
    
    // Check connectivity:
    // If we have at least two connections, all three can communicate.
    int count = 0;
    if (c12) count++;
    if (c23) count++;
    if (c13) count++;
    
    if (count >= 2) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```
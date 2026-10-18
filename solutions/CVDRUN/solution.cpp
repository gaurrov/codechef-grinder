#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The virus starts at X and jumps by K modulo N.
 * This generates a sequence of cities: X, (X+K)%N, (X+2K)%N, ...
 * Since there are only N cities, the sequence must eventually repeat.
 * The virus will visit all cities in the set { (X + i*K) % N | i >= 0 }.
 * This set is equivalent to { (X + i*gcd(K, N)) % N | i >= 0 }.
 * Therefore, the virus reaches city Y if and only if (Y - X) is divisible by gcd(K, N).
 * 
 * Constraints: N <= 1000, T <= 100.
 * A simple simulation is sufficient as the cycle length is at most N.
 */

void solve() {
    int N, K, X, Y;
    if (!(cin >> N >> K >> X >> Y)) return;

    // We can simulate the process. Since there are at most N cities,
    // if we haven't reached Y within N steps, we will never reach it.
    vector<bool> visited(N, false);
    int current = X;
    bool found = false;

    for (int i = 0; i < N; ++i) {
        if (current == Y) {
            found = true;
            break;
        }
        if (visited[current]) {
            // Cycle detected and Y was not found
            break;
        }
        visited[current] = true;
        current = (current + K) % N;
    }

    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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
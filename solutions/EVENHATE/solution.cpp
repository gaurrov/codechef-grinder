#include <bits/stdc++.h>
using namespace std;

/**
 * Logic:
 * Each odd number flips the parity of the prefix sum.
 * To maximize odd prefix sums:
 * We want the prefix sum to be odd as often as possible.
 * If O is the number of odd integers:
 * - If O is odd, we can arrange them such that we get (O+1)/2 + E odd prefix sums.
 * - If O is even, we can arrange them such that we get O/2 + E odd prefix sums.
 * This is equivalent to (O + 1) / 2 + E.
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    int even_count = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 2 != 0) odd_count++;
        else even_count++;
    }

    if (odd_count == 0) {
        cout << 0 << "\n";
    } else {
        cout << (odd_count + 1) / 2 + even_count << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
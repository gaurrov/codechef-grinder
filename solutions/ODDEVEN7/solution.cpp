#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 'odd_count' odd numbers and 'even_count' even numbers.
 * To form an alternating sequence:
 * - If odd_count == even_count, we can use all elements: odd_count + even_count.
 * - If odd_count != even_count, we can take the smaller count (say min_c) and 
 *   match it with min_c elements of the other type, then add one more of the 
 *   majority type. Total = 2 * min_c + 1.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    int odd_count = 0;
    int even_count = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    if (odd_count == even_count) {
        cout << odd_count + even_count << "\n";
    } else {
        // We take all of the minority type and (minority + 1) of the majority type
        cout << 2 * min(odd_count, even_count) + 1 << "\n";
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
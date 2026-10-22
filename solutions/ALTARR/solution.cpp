#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is alternating if the parity of A[i] is different from A[i+1].
 * There are only two possible patterns for an alternating array of length N:
 * Pattern 1: Odd, Even, Odd, Even, ...
 * Pattern 2: Even, Odd, Even, Odd, ...
 * 
 * To find the minimum changes, we count how many elements in the original array
 * violate Pattern 1 and how many violate Pattern 2. The answer is the minimum
 * of these two counts.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // count1: changes needed for Pattern 1 (Odd at index 0)
    // count2: changes needed for Pattern 2 (Even at index 0)
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < N; ++i) {
        int parity = A[i] % 2; // 1 for odd, 0 for even
        
        // Pattern 1: index 0 is odd (1), index 1 is even (0), index 2 is odd (1)...
        // Expected parity at index i is (i % 2 == 0 ? 1 : 0)
        int expected1 = (i % 2 == 0 ? 1 : 0);
        if (parity != expected1) {
            count1++;
        }

        // Pattern 2: index 0 is even (0), index 1 is odd (1), index 2 is even (0)...
        // Expected parity at index i is (i % 2 == 0 ? 0 : 1)
        int expected2 = (i % 2 == 0 ? 0 : 1);
        if (parity != expected2) {
            count2++;
        }
    }

    cout << min(count1, count2) << "\n";
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
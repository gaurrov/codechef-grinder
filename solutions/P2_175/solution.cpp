#include <iostream>
using namespace std;

/**
 * Logic:
 * N=1: 1
 * N=2: 2
 * N=3: 1
 * N=4: 3
 * N=5: 2
 * N=6: 4
 * N=7: 3
 * N=8: 5
 * 
 * If N is odd:
 *   If N == 1, result is 1.
 *   If N > 1, result is (N + 1) / 2 - 1 = (N - 1) / 2.
 * If N is even:
 *   Result is (N / 2) + 1.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 != 0) {
            if (n == 1) cout << 1 << "\n";
            else cout << (n - 1) / 2 << "\n";
        } else {
            cout << (n / 2) + 1 << "\n";
        }
    }
    return 0;
}
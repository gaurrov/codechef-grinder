#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * Given N, we want to find X such that X is a multiple of 3 and |N - X| is minimized.
 * - If N % 3 == 0, the nearest multiple is N.
 * - If N % 3 == 1, the candidates are N-1 and N+2. Since |N - (N-1)| = 1 
 *   and |N - (N+2)| = 2, the nearest is N-1.
 * - If N % 3 == 2, the candidates are N-2 and N+1. Since |N - (N+1)| = 1 
 *   and |N - (N-2)| = 2, the nearest is N+1.
 */

void solve() {
    long long N;
    if (!(cin >> N)) return;

    int remainder = N % 3;

    if (remainder == 0) {
        cout << N << endl;
    } else if (remainder == 1) {
        cout << N - 1 << endl;
    } else {
        cout << N + 1 << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
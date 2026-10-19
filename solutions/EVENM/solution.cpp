#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * We need to construct an N x N matrix with numbers 1 to N^2 such that
 * for any square submatrix, the sum of the corners is even.
 * 
 * Parity condition:
 * M[r,c] + M[r+a, c+a] is even => M[r,c] and M[r+a, c+a] have the same parity.
 * M[r,c+a] + M[r+a, c] is even => M[r,c+a] and M[r+a, c] have the same parity.
 * 
 * This is satisfied if the parity of M[i,j] depends only on (i+j) mod 2.
 * A simple construction:
 * Fill row i with numbers such that parity alternates.
 */

void solve() {
    int N;
    cin >> N;
    int current = 1;
    for (int i = 0; i < N; ++i) {
        vector<int> row(N);
        if (i % 2 == 0) {
            // Fill left to right
            for (int j = 0; j < N; ++j) {
                row[j] = current++;
            }
        } else {
            // Fill right to left
            for (int j = N - 1; j >= 0; --j) {
                row[j] = current++;
            }
        }
        for (int j = 0; j < N; ++j) {
            cout << row[j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let n_normal be the number of normal burgers and n_premium be the number of premium burgers.
 * We have two equations:
 * 1) n_normal + n_premium = N
 * 2) X * n_normal + Y * n_premium <= R
 * 
 * Substituting n_normal = N - n_premium into (2):
 * X * (N - n_premium) + Y * n_premium <= R
 * X * N - X * n_premium + Y * n_premium <= R
 * n_premium * (Y - X) <= R - X * N
 * 
 * Since Y > X, (Y - X) is positive.
 * n_premium <= (R - X * N) / (Y - X)
 * 
 * Also, we must satisfy:
 * 0 <= n_premium <= N
 * 
 * To maximize n_premium, we take the largest integer n_premium satisfying:
 * n_premium = min((long long)N, (R - (long long)X * N) / (Y - X))
 * 
 * If R < X * N, it is impossible to buy N burgers even if all are normal, so output -1.
 * If the calculated n_premium < 0, it is impossible, output -1.
 */

void solve() {
    long long X, Y, N, R;
    cin >> X >> Y >> N >> R;

    // Minimum cost to buy N burgers is N * X (all normal)
    if (R < N * X) {
        cout << -1 << "\n";
        return;
    }

    // Maximum possible premium burgers
    // n_premium * (Y - X) <= R - X * N
    long long max_premium = (R - N * X) / (Y - X);
    
    // We can't have more than N burgers total
    if (max_premium > N) {
        max_premium = N;
    }

    long long n_premium = max_premium;
    long long n_normal = N - n_premium;

    cout << n_normal << " " << n_premium << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
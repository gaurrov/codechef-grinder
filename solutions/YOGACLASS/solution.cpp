#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N hours.
 * Type 1: 1 hour, earns X.
 * Type 2: 2 hours, earns Y.
 * 
 * We want to maximize earnings.
 * Since Y > X, we should prioritize Type 2 sessions as much as possible.
 * Each Type 2 session consumes 2 hours and earns Y.
 * If we take k sessions of Type 2, we use 2*k hours and earn k*Y.
 * The remaining (N - 2*k) hours can be filled with Type 1 sessions, earning (N - 2*k)*X.
 * 
 * The number of Type 2 sessions we can take is at most N/2.
 * Total earnings = (k * Y) + ((N - 2*k) * X)
 *                = k * Y + N * X - 2 * k * X
 *                = N * X + k * (Y - 2 * X)
 * 
 * If (Y - 2 * X) > 0, we should maximize k (take as many Type 2 sessions as possible).
 * If (Y - 2 * X) <= 0, we should minimize k (take 0 Type 2 sessions, i.e., all Type 1).
 * 
 * Actually, the logic is simpler:
 * We can take floor(N/2) sessions of Type 2.
 * If N is odd, we will have 1 hour left, which must be a Type 1 session.
 * So, max earnings = (N / 2) * Y + (N % 2) * X.
 * However, we must compare this with taking only Type 1 sessions (N * X) 
 * in case Y < 2*X.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        // Option 1: Maximize Type 2 sessions
        long long num_type2 = n / 2;
        long long remainder = n % 2;
        long long earnings_with_type2 = (num_type2 * y) + (remainder * x);

        // Option 2: Only Type 1 sessions
        long long earnings_only_type1 = n * x;

        // The answer is the maximum of the two strategies
        cout << max(earnings_with_type2, earnings_only_type1) << "\n";
    }

    return 0;
}
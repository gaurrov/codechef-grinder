#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the smallest X > N such that parity(digitSum(N)) != parity(digitSum(X)).
 * Since N < 10^9, the digit sum is at most 9 * 9 = 81.
 * The parity of the digit sum changes very frequently as we increment N.
 * In fact, for any N, checking N+1, N+2, ... will find the required X very quickly.
 * Even in the worst case (e.g., N=19, digitSum=10, N+1=20, digitSum=2, N+2=21, digitSum=3),
 * the gap between N and X is very small. A simple linear search is optimal.
 */

int getDigitSum(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    long long n;
    cin >> n;
    
    int targetParity = getDigitSum(n) % 2;
    long long x = n + 1;
    
    while (true) {
        if (getDigitSum(x) % 2 != targetParity) {
            cout << x << "\n";
            break;
        }
        x++;
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
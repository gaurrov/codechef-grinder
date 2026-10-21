#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be a string of length N.
 * L(V) = S implies V[1...N-1] + V[0] = S[0...N-1]
 * This means V[i] = S[(i+1) % N]
 * R(V) = S implies V[N-1] + V[0...N-2] = S[0...N-1]
 * This means V[i] = S[(i-1+N) % N]
 * 
 * Combining these, we need to check if shifting S left by 1 is the same as 
 * shifting S right by 1.
 * Specifically, if we shift S left by 1 to get L(S), and shift S right by 1 
 * to get R(S), the condition L(V) = S and R(V) = S is equivalent to 
 * checking if L(S) == R(S).
 * 
 * For strings of length <= 2, the condition is always satisfied.
 * For length > 2, we perform the shifts and compare.
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    if (n <= 2) {
        cout << "YES" << "\n";
        return;
    }
    
    // Left shift L(S): move first char to end
    string l_s = s.substr(1) + s[0];
    
    // Right shift R(S): move last char to beginning
    string r_s = s[n - 1] + s.substr(0, n - 1);
    
    if (l_s == r_s) {
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
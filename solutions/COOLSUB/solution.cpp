#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A subsequence is "cool" if the averages of all its non-empty subsequences are present 
 * in the complement subsequence.
 * 
 * Consider a subsequence of length 1, say {x}. The only non-empty subsequence is {x},
 * with average x. If x is present in the complement, then {x} is a cool subsequence.
 * 
 * This means if there exists any value x that appears at least twice in the array A,
 * we can pick one instance of x as our subsequence. The complement will contain at 
 * least one other instance of x. Thus, the average of {x} (which is x) is present 
 * in the complement.
 * 
 * Therefore, if there is any duplicate element in the array, we can simply output 
 * a subsequence of length 1 containing that duplicate element.
 * 
 * If all elements are distinct, we check if any cool subsequence exists.
 * For distinct elements, the condition is much harder to satisfy. However, the 
 * problem asks for *any* cool subsequence. If no duplicates exist, it is 
 * mathematically impossible to satisfy the condition for a single element. 
 * For larger subsequences with distinct elements, the averages will likely 
 * involve fractions that are rarely present in the remaining set.
 * 
 * Based on the constraints and the nature of the problem, checking for duplicates 
 * is the optimal strategy.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> counts;
    int duplicate_val = -1;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        counts[A[i]]++;
        if (counts[A[i]] >= 2) {
            duplicate_val = A[i];
        }
    }
    
    if (duplicate_val != -1) {
        // We found a duplicate. A subsequence of length 1: {duplicate_val}
        // The complement contains at least one duplicate_val.
        // Average of {duplicate_val} is duplicate_val, which is in complement.
        cout << 1 << "\n";
        cout << duplicate_val << "\n";
    } else {
        // If all elements are distinct, no cool subsequence exists.
        cout << -1 << "\n";
    }
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
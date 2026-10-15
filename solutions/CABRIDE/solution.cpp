#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A cab can hold at most 4 people.
 * Cost for X people in one cab = max(200, 100 * X).
 * 
 * If we put X people in a cab:
 * - If X = 1, cost = max(200, 100) = 200.
 * - If X = 2, cost = max(200, 200) = 200.
 * - If X = 3, cost = max(200, 300) = 300.
 * - If X = 4, cost = max(200, 400) = 400.
 * 
 * To minimize total cost for N people:
 * We want to pack as many people as possible into cabs such that the cost per person is minimized.
 * The cost per person for a full cab (4 people) is 400/4 = 100.
 * The cost per person for a cab with 2 people is 200/2 = 100.
 * The cost per person for a cab with 1 person is 200/1 = 200.
 * 
 * Strategy:
 * We should prioritize filling cabs with 2 people or 4 people to maintain a rate of 100 per person.
 * Any N can be represented as a sum of 2s and 4s (if N is even) or a combination involving 3s.
 * Actually, since 2 people cost 200, we can always group people into pairs of 2 to get a cost of 100 per person.
 * If N is odd, we must have at least one cab with an odd number of people. 
 * A cab with 3 people costs 300 (100 per person).
 * So, for any N:
 * - If N is even, we can use cabs of 2 people each: (N/2) * 200 = 100 * N.
 * - If N is odd, we can use one cab of 3 people and the rest in pairs of 2: 300 + ((N-3)/2) * 200 = 300 + 100 * (N-3) = 100 * N.
 * 
 * In all cases, the minimum cost is 100 * N, provided N >= 2.
 * For N = 1, cost is 200.
 */

void solve() {
    long long N;
    cin >> N;
    if (N == 1) {
        cout << 200 << "\n";
    } else {
        cout << 100 * N << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
# [Discrepancies in the Voters List (VOTERS)](https://www.codechef.com/problems/VOTERS)

- **Difficulty Rating**: 1114
- **Solved in**: 1 attempt(s)

## Problem Summary
We are provided with three separate lists of voter IDs, each already sorted in ascending order. Our task is to identify all voter IDs that appear in at least two of the three lists. The final output must list these IDs in ascending order, preceded by the total count of such IDs.

## Intuition & Mathematical Observation
Since the total number of IDs across all three lists is at most 150,000 ($50,000 \times 3$), we need an efficient way to track occurrences. 

1. **Frequency Counting**: We can use a hash map or a balanced binary search tree to store the frequency of each ID. 
2. **Sorting**: The problem requires the output to be in ascending order. Using a `std::map` in C++ is ideal because it stores keys in sorted order automatically.
3. **Filtering**: After populating the map with all IDs from the three lists, we simply iterate through the map and collect all keys where the associated value (frequency) is $\ge 2$.
4. **Efficiency**: Given the constraints, an $O(N \log N)$ approach (where $N$ is the total number of IDs) is well within the time limit of 1.15 seconds.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$, where $N$ is the total number of IDs ($N_1 + N_2 + N_3$). Inserting into a `std::map` takes $O(\log K)$ per insertion, where $K$ is the number of unique IDs. Iterating through the map takes $O(K)$.
- **Space Complexity**: $O(N)$, as we store each unique ID in the map. In the worst case, all IDs are unique, requiring space proportional to the total number of inputs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three sorted lists of voter IDs. We need to find IDs that appear
 * in at least two of the three lists.
 * 
 * Constraints:
 * N1, N2, N3 <= 50,000. Total IDs <= 150,000.
 * Time limit: ~1.15s.
 * 
 * Approach:
 * Since the total number of IDs is relatively small (150,000), we can use a 
 * frequency map (std::map) to count occurrences of each ID.
 * Given the constraints and the requirement for ascending order, a std::map 
 * is efficient enough (O(N log N)) and keeps keys sorted.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, n3;
    if (!(cin >> n1 >> n2 >> n3)) return 0;

    // Using a map to store the frequency of each ID.
    // Map keys are automatically sorted.
    map<int, int> counts;

    int total_elements = n1 + n2 + n3;
    for (int i = 0; i < total_elements; ++i) {
        int id;
        cin >> id;
        counts[id]++;
    }

    // Collect IDs that appear at least twice
    vector<int> result;
    for (auto const& [id, count] : counts) {
        if (count >= 2) {
            result.push_back(id);
        }
    }

    // Output the count of such IDs
    cout << result.size() << "\n";
    
    // Output the IDs in ascending order
    for (int id : result) {
        cout << id << "\n";
    }

    return 0;
}
```
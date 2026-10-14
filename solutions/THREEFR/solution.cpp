#include <iostream>

int main() {
    // Optimize I/O operations for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    if (!(std::cin >> T)) return 0;

    while (T--) {
        int X, Y, Z;
        std::cin >> X >> Y >> Z;

        // The condition derived from (A-B) + (B-C) + (C-A) = 0 is:
        // s1*X + s2*Y + s3*Z = 0, where s_i are in {1, -1}.
        // This simplifies to checking if one value is the sum of the other two.
        if ((X + Y == Z) || (X + Z == Y) || (Y + Z == X)) {
            std::cout << "yes" << "\n";
        } else {
            std::cout << "no" << "\n";
        }
    }

    return 0;
}
class Solution {
public:
    long long nCr(int n, int r) {
        if (r < 0 || n < r) return 0;
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
        }
        return res;
    }

    long long distributeCandies(int n, int limit) {
        long long total = nCr(n + 2, 2);

        for (int i = 1; i <= 3; ++i) {
            for (int mask = 0; mask < (1 << 3); ++mask) {
                if (__builtin_popcount(mask) != i) continue;

                int reduced = 0;
                for (int j = 0; j < 3; ++j) {
                    if (mask & (1 << j)) reduced += (limit + 1);
                }

                int remaining = n - reduced;
                long long ways = nCr(remaining + 2, 2);
                if (i % 2 == 1) total -= ways;
                else total += ways;
            }
        }

        return total;
    }
};
     
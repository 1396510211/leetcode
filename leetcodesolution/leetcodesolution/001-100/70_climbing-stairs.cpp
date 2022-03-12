#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) {
            return n;
        }
        std::vector<int>dp(n);
        dp[0] = 1;
        dp[1] = 2;
        for (size_t i = 2; i < n; i++) {
            dp[i] = dp[i-1] + dp[i - 2];
        }
        return dp[(size_t)n-1];
    }
};
class Solution {
    int helper(int level, int n) {
        if(level > n)
            return 0;
        if(level == n) 
            return 1;
        int ans = 0;
        for(int i = 1; i <= 2; i++) {
            if(level + i <= n) {
                int ways = helper(level + i, n);
                ans += ways;
            }
        }
        return ans;
    }
public:
    int climbStairs(int n) {
        int ways = helper(0, n);
        return ways;
    }
};

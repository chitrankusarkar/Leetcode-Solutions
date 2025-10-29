class Solution {
    bool helper(string &s, int idx, int cnt, vector<vector<int>>& dp) {
        if(cnt < 0)
            return false;
        if(idx == s.size())
            return (cnt == 0);

        if(dp[idx][cnt] != -1)
            return dp[idx][cnt];

        bool res = false;
        if(s[idx] == '(')
            res = helper(s, idx + 1, cnt + 1, dp);
        else if(s[idx] == ')')
            res = helper(s, idx + 1, cnt - 1, dp);
        else
            res = helper(s, idx + 1, cnt + 1, dp) ||
                  helper(s, idx + 1, cnt - 1, dp) ||
                  helper(s, idx + 1, cnt, dp);

        return dp[idx][cnt] = res;
    }

public:
    bool checkValidString(string s) {
        int n = s.size();
        // dp[idx][cnt] where cnt <= n (max open parentheses count)
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helper(s, 0, 0, dp);
    }
};

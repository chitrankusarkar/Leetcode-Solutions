class Solution {
public:
    vector<string> ans;
    void helper(int n, string s) {
        if(n == 0) {
            ans.push_back(s);
            return;
        }
        if(s.empty() || s.back() == '1') {
            helper(n - 1, s + '0');
            helper(n - 1, s + '1');
        }
        else {
            helper(n - 1, s + '1');
        }
    }
    vector<string> validStrings(int n) {
        helper(n, "");
        return ans;
    }
};

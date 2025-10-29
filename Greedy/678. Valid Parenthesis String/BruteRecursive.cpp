class Solution {
    bool helper(string s, int idx, int cnt) {
        if(cnt < 0)
            return false;
        if(idx == s.size())
            return (cnt == 0);
        if(s[idx] == '(')
            return helper(s, idx + 1, cnt + 1);
        if(s[idx] == ')')
            return helper(s, idx + 1, cnt - 1);
        if(s[idx] == '*')
            return helper(s, idx + 1, cnt + 1) || helper(s, idx + 1, cnt - 1) || helper(s, idx + 1, cnt);
        return false;
    }
 public:
    bool checkValidString(string s) {
        bool res = helper(s, 0, 0);
        return res;
    }
};

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() == 1)
            return 1;
        unordered_map<char, int> mpp;
        int res = 0;
        bool hasOdd = false;
        for(auto it: s)
            mpp[it]++;
        for(auto it: mpp) {
            if(it.second % 2 == 0)
                res += it.second;
            else {
                res += it.second - 1;
                hasOdd = true;
            }
        }
        if(hasOdd)
            res += 1;
        return res;
    }
};

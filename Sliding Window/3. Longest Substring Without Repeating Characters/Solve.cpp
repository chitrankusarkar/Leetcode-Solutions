class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, mx = INT_MIN;
        unordered_map<char, int> mpp;
        while(j < s.size()) {
            mpp[s[j]]++;
            if(mpp.size() == j - i + 1) { // curr window == mp size then all uniwque is there
                mx = max(mx, j - i + 1);
                j++;
            }
            else if(mpp.size() < j - i + 1) { // unique char is less in map than curr window
                while(mpp.size() < j - i + 1) {
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0) // if one item freq is 0 remove that
                        mpp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return(mx == INT_MIN) ? 0 : mx;
    }
};

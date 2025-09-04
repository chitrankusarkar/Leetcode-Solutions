class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int i = 0, j = 0, mx = INT_MIN;
        unordered_map<char, int> mpp;
        while(j < s.size()) {
            mpp[s[j]]++; // store each char freq
            if(mpp.size() < k) // distinct element == k
                j++;
            if(mpp.size() == k) {
                mx = max(mx, j - i + 1);
                j++;
            }
            if(mpp.size() > k) {
                while(mpp.size() > k) {
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0) // when one char count is 0 remove it
                        mpp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return (mx == INT_MIN) ? -1 : mx;
    }
};

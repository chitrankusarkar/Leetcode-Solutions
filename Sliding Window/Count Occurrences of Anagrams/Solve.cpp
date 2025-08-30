class Solution {
  public:
    int search(string &pat, string &txt) {
        unordered_map<char, int> mpp;
        for(int i = 0; i < pat.size(); i++) {
            char c = pat[i];
            if(mpp.find(c) != mpp.end())
                mpp[c] += 1;
            else
                mpp[c] = 1;
        }
        
        int i = 0, j = 0, ans = 0;
        int count = mpp.size();
        
        while(j < txt.size()) {
            if(mpp.find(txt[j]) != mpp.end()) {
                mpp[txt[j]]--;
                if(mpp[txt[j]] == 0)
                    count--;
            }
            if(j - i + 1 < pat.size())
                j++;
            else if(j - i + 1 == pat.size()) {
                if(count == 0)  
                    ans++;
                if(mpp.find(txt[i]) != mpp.end()) {
                    mpp[txt[i]]++;
                    if(mpp[txt[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

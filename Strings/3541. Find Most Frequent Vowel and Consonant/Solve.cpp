class Solution {
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> vow;
        unordered_map<char, int> cons;
        int maxVowFreq = 0, maxConsFreq = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i]))
                vow[s[i]]++;
            else
                cons[s[i]]++;
        }
        for(auto it: vow) {
            if(it.second > maxVowFreq)
                maxVowFreq = it.second;
        }
        for(auto it: cons) {
            if(it.second > maxConsFreq)
                maxConsFreq = it.second;
        }
        return maxVowFreq + maxConsFreq;
    }
};

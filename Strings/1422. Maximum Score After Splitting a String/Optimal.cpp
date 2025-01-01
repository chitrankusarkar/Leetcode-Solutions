class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int cntZeros = 0, cntOnes = 0, maxi = INT_MIN;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] =='0')
                cntZeros++;
            else
                cntOnes++;
            maxi = max(maxi, cntZeros - cntOnes);
        }
        if(s[n - 1] == '1')
            cntOnes++;
        return maxi + cntOnes;
        }
};

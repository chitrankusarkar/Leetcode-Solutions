class Solution {
public:
    bool checkString(string s) {
        int aCount = 0, bCount;
        while(aCount < s.size()) {
            if(s[aCount] != 'a')
                break;
            aCount++;
        }
        bCount = aCount;
        while(bCount < s.size()) {
            if(s[bCount] != 'b')
                return false;
            bCount++;
        }
        return true;
    }
};

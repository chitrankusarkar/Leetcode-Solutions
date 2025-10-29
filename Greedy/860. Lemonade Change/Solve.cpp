class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCnt = 0, tenCnt = 0;
        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                fiveCnt++;
            }
            if(bills[i] == 10) {
                if(fiveCnt <= 0)
                    return false;
                fiveCnt--;
                tenCnt++;
            }
            if(bills[i] == 20) {
                if(tenCnt > 0 && fiveCnt > 0) {
                    tenCnt--;
                    fiveCnt--;
                }
                else if(fiveCnt >= 3)
                    fiveCnt -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};

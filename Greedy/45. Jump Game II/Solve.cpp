class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, res = 0;
        while(r < nums.size() - 1) {
            int maxi = 0;
            for(int i = 0; i <= r; i++) 
                maxi = max(i + nums[i], maxi);
            l = r + 1;
            r = maxi;
            res++;
        }
        return res;
    }
};

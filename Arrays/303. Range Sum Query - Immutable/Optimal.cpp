class NumArray {
private:
    vector<int> pre;
public:
    NumArray(vector<int>& nums) {
        pre = nums;
        pre[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            pre[i] = pre[i - 1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return pre[right] - ((left == 0) ? 0 : pre[left - 1]);
    }
};

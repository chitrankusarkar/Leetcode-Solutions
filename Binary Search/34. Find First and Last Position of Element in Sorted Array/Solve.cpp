class Solution {
    int seacrhFirstOcc(vector<int>& nums, int target) {
        int ans = -1;
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            }
            else if(target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;        
    }

    int seacrhLastOcc(vector<int>& nums, int target) {
        int ans = -1;
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            }
            else if(target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;        
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int firstOcc = seacrhFirstOcc(nums, target);
        int lastOcc = seacrhLastOcc(nums, target);
        res.push_back(firstOcc);
        res.push_back(lastOcc);
        return res;
    }
};

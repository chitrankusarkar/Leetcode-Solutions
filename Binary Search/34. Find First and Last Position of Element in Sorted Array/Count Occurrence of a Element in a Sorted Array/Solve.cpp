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
    int countFreq(vector<int>& nums, int target) {
        int first = seacrhFirstOcc(nums, target);
        if(first == -1)
            return 0;
        int last = seacrhLastOcc(nums, target);
        return last - first + 1;
        
    }
};

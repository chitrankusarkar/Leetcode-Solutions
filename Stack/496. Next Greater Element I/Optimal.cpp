class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        stack<int> s;
        unordered_map<int, int> mpp;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            if(s.empty())
                mpp[nums2[i]] = -1;
            else if(s.size() > 0 && s.top() > nums2[i])
                mpp[nums2[i]] = s.top();
            else if(s.size() > 0 && s.top() <= nums2[i]) {
                while(s.size() > 0 && s.top() <= nums2[i])
                    s.pop();
                if(s.empty())
                    mpp[nums2[i]] = -1;
                else
                    mpp[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        for(auto it: nums1) {
            res.push_back(mpp[it]);
        }
        return res;
    }
};

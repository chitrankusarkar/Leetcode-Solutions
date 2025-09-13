class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++) {
            bool find = false;
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    for(int k = j + 1; k < nums2.size(); k++) {
                        if(nums2[j] < nums2[k]) {
                            res.push_back(nums2[k]);
                            find = true;
                            break;
                        }
                    }
                }
            }
            if(!find)
                res.push_back(-1);
        }
        return res;
    }
};

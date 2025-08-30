class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;  // stores actual values now
        int i = 0, j = 0;

        while(j < nums.size()) {
            // remove smaller values from back
            while(!dq.empty() && dq.back() < nums[j])
                dq.pop_back();

            dq.push_back(nums[j]);

            // window not full yet
            if(j - i + 1 < k)
                j++;
            else if(j - i + 1 == k) {
                res.push_back(dq.front()); // front is max

                // if the outgoing element is at the front, remove it
                if(dq.front() == nums[i])
                    dq.pop_front();

                i++;
                j++;
            }
        }
        return res;
    }
};

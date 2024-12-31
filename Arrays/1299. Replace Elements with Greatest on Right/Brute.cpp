class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        if(arr.size() == 1) {
            res.push_back(-1);
            return res;
        }
        for(int i = 0; i < n - 1; i++) {
            int maxi = INT_MIN;
            for(int j = i + 1; j < n; j++) {
                maxi = max(arr[j], maxi);
            }
            res.push_back(maxi);
        }
        res.push_back(-1);
        return res;
    }
};

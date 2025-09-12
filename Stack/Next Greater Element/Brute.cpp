class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        vector<int> res;
        for(int i = 0; i < arr.size(); i++) {
            bool found = false;
            for(int j = i + 1; j < arr.size(); j++) {
                if(arr[i] < arr[j]) {
                    res.push_back(arr[j]);
                    found = true;
                    break;
                }
            }
            if(!found)
                res.push_back(-1);
        }
        return res;
    }
};

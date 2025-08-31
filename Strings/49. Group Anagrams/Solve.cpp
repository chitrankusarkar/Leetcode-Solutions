class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mpp;
        for(auto it: strs) {
            string temp = it;
            sort(temp.begin(), temp.end()); // bucket for sorted version of each word
            mpp[temp].push_back(it);
        }
        for(auto it: mpp) {
            res.push_back(it.second); // the resulantant string will be present on the map's value 
        }
        return res;
    }
};

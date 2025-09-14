class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int> temp;
        vector<int> res;
        stack<pair<int, int>> s;   
        for(int i = 0; i < arr.size(); i++) {
            if(s.empty())
                temp.push_back(-1);
            else if(s.size() > 0 && arr[i] < s.top().first) {
                temp.push_back(s.top().second);
            }
            else if(s.size() > 0 && arr[i] >= s.top().first) {
                while(s.size() > 0 && arr[i] >= s.top().first) {
                    s.pop();
                }
                if(s.empty())
                    temp.push_back(-1);
                else
                    temp.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        
        for(int i = 0; i < arr.size(); i++) {
            res.push_back(i - temp[i]);
        }
        return res;
    }
};

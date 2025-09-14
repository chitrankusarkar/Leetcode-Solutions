class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        vector<int> res;
        stack<int> s;
        for(int i = arr.size() - 1; i >= 0; i--) {
            if(s.empty())
                res.push_back(-1);
            else if(s.size() > 0 && arr[i] > s.top())
                res.push_back(s.top());
            else if(s.size() > 0 && arr[i] <= s.top()) {
                while(s.size() > 0 && arr[i] <= s.top())
                    s.pop();
                if(s.empty())
                    res.push_back(-1);
                else
                    res.push_back(s.top());
            }
            s.push(arr[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

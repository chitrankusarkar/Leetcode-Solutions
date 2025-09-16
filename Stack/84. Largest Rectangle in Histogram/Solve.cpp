class Solution {
    vector<int> nearestSmallerToLeft(vector<int>& arr) {
        vector<int> res;
        stack<pair<int, int>> st;
        for(int i = 0; i < arr.size(); i++) {
            if(st.empty())
                res.push_back(-1);
            else if(st.size() > 0 && st.top().first < arr[i])
                res.push_back(st.top().second);
            else if(st.size() > 0 && st.top().first >= arr[i]) {
                while(st.size() > 0 && st.top().first >= arr[i])
                    st.pop();
                if(st.empty())
                    res.push_back(-1);
                else
                    res.push_back(st.top().second);
            }
            st.push({arr[i], i});
        }
        return res;
    }
    
    vector<int> nearestSmallerToRight(vector<int>& arr) {
        vector<int> res;
        stack<pair<int, int>> st;
        int n = arr.size();
        for(int i = n - 1; i >= 0; i--) {
            if(st.empty())
                res.push_back(n); 
            else if(st.size() > 0 && st.top().first < arr[i])
                res.push_back(st.top().second);
            else if(st.size() > 0 && st.top().first >= arr[i]) {
                while(st.size() > 0 && st.top().first >= arr[i])
                    st.pop();
                if(st.empty())
                    res.push_back(n); 
                else
                    res.push_back(st.top().second);
            }
            st.push({arr[i], i});
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        vector<int> right = nearestSmallerToRight(heights);
        vector<int> left = nearestSmallerToLeft(heights);
        int area = 0, res = 0;
        for(int i = 0; i < heights.size(); i++) {
            area = (right[i] - left[i] - 1) * heights[i];
            res = max(area, res);
        }
        return res;
    }
};

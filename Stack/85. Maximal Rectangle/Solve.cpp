class Solution {
    vector<int> nearestSmallerLeft(vector<int>& arr) {
        vector<int> res;
        stack<pair<int, int>> s;
        for(int i = 0; i < arr.size(); i++) {
            if(s.empty())
                res.push_back(-1);
            else if(s.size() > 0 && s.top().first < arr[i])
                res.push_back(s.top().second);
            else if(s.size() > 0 && s.top().first >= arr[i]) {
                while(s.size() > 0 && s.top().first >= arr[i])
                    s.pop();
                if(s.empty())
                    res.push_back(-1);
                else
                    res.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        return res;
    }

    vector<int> nearestSmallerRight(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        stack<pair<int, int>> s;
        for(int i = n - 1; i >= 0; i--) {
            if(s.empty())
                res.push_back(n);
            else if(s.size() > 0 && s.top().first < arr[i])
                res.push_back(s.top().second);
            else if(s.size() > 0 && s.top().first >= arr[i]) {
                while(s.size() > 0 && s.top().first >= arr[i])
                    s.pop();
                if(s.empty())
                    res.push_back(n);
                else
                    res.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int maxAreaHistogram(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;
        vector<int> temp1 = nearestSmallerRight(arr);
        vector<int> temp2 = nearestSmallerLeft(arr);
        int area = 0, res = 0;
        for(int i = 0; i < arr.size(); i++) {
            area = (temp1[i] - temp2[i] - 1) * arr[i];
            res = max(area, res);
        }
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> mat(rows, vector<int>(cols));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                mat[i][j] = (matrix[i][j] - '0');
            }
        }
        vector<int> temp;
        for(int j = 0; j < cols; j++) {
            temp.push_back(mat[0][j]);
        }
        int res = maxAreaHistogram(temp);
        for(int i = 1; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(mat[i][j] == 0)
                    temp[j] = 0;
                else {
                    temp[j] += mat[i][j];
                }
            }
            res = max(res, maxAreaHistogram(temp));
        }
        return res;
    }
};

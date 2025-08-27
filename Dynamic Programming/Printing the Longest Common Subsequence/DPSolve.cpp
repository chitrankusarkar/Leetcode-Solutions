string findLCS(int n, int m,string &s1, string &s2){
  int dp[n + 1][m + 1];
	for(int i = 0; i < n + 1; i++) {
		for(int j = 0; j < m + 1; j++) {
			if(i == 0 || j == 0)
				dp[i][j] = 0;
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s1[i - 1] ==  s2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	string ans = "";

	int x = n, y = m;

	while(x > 0 && y > 0) {
		if(s1[x - 1] == s2[y - 1]) {
			ans.push_back(s1[x - 1]);
			x--;
			y--;
		}
		else {
			if(dp[x - 1][y] > dp[x][y - 1])
				x--;
			else
				y--;
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

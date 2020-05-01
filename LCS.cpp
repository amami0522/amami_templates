int LCS(string s,string t){
	int n=s.size();
	int m=t.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];
}

string LCS_string(string s,string t){
	int n=s.size();
	int m=t.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int len=dp[n][m];
	int y=n;
	int x=m;
	string ans="";
	while(len){
		if(s[y-1]==t[x-1]){
			ans=s[y-1]+ans;
			x--;
			y--;
			len--;
		}
		else if(dp[y][x]==dp[y-1][x]) y--;
		else x--;
	}
	return ans;
}

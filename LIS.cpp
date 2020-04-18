long long LIS(vector<long long> a) {
	long long n=(int)a.size();
	vector<long long> dp(n,1e18);
	for (long long i=0;i<n;i++){
		long long tmp =lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
		dp[tmp] =a[i];
	}
	long long k=0;
	while (k<n && dp[k]!= 1e18) k++;
	return k;
}

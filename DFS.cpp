void dfs(int cur, int pre) {
	for(auto&& next : to[cur]) {
		if(next == pre) continue;
		dfs(next, cur);
	}
}

struct edge{
    long long to;
    long long cost;
};

pair<long long, int> dfs(const vector<vector<edge>> &g, int idx, int par){
	pair<long long, int> ret(0, idx);
	for(auto&& e:g[idx]){
		if(e.to==par) continue;
		auto cost=dfs(g, e.to, idx);
		cost.first+=e.cost;
		ret=max(ret, cost);
	}
	return ret;
}

long long tree_diameter(const vector<vector<edge>> &g){
	auto p=dfs(g, 0, -1);
	auto q=dfs(g, p.second, -1);
	return q.first;
}

/*
vector<vector<edge>> G(n);

0-index
G[u].push_back({v, cost});

cout << tree_diameter(G) << endl;
*/

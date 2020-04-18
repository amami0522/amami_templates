//vector<vector<int>> to(n);
//vector<int> color(n);

bool is_bipartite(int current, int now_color) {
	color[current] = now_color;
	for(auto&& next : to[current]) {
		if(c[next]==now_color) return false;
		else if(!c[next] && !is_bipartite(next, -now_color)) return false;
	}
	return true;
}

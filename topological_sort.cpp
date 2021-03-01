template<typename T>
vector<int> topological_sort(const vector<vector<T>>& g) {
    const int n = (int)g.size();
    vector<int> deg(n);
    for(int i = 0; i < n; i++) {
        for(auto&& to : g[i]) ++deg[to];
    }
    stack<int> st;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) st.emplace(i);
    }
    vector<int> ord;
    while(!st.empty()) {
        auto p = st.top();
        st.pop();
        ord.emplace_back(p);
        for(auto&& to : g[p]) {
            if(--deg[to] == 0) st.emplace(to);
        }
    }
    return ord;
}

/*
vector<vector<int>> G;
vector<int> ans = topological_sort(G);
*/
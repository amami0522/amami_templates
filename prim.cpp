long long prim(int V,vector<vector<long long>> cost){
    vector<long long> mincost(V,INF);
    vector<bool> used(V,false);
    mincost[0]=0;
    int ret=0;
    while(1){
        int v=-1;
        for(int u=0;u<V;u++){
            if(!used[u] && (v==-1 || mincost[u]<mincost[v])) v=u;
        }
        if(v==-1) break;
        used[v]=true;
        ret+=mincost[v];
        for(int u=0;u<V;u++){
            mincost[u]=min(mincost[u],cost[u][v]);
        }
    }
    return ret;
}

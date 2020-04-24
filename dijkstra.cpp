#define INF ((1LL<<62)-(1LL<<31))
using P=pair<long long,long long>;

struct edge{
    long long to;
    long long cost;
};

vector<long long> dijkstra(int x,vector<vector<edge>> G){
    priority_queue<P,vector<P>,greater<P>> que;
    vector<long long> dist(G.size(),INF);
    dist[x]=0;
    que.push(P(0,x));
    while(!que.empty()){
        P tmp=que.top();
        que.pop();
        int v=tmp.second;
        if(dist[v]<tmp.first) continue;
        for(edge e:G[v]){
            if(dist[e.to]>dist[v]+e.cost){
                dist[e.to]=dist[v]+e.cost;
                que.push(P(dist[e.to],e.to));
            }
        }
    }
    return dist;
}

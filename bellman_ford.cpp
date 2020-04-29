template<typename T>
struct edge{
    long long src;
    long long to;
    T cost;
};

template<typename T>
using Edges=vector<edge<T>>;

template<typename T>
vector<T> bellman_ford(Edges<T> &edges,int V,int s){
    vector<T> dist(V,INF);
    dist[s]=0;
    for(int i=0;i<V-1;i++){
        for(auto& e:edges){
            if(dist[e.src]==INF) continue;
            dist[e.to]=min(dist[e.to],dist[e.src]+e.cost);
        }
    }
    for(auto& e:edges){
        if(dist[e.src]==INF) continue;
        if(dist[e.src]+e.cost<dist[e.to]) return vector<T>();
    }
    return dist;
}

int main(){return 0;}
/*
Egdes<ll> e;
e.push_back({from,to,cost});

auto dist=bellman_ford(e,n,start);

if(dist.empty()) cout << "NEGATIVE CYCLE\n";

for(auto d:dist){
    if(d==INF) cout << "INF\n";
    else cout << d << endl;
}
*/

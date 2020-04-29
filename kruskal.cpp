#include<bits/stdc++.h>
using namespace std;

struct edge{
    long long u;
    long long v;
    long long cost;
};

struct UnionFind {
	vector<long long> par;
	UnionFind(long long size):par(size+1,-1){}
	bool unite(long long x,long long y){
		x=root(x);
        y=root(y);
		if (x!=y){
			if(par[y]<par[x]) swap(x,y);
			par[x]+=par[y];
            par[y]=x;
		}
		return x!=y;
	}
	bool same(long long x,long long y){
        return root(x)==root(y);
    }
	int root(long long x){
        return par[x]<0?x:par[x]=root(par[x]);
    }
	int size(long long x){
        return -par[root(x)];
    }
};

bool comp(const edge& e1,const edge& e2){
    return e1.cost < e2.cost;
}

int kruskal(int n,vector<edge> tr){
    sort(tr.begin(),tr.end(),comp);
    UnionFind tree(n);
    int ret=0;
    for(auto e:tr){
        if(!tree.same(e.u,e.v)){
            tree.unite(e.u,e.v);
            ret+=e.cost;
        }
    }
    return ret;
}
/*
vector<edge> e;

e.push_back({u,v,cost});

int sum=kruskal(n,e);
*/

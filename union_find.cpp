struct UnionFind {
	vector<long long> par;
	UnionFind(long long size):par(size+1,-1){}
	bool unite(long long x,long long y){	//集合の連結
		x=root(x);
        y=root(y);
		if (x!=y){
			if(par[y]<par[x]) swap(x,y);
			par[x]+=par[y];
            par[y]=x;
		}
		return x!=y;
	}
	bool same(long long x,long long y){	//同集合内かの判定
		return root(x)==root(y);
	}
	int root(long long x){	//根を求める
		return par[x]<0?x:par[x]=root(par[x]);
	}
	int size(long long x){	//集合の大きさ
		return -par[root(x)];
	}
};

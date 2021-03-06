class Monoid{
    public:
        int unit;
        Monoid(){
            unit = 0;
        }
        int calc(int a, int b){
            return a + b;
        }
};

class SegmentTree{
    public:
        int n;
        vector<int> tree;
        Monoid mono;
        SegmentTree(vector<int> &v){
            n = 1 << (int)ceil(log2(v.size()));
            tree = vector<int>(n << 1);
            for(int i = 0; i < (int)v.size(); i++){
                update(i, v[i]);
            }
            for(int i = v.size(); i < n; i++){
                update(i, mono.unit);
            }
        }
        void update(int k, int x){
            k += n;
            tree[k] = x;
            for(k = k >> 1; k > 0; k >>= 1){
                tree[k] = mono.calc(tree[k << 1 | 0], tree[k << 1 | 1]);
            }
        }
        int query(int l, int r){
            int res = mono.unit;
            l += n;
            r += n;
            while(l < r){
                if(l & 1){
                    res = mono.calc(res, tree[l++]);
                }
                if(r & 1){
                    res = mono.calc(res, tree[--r]);
                }
                l >>= 1;
                r >>= 1;
            }
            return res;
        }
        long long operator[](int k){
            if(k - n >= 0 || k < 0){
                return -INF;
            }
            return tree[tree.size() - n + k];
        }
        void show(){
            int ret = 2;
            for(int i = 0; i < 2 * n; i++){
                cout << tree[i] << " ";
                if(i == ret - 1){
                    cout << endl;
                    ret <<= 1;
                }
            }
            cout << endl;
        }
};

/*
vector<int> v;

SegmentTree st(v);

update(k, x);   // k番目の値(0-indexed)をxに変更

st(l,r);    //[l, r)の総和
*/

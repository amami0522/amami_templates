template<typename T>
struct SparseTable{
    vector<vector<T>> st;

    SparseTable() {}

    SparseTable(const vector<T> &v){
        int b = 0;
        while((1 << b) <= (int)v.size()) ++b;
        st.assign(b, vector<T>(1 << b));
        for(int i = 0; i < (int)v.size(); i++){
            st[0][i] = v[i];
        }
        for(int i = 1; i < b; i++){
            for(int j = 0; j + (1 << i) <= (1 << b); j++){
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    //[l, r)
    inline T rmq(int l, int r){
        int b = 32 - __builtin_clz(r - l) - 1;
        return (min(st[b][l], st[b][r - (1 << b)]));
    }
};

/*
vector<long long> a(n);

SparseTable<long long> st(a);

st.rmq(l, r);    //[l, r)
*/

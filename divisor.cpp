vector<long long> divisor(long long n){
    vector<long long> ret;
    for(int64_t i=1;i*i<=n;i++){
        if(n%i==0){
            ret.push_back(i);
            if(i*i!=n) ret.push_back(n/i);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
}

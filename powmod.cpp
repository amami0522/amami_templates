long long powmod(long long a, long long b) {
    long long c = 1;
    while(b > 0) {
        if(b & 1) c = a*c%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return c;
}

#include<bits/stdc++.h>
using namespace std;

map<long long,long long> prime_factor(long long n) {
    map<long long,long long> ret;
    for(long long i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return ret;
}

int main()
{
    long long n;
    cin >> n;
    map<long long,long long> mp=prime_factor(n);
    for(auto& e:mp){
        cout << e.first << "^" << e.second << " ";
    }
    cout << endl;
    return 0;
}

/*
sample

input
140

output
2^2 5^1 7^1

 */

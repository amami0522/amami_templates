#include<bits/stdc++.h>
using namespace std;

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

int main()
{
    long long n;
    vector<long long> v;
    cin >> n;
    v=divisor(n);
    for(auto& e:v) cout << e << " ";
    cout << endl;
    return 0;
}
/*

sample

input
40

output
1 2 4 5 8 10 20 40

 */

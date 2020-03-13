#include<bits/stdc++.h>
using namespace std;

void bit_search(int n){
    for(int bit=0;bit<(1<<n);bit++){
        vector<int> v;
        for(int i=0;i<n;i++){
            if(bit&(1<<i)) v.push_back(i);
        }
        cout << "{";
        for(int i=0;i<(int)v.size();i++) cout << v[i] << " ";
        cout << "}\n";
    }
}

int main()
{
    int n;
    cin >> n;
    bit_search(n);
    return 0;
}

/*
sample_output

n=3

{}
{0 }
{1 }
{0 1 }
{2 }
{0 2 }
{1 2 }
{0 1 2 }

*/

#include<bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y){
    return __gcd(x, y);
}

long long lcm(long long x, long long y){
    return x / __gcd(x, y) * y;
}

int main()
{
    long long x,y;
    cin >> x >> y;
    cout << "GCD(" << x << ", " << y << ") = " << gcd(x,y) << endl;
    cout << "LCM(" << x << ", " << y << ") = " << lcm(x,y) << endl;
    return 0;
}

/*
example

gcd(x,y)    最大公約数
lcm(x,y)    最小公倍数

*/

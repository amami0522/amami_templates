bool IsPrime(int n){
    if (n<2) return false;
    else if(n==2) return true;
    else if(n%2==0) return false;
    double sqrtNum=sqrt(n);
    for(int i=3;i<=sqrtNum;i+=2){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

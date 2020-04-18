long long GCD(long long x, long long y) {
	if(y == 0) return x;
	return GCD(y, x % y);
}

long long LCM(long long x, long long y) {
	return x * y / GCD(x, y);
}

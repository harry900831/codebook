//for all i,j , gcd(m_i,m_j) == 1

long long m[maxn],a[maxn];

long long crt(int x){
	long long M = 1,ans = 0;
	for(int i = 0 ; i < x ; i++)M *= m[i];
	for(int i = 0 ; i < x ; i++){
		lld mi = M/m[i];
		int x,y;
		exgcd(mi,m[i],x,y);
		x = (x + m[i]) % m[i];
		ans += ((a[i] * mi) % M * x % M) % M;
	}
	return ans;
}



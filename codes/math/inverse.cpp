const int maxn = 1000000;
int inv[maxn + 5],infac[maxn + 5];

void inverse(int n,int MOD = 1000000007){
	inv[1] = inv[0] = 1;
	infac[0] = infac[1] = 1;
	for(int i = 2; i <= n ; i++){
		inv[i] = 1LL * (MOD - MOD/i) * inv[MOD % i] % MOD;
		infac[i] = 1LL * infac[i-1] * inv[i] % MOD;
	}
}


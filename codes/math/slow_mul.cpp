#define lld long long

lld slow_mul(lld a,lld b,lld c = 1000000007){
	lld t = 0;
	while(b){
		if(b&1)t = (t + a) % c;
		a = (a + a) % c;
		b >>= 1;
	}
	return t;
}



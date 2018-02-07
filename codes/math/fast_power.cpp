#define lld long long

lld fast_power(lld a,lld b,lld c = 1000000007){
	lld ret = 1;
	a %= c;
	while(b){
		if(b&1)ret = (ret*a)%c;
		a = (a*a)%c;
		b >>= 1;
	}
	return ret;
}

lld fast_power_recursion(lld a,lld b,lld c = 1000000007){
	if(b == 0)return 1;
	if(b&1)return (a*fast_power_recursion(a,b-1))%c;
	else{
		lld tmp = fast_power_recursion(a,b/2);
		return (tmp * tmp)%c;
	}
}


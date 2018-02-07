//32bit : {2,7,61};
//64bit : {2,325,9375,28178,450775,9780504,1795265022}
//num = x*2^t
int p[3] = {2,7,61};

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

bool Miller_Rabin(long long num){
	long long t = 0,x = num-1;
	while(x % 2 == 0)t++,x /= 2;
	bool is = 1;
	for(int i = 0 ; i < 3 && p[i] < num; i++){
			lld v = fast_power(p[i],x,num);
			if(v == 1 || v == num-1)continue;
			bool tt = 0;
			for(int i = 0 ; i < t-1 ; i++){
				v= v*v%num;
				if(v == num-1){
					tt = 1;
					break;
				}
			}
			if(!tt)is = 0;
	}
	return is;
}


#define lld long long

vector<lld> v;

lld pollard_rho(lld x) {
	if(!(x&1)) return 2;
 	while(1){
    	lld y=2, t = rand()%(x-1)+1, tmp = 1;
	    for (int i = 2; tmp == 1 ; i <<= 1) {
    		for (int j = 0; j < i && tmp <= 1; j++) {
		        t = (slow_mul(t, t) + 1) % x;
        		tmp = __gcd(abs(t-y), x);
			}
	    	y = t;
    	}
	    if (tmp != 0 && tmp != x) return tmp;
	}
}

void findprime(lld x){
    if(miller_rabin(x)){v.PB(x);return;}
    lld p = x;
    while(p >= x)p = pollard_rho(x);
    findprime(p);
    findprime(x/p);
}



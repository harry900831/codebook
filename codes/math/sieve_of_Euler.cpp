const int maxn = 1000000;
int euler[maxn + 5];
bitset<maxn + 5> isprime;

void euler(){
	for(int i = 1 ; i <= maxn ; i++)euler[i] = i;
	for(int i = 2 ; i <= maxn ; i++){
		if(!isprime[i]){
			euler[i]--;
			for(int j = i<<1 ; j <= maxn ; j += i){
				isprime[j] = 1;
				euler[j] -= euler[j]/i;
			}
		}
	}
}



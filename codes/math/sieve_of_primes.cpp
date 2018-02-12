const int maxn = 1000000;

bitset<maxn + 5> isprime;
vector<int> prime;

//O(nloglogn)
for(int i = 2; i * i <= maxn ; i++){
	if(!isprime[i]){
		for(int j = i*i ; j <= maxn ; j+=i){
			isprime[j] = 1;
		}
	}
}

//O(n)
for(int i = 2 ; i <= maxn ; i++){
    if(!isprime[i])	prime.push_back(i);
    for(int j = 0 ; j < prime.size() && prime[j]*i <= maxn; j++){
        isprime[i*prime[j]] = 1;
        if(i % prime[j] == 0)break;
    }
}








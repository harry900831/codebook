//φ(N)=N×(1−1/P_1)×(1−1/P_2)×(1−1/P_3)×...×(1−1/P_k)

long long phi(long long x){
	long long cnt = x;
	for(long long i = 2 ; i*i <= x ; i++){
		if(x % i == 0){
			cnt -= cnt/i;
			while(x % i == 0)x /= i;
		}
	}
	if(x > 1) cnt -= cnt/x;
	return cnt;
}



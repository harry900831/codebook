//0-base
const int maxn = 1000000;
long long a[maxn+5],m[maxn+5];

long long excrt(int n){
	long long a1 = a[0],m1 = m[0],x,y,a2,m2,g,k;
	for(int i = 1 ; i < n ; i++){
		a2 = a[i],m2 = m[i],g = exgcd(m1,m2,x,y);
		if((a2 - a1) % g != 0)return -1;
		k = ( (a2 - a1) / g * x % (m2/g) + (m2/g) ) % (m2/g);
		a1 = (m1 * k + a1)%(m1*m2/g);
		m1 = m1 * m2 /g;
	}
	return a1;
}


